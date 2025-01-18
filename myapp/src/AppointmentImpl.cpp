#define _CRT_SECURE_NO_WARNINGS
#include "myapp/include/Appointment.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio> 

std::vector<Appointment> citas;

 //YYYY-MM-DD
bool Appointment::validarFecha(const std::string& fecha) {
    if (fecha.size() != 10) return false;
    if (fecha[4] != '-' || fecha[7] != '-') return false;
    for (size_t i = 0; i < fecha.size(); ++i) {
        if ((i != 4 && i != 7) && !isdigit(fecha[i])) return false;
    }
    return true;
}

// hora HH:MM
bool Appointment::validarHora(const std::string& hora) {
    if (hora.size() != 5) return false;
    if (!isdigit(hora[0]) || !isdigit(hora[1]) || hora[2] != ':' || !isdigit(hora[3]) || !isdigit(hora[4])) return false;
    return true;
}

bool Appointment::validarID(int id) {
    return id > 0;
}

void Appointment::registrarCita(const Appointment& cita) {
    if (!validarFecha(cita.fecha) || !validarHora(cita.hora) || !validarID(cita.pacienteId) || !validarID(cita.medicoId)) {
        std::cout << "Datos inválidos para la cita.\n";
        return;
    }
    citas.push_back(cita);
    std::cout << "Cita registrada: " << cita.descripcion << " en " << cita.fecha << " a las " << cita.hora << "\n";
}

void Appointment::eliminarCita(int id) {
    auto it = std::remove_if(citas.begin(), citas.end(),
        [id](const Appointment& c) { return c.id == id; });
    if (it != citas.end()) {
        citas.erase(it, citas.end());
        std::cout << "Cita eliminada.\n";
    }
    else {
        std::cout << "Cita no encontrada.\n";
    }
}

void Appointment::listarCitas() {
    if (citas.empty()) {
        std::cout << "No hay citas registradas.\n";
        return;
    }
    std::cout << "\nLista de citas:\n";
    for (const auto& c : citas) {
        std::cout << "ID: " << c.id << ", Descripción: " << c.descripcion
            << ", Fecha: " << c.fecha << ", Hora: " << c.hora
            << ", Paciente ID: " << c.pacienteId
            << ", Médico ID: " << c.medicoId << "\n";
    }
}

// Guardar citas
void Appointment::guardarCitas(const std::string& archivo) {
    FILE* outFile = fopen(archivo.c_str(), "w");
    if (!outFile) {
        std::cout << "Error al abrir el archivo para guardar citas.\n";
        return;
    }
    for (const auto& c : citas) {
        fprintf(outFile, "%d,%s,%s,%s,%d,%d\n",
            c.id,
            c.descripcion.c_str(),
            c.fecha.c_str(),
            c.hora.c_str(),
            c.pacienteId,
            c.medicoId);
    }
    fclose(outFile);
    std::cout << "Citas guardadas en " << archivo << "\n";
}

// Cargar citas
void Appointment::cargarCitas(const std::string& archivo) {
    FILE* inFile = fopen(archivo.c_str(), "r");
    if (!inFile) {
        std::cout << "Error al abrir el archivo para cargar citas.\n";
        return;
    }
    citas.clear();
    char descripcion[101], fecha[21], hora[11];
    int id, pacienteId, medicoId;
    while (fscanf(inFile, "%d,%100[^,],%20[^,],%10[^,],%d,%d",
        &id, descripcion, fecha, hora, &pacienteId, &medicoId) == 6) {
        citas.emplace_back(id, descripcion, fecha, hora, pacienteId, medicoId);
    }
    fclose(inFile);
    std::cout << "Citas cargadas desde " << archivo << "\n";
}
