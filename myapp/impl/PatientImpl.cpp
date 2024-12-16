#include "myapp/model/Patient.h"
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<Patient> pacientes;

void registrarPaciente(const Patient& paciente) {
    pacientes.push_back(paciente);
    std::cout << "Paciente registrado: " << paciente.nombre << "\n";
}

void buscarPaciente(int id) {
    for (const auto& p : pacientes) {
        if (p.id == id) {
            std::cout << "Paciente encontrado: " << p.nombre << "\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void eliminarPaciente(int id) {
    pacientes.erase(
        std::remove_if(pacientes.begin(), pacientes.end(),
            [id](const Patient& p) { return p.id == id; }),
        pacientes.end());
    std::cout << "Paciente eliminado.\n";
}
