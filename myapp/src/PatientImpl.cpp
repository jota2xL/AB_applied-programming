#define _CRT_SECURE_NO_WARNINGS
#include "myapp/include/Patient.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio> // Para fopen, fclose, fprintf, fscanf

std::vector<Patient> pacientes;

// Validar nombre
bool Patient::validarNombre(const std::string& nombre) {
    return !nombre.empty(); // Ejemplo básico de validación
}

// Validar ID
bool Patient::validarID(int id) {
    return id > 0;
}

// Validar fecha (formato YYYY-MM-DD)
bool Patient::validarFecha(const std::string& fecha) {
    return fecha.size() == 10 && fecha[4] == '-' && fecha[7] == '-';
}

// Registrar paciente
void Patient::registrarPaciente(const Patient& paciente) {
    if (!validarNombre(paciente.nombre) || !validarID(paciente.id) || !validarFecha(paciente.fechaIngreso)) {
        std::cout << "Datos inválidos para el paciente.\n";
        return;
    }
    pacientes.push_back(paciente);
    std::cout << "Paciente registrado: " << paciente.nombre << "\n";
}

// Buscar paciente
void Patient::buscarPaciente(int id) {
    for (const auto& p : pacientes) {
        if (p.id == id) {
            std::cout << "Paciente encontrado: " << p.nombre << "\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

// Eliminar paciente
void Patient::eliminarPaciente(int id) {
    auto it = std::remove_if(pacientes.begin(), pacientes.end(),
        [id](const Patient& p) { return p.id == id; });
    if (it != pacientes.end()) {
        pacientes.erase(it, pacientes.end());
        std::cout << "Paciente eliminado.\n";
    }
    else {
        std::cout << "Paciente no encontrado.\n";
    }
}

// Guardar pacientes
void Patient::guardarPacientes(const std::string& archivo) {
    FILE* outFile = fopen(archivo.c_str(), "w");
    if (!outFile) {
        std::cout << "Error al abrir el archivo.\n";
        return;
    }
    for (const auto& p : pacientes) {
        fprintf(outFile, "%d,%s,%s\n", p.id, p.nombre.c_str(), p.fechaIngreso.c_str());
    }
    fclose(outFile);
    std::cout << "Pacientes guardados en " << archivo << "\n";
}

// Cargar pacientes
void Patient::cargarPacientes(const std::string& archivo) {
    FILE* inFile = fopen(archivo.c_str(), "r");
    if (!inFile) {
        std::cout << "Error al abrir el archivo.\n";
        return;
    }
    pacientes.clear();
    char nombre[101], fechaIngreso[21];
    int id;
    while (fscanf(inFile, "%d,%100[^,],%20s", &id, nombre, fechaIngreso) == 3) {
        pacientes.emplace_back(nombre, id, fechaIngreso);
    }
    fclose(inFile);
    std::cout << "Pacientes cargados desde " << archivo << "\n";
}
