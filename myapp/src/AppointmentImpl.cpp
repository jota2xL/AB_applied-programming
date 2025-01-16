#include "myapp/include/Appointment.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>

std::vector<Appointment> citas;

// Funci�n para validar la fecha (formato YYYY-MM-DD)
bool Appointment::validarFecha(const std::string& fecha) {
    std::regex fechaRegex("^\\d{4}-\\d{2}-\\d{2}$");
    return std::regex_match(fecha, fechaRegex);
}

// Funci�n para validar la hora (formato HH:MM)
bool Appointment::validarHora(const std::string& hora) {
    std::regex horaRegex("^\\d{2}:\\d{2}$");
    return std::regex_match(hora, horaRegex);
}

// Funci�n para validar los IDs (debe ser un n�mero entero positivo)
bool Appointment::validarID(int id) {
    return id > 0;
}

void Appointment::registrarCita(const Appointment& cita) {
    // Validaciones
    if (!validarFecha(cita.fecha)) {
        std::cout << "Error: Fecha inv�lida. Formato esperado: YYYY-MM-DD.\n";
        return;
    }
    if (!validarHora(cita.hora)) {
        std::cout << "Error: Hora inv�lida. Formato esperado: HH:MM.\n";
        return;
    }
    if (!validarID(cita.pacienteId) || !validarID(cita.medicoId)) {
        std::cout << "Error: ID inv�lido. Debe ser un n�mero positivo.\n";
        return;
    }

    citas.push_back(cita);
    std::cout << "Cita registrada: " << cita.descripcion << "\n";
}

void Appointment::cancelarCita(int id) {
    citas.erase(
        std::remove_if(citas.begin(), citas.end(),
            [id](const Appointment& c) { return c.id == id; }),
        citas.end());
    std::cout << "Cita cancelada.\n";
}

void Appointment::ordenarCitasPorFecha() {
    std::sort(citas.begin(), citas.end(),
        [](const Appointment& a, const Appointment& b) { return a.fecha < b.fecha; });
    std::cout << "Citas ordenadas por fecha.\n";
}
