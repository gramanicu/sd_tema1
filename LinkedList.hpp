#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
   private:
    class Node {
       private:
        T value;
        Node *next;

       public:
        // Constructors
        Node() : next(nullptr){};
        Node(const T &_value) : value(_value), next(nullptr){};

        // This is not an actual copy constructor, because I don't need
        // to assign the other node link to the current one (next pointer)
        Node(const Node &other) : value(other.value), next(nullptr){};

        // Destructor
        ~Node(){};
    };

    Node *first;
    Node *last;

   public:
    // Rule of three - Constructor, Copy-Constructor, Destructor
    LinkedList() : first(nullptr), last(nullptr){};
    LinkedList(const LinkedList &other)
        : first(other.first), last(other.last){};
    ~LinkedList(){};
};

#endif