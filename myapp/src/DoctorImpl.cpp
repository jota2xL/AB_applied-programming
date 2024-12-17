#include "myapp/include/Doctor.h"
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<Doctor> medicos;

void Doctor::registrarDoctor(const Doctor& doctor) {
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
