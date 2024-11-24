#include "model/Doctor.h"
#include <iostream>

void registrarDoctor(Doctor& doctor) {
    std::cout << "Doctor registrado: " << doctor.nombre
        << " (Especialidad: " << doctor.especialidad << ")\n";
}
