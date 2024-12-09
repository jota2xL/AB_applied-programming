// AB_Programming.cpp: define el punto de entrada de la aplicación.
//
#include <iostream>
#include "myapp/util/Utils.h"
#include "myapp/model/Patient.h"
#include "myapp/impl/PatientImpl.cpp"

using namespace std;

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

