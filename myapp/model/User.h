#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    std::string nombre;
    int id;

    User(std::string n, int i) : nombre(n), id(i) {}
    virtual ~User() {} // Destructor virtual para herencia
};

#endif
