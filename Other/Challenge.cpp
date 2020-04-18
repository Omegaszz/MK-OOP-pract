#include "Challenge.h"

Challenge::Challenge(const char* _name, const char* _status, int _timesUsed) : rating(nullptr), timesUsed(_timesUsed) {
    strcpy(name, _name);
    strcpy(status, _status);
    size = 2;
    curr = 1;
    rating = new float[size];
    rating[0] = 0;
}

Challenge::Challenge(Challenge const &temp) : timesUsed(temp.timesUsed), size(temp.size), curr(temp.curr) {
    strcpy(name, temp.name);
    strcpy(status, temp.status);
    rating = new float[size];

    for (int i = 0; i < curr; ++i) {
        rating[i] = temp.rating[i];
    }
}

Challenge::~Challenge() {
    delete [] rating;
}

char* Challenge::getName() {
    return name;
}

int Challenge::getTimesUsed() {
    return timesUsed;
}

void Challenge::setRating(float _rating) {
    if(curr == size) {
        float *arr = new float[size + 1];
        for (int i = 0; i < curr; ++i) {
            arr[i] = rating[0];
        }
        delete [] rating;
        size++;
        rating = arr;
    }
    rating[curr++] = _rating;
    float average = 0;
    for (int i = 1; i < curr; ++i) {
        average += rating[i];
    }
    average /= float(curr - 1);
    rating[0] = average;
}

void Challenge::oneUpTimesUsed() {
    timesUsed++;

    if(timesUsed < 10 && timesUsed > 2)
        strcpy(status, "quite recently");

    else if (timesUsed > 11)
        strcpy(status, "old");

}

Challenge& Challenge::operator=(Challenge const &temp) {
    if(this != &temp) {
        delete [] rating;

        strcpy(name, temp.name);
        strcpy(status, temp.status);

        size = temp.size;
        curr = temp.curr;
        timesUsed = temp.timesUsed;

        rating = new float[size];
        for (int i = 0; i < curr; ++i) {
            rating[i] = temp.rating[i];
        }
    }
    return *this;
}

bool Challenge::operator>(const Challenge &temp) {
    return timesUsed > temp.timesUsed;
}

bool Challenge::operator<(const Challenge &temp) {
    return timesUsed < temp.timesUsed;
}

void Challenge::print() {
    std::cout << name << ' ' << rating[0] << ' ' << timesUsed << std::endl;
}