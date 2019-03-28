#ifndef Athlete_H
#define Athlete_H

#include <iostream>

class Athlete {
   private:
    int id;
    int lastPosition;
    int currPosition;
    int points;

   public:
    // Constructors
    Athlete() : id(0), lastPosition(0), currPosition(0), points(0){};
    Athlete(int _id) : id(_id), lastPosition(0), currPosition(0), points(0){};
    Athlete(int _id, int _pos)
        : id(_id), lastPosition(_pos), currPosition(_pos), points(0){};

    // Destructor
    ~Athlete() {}

    // Copy-constructor
    Athlete(const Athlete&);

    // Getters
    int get_id() { return id; };
    int get_lastPosition() { return lastPosition; };
    int get_currPosition() { return currPosition; };
    int get_points() { return points; };

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& os, const Athlete& ath) {
        os << ath.id << " " << ath.points << " " << ath.positionDifference();
        return os;
    }

    // This operators compare the id because it is needed by the SkipList
    bool operator<(const Athlete& other) { return id < other.id; }
    bool operator>(const Athlete& other) { return id > other.id; }
    bool operator<=(const Athlete& other) { return id <= other.id; }
    bool operator>=(const Athlete& other) { return id >= other.id; }
    bool operator==(const Athlete& other) { return id == other.id; }
    bool operator!=(const Athlete& other) { return id != other.id; }

    // Other methods
    void updatePosition(int);        // Updates the athlete position
    void addPoints(int);             // Adds points
    int positionDifference() const;  // Computes the "progress"
};

#endif