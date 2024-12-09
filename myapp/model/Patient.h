#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"

class Patient : public User {
public:
    std::string fechaIngreso;

    Patient(std::string n, int i, std::string f) : User(n, i), fechaIngreso(f) {}
};

#endif
