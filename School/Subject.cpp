#include "Subject.h"

std::ostream & operator<<(std::ostream &os, const Subject &subject) {
    return os << subject.name;
}
