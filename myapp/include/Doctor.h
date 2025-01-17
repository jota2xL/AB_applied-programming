#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.h"
#include <string>

class Doctor : public User {
public:
    std::string especialidad;

    Doctor(std::string n, int i, std::string e) : User(n, i), especialidad(e) {}
    static void registrarDoctor(const Doctor& doctor);
    static void eliminarDoctor(int id);
    static void guardarDoctores(const std::string& archivo);
    static void cargarDoctores(const std::string& archivo);

    static bool validarNombre(const std::string& nombre);
    static bool validarEspecialidad(const std::string& especialidad);
};

#endif
