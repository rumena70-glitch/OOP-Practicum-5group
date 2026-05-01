#include <iostream>
using namespace std;

class Time {
    int hours;
    int minutes;
    int seconds;
    public:
    int toSec() const {
        return this -> hours * 3600 + this -> minutes * 60 + this -> seconds;
    }
    Time toTime(int seconds) const {
        int hours = seconds / 3600;
        seconds %= 3600;
        int minutes = seconds / 60;
        seconds %= 60;
        return Time(hours, minutes, seconds);
    }
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(const int h, const int m, const int s) : hours(h), minutes(m), seconds(s) {}
    Time tillMidnight() const{
        constexpr int midnight_in_seconds = 24 * 60 * 60;
        return toTime(midnight_in_seconds - this -> toSec());
    }
    void increment() {
        this -> seconds++;
        if (this -> seconds >= 60) {
            this -> seconds = 0;
            this -> minutes++;
        }
        if (this -> minutes >= 60) {
            this -> minutes = 0;
            this -> hours++;
        }
        if (this -> hours >= 24) {
            this -> hours = 0;
        }
    }
    bool isBefore(const Time& otherTime) const {
        if (this -> hours != otherTime.hours) {
            return this -> hours < otherTime.hours;
        }
        if (this -> minutes != otherTime.minutes) {
            return this -> minutes < otherTime.minutes;
        }
        if (this -> seconds != otherTime.seconds) {
            return this -> seconds < otherTime.seconds;
        }
        return true;
    }
    bool isAfter(const Time& otherTime) const {
        if (this -> hours != otherTime.hours) {
            return this -> hours > otherTime.hours;
        }
        if (this -> minutes != otherTime.minutes) {
            return this -> minutes > otherTime.minutes;
        }
        if (this -> seconds != otherTime.seconds) {
            return this -> seconds > otherTime.seconds;
        }
        return true;
    }
    bool isEqual(const Time& otherTime) const {
        return this -> hours == otherTime.hours && this -> minutes == otherTime.minutes && this -> seconds == otherTime.seconds;
    }
    bool isTimeForDinner() const {
        return ((this -> isAfter(Time(20, 30, 0))) || (this -> isEqual(Time(20, 30, 0)))) && ((this -> isBefore(Time(22, 0, 0))) || (this -> isEqual(Time(22, 0, 0))));
    }
    bool isTimeToParty() const {
        return !(this -> isBefore(Time(23, 0, 0)) && this -> isAfter(Time(6, 0, 0)));
    }
    Time subtract(const Time& otherTime) const {
        return toTime(abs(this -> toSec() - otherTime.toSec()));
    }
    int compare(const Time& otherTime) const {
        if (this -> isBefore(otherTime)) {
            return -1;
        }
        if (this -> isAfter(otherTime)) {
            return 1;
        }
        return 0;
    }
    void print() const {
        println("{:02}:{:02}:{:02}", this -> hours, this -> minutes, this -> seconds);
    }
};
void selectionSort(Time* arr, const int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].isBefore(arr[minIndex])) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}
int main() {
    constexpr int n = 10;
    Time times[n]{
        Time(23, 0, 0), Time(22, 0, 0), Time(21, 0, 0), Time(20, 0, 0), Time(19, 0, 0), Time(18, 0, 0), Time(17, 0, 0),
        Time(16, 0, 0), Time(15, 0, 0), Time(14, 0, 0)
    };
    for (Time time : times) {
        time.print();
    }
    println();
    selectionSort(times, 10);
    for (Time time : times) {
        time.print();
    }
}
