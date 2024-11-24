#include <iostream>
#include "model/Patient.h"
#include "impl/PatientImpl.cpp"
#include "util/Utils.h"

int main() {
    std::cout << "Bienvenido al sistema de gestión hospitalaria.\n";

    Patient paciente("Joel López", 1, "2024-11-01");
    registrarPaciente(paciente);

    if (validarFecha(paciente.fechaIngreso)) {
        std::cout << "Fecha de ingreso válida.\n";
    }
    else {
        std::cout << "Fecha de ingreso inválida.\n";
    }

    return 0;
}
