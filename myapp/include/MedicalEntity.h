#ifndef MEDICALENTITY_H
#define MEDICALENTITY_H

#include <string>

class MedicalEntity {
public:
    int id;
    std::string descripcion;

    MedicalEntity(int i, std::string d) : id(i), descripcion(d) {}
    virtual ~MedicalEntity() {}
};

#endif
