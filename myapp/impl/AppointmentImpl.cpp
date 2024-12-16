#include "myapp/model/Appointment.h"
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<Appointment> citas;

void registrarCita(const Appointment& cita) {
    citas.push_back(cita);
    std::cout << "Cita registrada: " << cita.descripcion << "\n";
}

void cancelarCita(int id) {
    citas.erase(
        std::remove_if(citas.begin(), citas.end(),
            [id](const Appointment& c) { return c.id == id; }),
        citas.end());
    std::cout << "Cita cancelada.\n";
}

void ordenarCitasPorFecha() {
    std::sort(citas.begin(), citas.end(),
        [](const Appointment& a, const Appointment& b) { return a.fecha < b.fecha; });
    std::cout << "Citas ordenadas por fecha.\n";
}
