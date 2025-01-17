#define _CRT_SECURE_NO_WARNINGS
#include "myapp/include/Appointment.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio> // Para fopen, fclose, fprintf, fscanf

std::vector<Appointment> citas;

// Cancelar una cita
void Appointment::cancelarCita(int id) {
    auto it = std::remove_if(citas.begin(), citas.end(),
        [id](const Appointment& cita) { return cita.id == id; });
    if (it != citas.end()) {
        citas.erase(it, citas.end());
        std::cout << "Cita cancelada.\n";
    }
    else {
        std::cout << "Cita no encontrada.\n";
    }
}

// Ordenar citas por fecha
void Appointment::ordenarCitasPorFecha() {
    std::sort(citas.begin(), citas.end(),
        [](const Appointment& a, const Appointment& b) { return a.fecha < b.fecha; });
    std::cout << "Citas ordenadas por fecha.\n";
}

// Registrar una cita
void Appointment::registrarCita(const Appointment& cita) {
    if (!validarFecha(cita.fecha) || !validarHora(cita.hora) || !validarID(cita.pacienteId) || !validarID(cita.medicoId)) {
        std::cout << "Datos inválidos para la cita.\n";
        return;
    }
    citas.push_back(cita);
    std::cout << "Cita registrada: " << cita.descripcion << "\n";
}

// Validar fecha
bool Appointment::validarFecha(const std::string& fecha) {
    return fecha.size() == 10 && fecha[4] == '-' && fecha[7] == '-';
}

// Validar hora
bool Appointment::validarHora(const std::string& hora) {
    return hora.size() == 5 && hora[2] == ':';
}

// Validar ID
bool Appointment::validarID(int id) {
    return id > 0;
}
