#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.h"

class Doctor : public User {
public:
    std::string especialidad;

    Doctor(std::string n, int i, std::string e) : User(n, i), especialidad(e) {}
};

#endif
