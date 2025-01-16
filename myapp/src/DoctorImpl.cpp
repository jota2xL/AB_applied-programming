#include "myapp/include/Doctor.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>

std::vector<Doctor> medicos;

// Función para validar el nombre del doctor (solo letras y espacios)
bool Doctor::validarNombre(const std::string& nombre) {
    std::regex nombreRegex("^[A-Za-z ]+$");
    return std::regex_match(nombre, nombreRegex);
}

// Función para validar la especialidad del doctor (no debe estar vacía)
bool Doctor::validarEspecialidad(const std::string& especialidad) {
    return !especialidad.empty();
}

void Doctor::registrarDoctor(const Doctor& doctor) {
    // Validaciones
    if (!validarNombre(doctor.nombre)) {
        std::cout << "Error: Nombre inválido.\n";
        return;
    }
    if (!validarEspecialidad(doctor.especialidad)) {
        std::cout << "Error: Especialidad inválida.\n";
        return;
    }

    medicos.push_back(doctor);
    std::cout << "Doctor registrado: " << doctor.nombre << "\n";
}

void Doctor::eliminarDoctor(int id) {
    medicos.erase(
        std::remove_if(medicos.begin(), medicos.end(),
            [id](const Doctor& d) { return d.id == id; }),
        medicos.end());
    std::cout << "Doctor eliminado.\n";
}
