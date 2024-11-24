#include <iostream>
#include "model/Patient.h"
#include "impl/PatientImpl.cpp"
#include "util/Utils.h"

int main() {
    std::cout << "Bienvenido al sistema de gesti�n hospitalaria.\n";

    Patient paciente("Joel L�pez", 1, "2024-11-01");
    registrarPaciente(paciente);

    if (validarFecha(paciente.fechaIngreso)) {
        std::cout << "Fecha de ingreso v�lida.\n";
    }
    else {
        std::cout << "Fecha de ingreso inv�lida.\n";
    }

    return 0;
}
