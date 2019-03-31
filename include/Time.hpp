#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>

class Times {
   public:
    int index;
    int time;
    Times(){};
    Times(const int index, const int time) : index(index), time(time){};
    ~Times(){};
    Times(const Times &other) : index(other.index), time(other.time){};

    bool operator<(const Times &other) { return time < other.time; }
    bool operator>(const Times &other) { return time > other.time; }
    bool operator==(const Times &other) { return time == other.time; }

    friend std::ostream &operator<<(std::ostream &output, const Times &result) {
        output << "index: " << result.index << " time: " << result.time;
        return output;
    }
};

#endif