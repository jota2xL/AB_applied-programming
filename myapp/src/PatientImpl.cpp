#include "myapp/include/Patient.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>

std::vector<Patient> pacientes;

// validar el nombre (solo letras y espacios)
bool Patient::validarNombre(const std::string& nombre) {
    std::regex nombreRegex("^[A-Za-z ]+$");
    return std::regex_match(nombre, nombreRegex);
}

// validar el ID (debe ser un número entero positivo)
bool Patient::validarID(int id) {
    return id > 0;
}

// validar la fecha (formato YYYY-MM-DD)
bool Patient::validarFecha(const std::string& fecha) {
    std::regex fechaRegex("^\\d{4}-\\d{2}-\\d{2}$");
    return std::regex_match(fecha, fechaRegex);
}

// registrar un paciente
void Patient::registrarPaciente(const Patient& paciente) {
    if (!validarNombre(paciente.nombre)) {
        std::cout << "Error: Nombre inválido.\n";
        return;
    }
    if (!validarID(paciente.id)) {
        std::cout << "Error: ID inválido. Debe ser un número positivo.\n";
        return;
    }
    if (!validarFecha(paciente.fechaIngreso)) {
        std::cout << "Error: Fecha de ingreso inválida. Formato esperado: YYYY-MM-DD.\n";
        return;
    }

    pacientes.push_back(paciente);
    std::cout << "Paciente registrado: " << paciente.nombre << "\n";
}

// buscar un paciente por ID
void Patient::buscarPaciente(int id) {
    for (const auto& p : pacientes) {
        if (p.id == id) {
            std::cout << "Paciente encontrado: " << p.nombre << "\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

// eliminar un paciente por ID
void Patient::eliminarPaciente(int id) {
    pacientes.erase(
        std::remove_if(pacientes.begin(), pacientes.end(),
            [id](const Patient& p) { return p.id == id; }),
        pacientes.end());
    std::cout << "Paciente eliminado.\n";
}
