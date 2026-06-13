#ifndef SCHOOL_SUBJECT_H
#define SCHOOL_SUBJECT_H
#include <string>


class Subject {
    std::string name;
public:
    friend std::ostream& operator<<(std::ostream &os, const Subject &subject);
};


#endif //SCHOOL_SUBJECT_H
