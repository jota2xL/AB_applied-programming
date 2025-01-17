#ifndef PATIENT_H
#define PATIENT_H

#include "User.h"
#include <string>

class Patient : public User {
public:
    std::string fechaIngreso;

    Patient(std::string n, int i, std::string f) : User(n, i), fechaIngreso(f) {}

    static void registrarPaciente(const Patient& paciente);
    static void buscarPaciente(int id);
    static void eliminarPaciente(int id);
    static void guardarPacientes(const std::string& archivo);
    static void cargarPacientes(const std::string& archivo);
    static void listarPacientes();
    static void modificarPaciente(int id);

    static bool validarNombre(const std::string& nombre);
    static bool validarID(int id);
    static bool validarFecha(const std::string& fecha);
};

#endif
