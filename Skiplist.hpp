#ifndef SKIPLIST_HPP
#define SKIPLIST_HPP

#include "./Helpers.hpp"
#include "./LinkedList.hpp"

template <typename T>
class SkipList {
   private:
    class SkipNode {
       private:
        T value;
        SkipNode shortcut[];
        int levels;

       public:
        // Rule of three
        SkipNode(const int _levels) : levels(_levels) {
            shortcut = new SkipNode[_levels];
        };
        SkipNode(const T& _value, const int _levels)
            : value(_value), levels(_levels) {
            shortcut = new SkipNode[_levels];
        };
        SkipNode(const SkipNode& other)
            : value(other.value), levels(other.levels) {
            for (int i = 1; i <= levels; ++i) {
                shortcut[i] = other.shortcut[i];
            }
        };
        ~SkipNode() { delete shortcut; };
    };
    int maxLevel;
    SkipNode* first;
    SkipNode* last;

   public:

    SkipNode& Search(const T& value);
    SkipNode& Insert(const T& value);
};

#endif