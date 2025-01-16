#include "myapp/include/Appointment.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <regex>

std::vector<Appointment> citas;

// Función para validar la fecha (formato YYYY-MM-DD)
bool Appointment::validarFecha(const std::string& fecha) {
    std::regex fechaRegex("^\\d{4}-\\d{2}-\\d{2}$");
    return std::regex_match(fecha, fechaRegex);
}

// Función para validar la hora (formato HH:MM)
bool Appointment::validarHora(const std::string& hora) {
    std::regex horaRegex("^\\d{2}:\\d{2}$");
    return std::regex_match(hora, horaRegex);
}

// Función para validar los IDs (debe ser un número entero positivo)
bool Appointment::validarID(int id) {
    return id > 0;
}

// Registrar una cita
void Appointment::registrarCita(const Appointment& cita) {
    // Validaciones
    if (!validarFecha(cita.fecha)) {
        std::cout << "Error: Fecha inválida. Formato esperado: YYYY-MM-DD.\n";
        return;
    }
    if (!validarHora(cita.hora)) {
        std::cout << "Error: Hora inválida. Formato esperado: HH:MM.\n";
        return;
    }
    if (!validarID(cita.pacienteId) || !validarID(cita.medicoId)) {
        std::cout << "Error: ID inválido. Debe ser un número positivo.\n";
        return;
    }

    citas.push_back(cita);
    std::cout << "Cita registrada: " << cita.descripcion << "\n";
}

// Modificar una cita existente
void Appointment::modificarCita(int id, const std::string& nuevaFecha, const std::string& nuevaHora, int nuevoMedicoId) {
    for (auto& cita : citas) {
        if (cita.id == id) {
            // Validaciones antes de modificar
            if (!validarFecha(nuevaFecha)) {
                std::cout << "Error: Fecha inválida. Formato esperado: YYYY-MM-DD.\n";
                return;
            }
            if (!validarHora(nuevaHora)) {
                std::cout << "Error: Hora inválida. Formato esperado: HH:MM.\n";
                return;
            }
            if (!validarID(nuevoMedicoId)) {
                std::cout << "Error: ID del médico inválido. Debe ser un número positivo.\n";
                return;
            }

            // Aplicar modificaciones
            cita.fecha = nuevaFecha;
            cita.hora = nuevaHora;
            cita.medicoId = nuevoMedicoId;

            std::cout << "Cita modificada: " << cita.descripcion << "\n";
            return;
        }
    }
    std::cout << "Error: Cita no encontrada con el ID proporcionado.\n";
}

// Cancelar una cita
void Appointment::cancelarCita(int id) {
    citas.erase(
        std::remove_if(citas.begin(), citas.end(),
            [id](const Appointment& c) { return c.id == id; }),
        citas.end());
    std::cout << "Cita cancelada.\n";
}

// Ordenar citas por fecha
void Appointment::ordenarCitasPorFecha() {
    std::sort(citas.begin(), citas.end(),
        [](const Appointment& a, const Appointment& b) { return a.fecha < b.fecha; });
    std::cout << "Citas ordenadas por fecha.\n";
}
