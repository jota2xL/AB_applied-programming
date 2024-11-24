#include "model/Patient.h"
#include <iostream>

void registrarPaciente(Patient& paciente) {
    std::cout << "Paciente registrado: " << paciente.nombre
        << " (ID: " << paciente.id << ", Fecha de ingreso: "
        << paciente.fechaIngreso << ")\n";
}
