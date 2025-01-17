#define _CRT_SECURE_NO_WARNINGS
#include "myapp/include/Doctor.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>

std::vector<Doctor> medicos;

// Validar nombre
bool Doctor::validarNombre(const std::string& nombre) {
    return !nombre.empty();
}

// Validar especialidad
bool Doctor::validarEspecialidad(const std::string& especialidad) {
    return !especialidad.empty();
}

// Registrar doctor
void Doctor::registrarDoctor(const Doctor& doctor) {
    if (!validarNombre(doctor.nombre) || !validarEspecialidad(doctor.especialidad)) {
        std::cout << "Datos inválidos para el doctor.\n";
        return;
    }
    medicos.push_back(doctor);
    std::cout << "Doctor registrado: " << doctor.nombre << "\n";
}

// Eliminar doctor
void Doctor::eliminarDoctor(int id) {
    auto it = std::remove_if(medicos.begin(), medicos.end(),
        [id](const Doctor& d) { return d.id == id; });
    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        std::cout << "Doctor eliminado.\n";
    }
    else {
        std::cout << "Doctor no encontrado.\n";
    }
}

// Guardar doctores
void Doctor::guardarDoctores(const std::string& archivo) {
    FILE* outFile = fopen(archivo.c_str(), "w");
    if (!outFile) {
        std::cout << "Error al abrir el archivo.\n";
        return;
    }
    for (const auto& d : medicos) {
        fprintf(outFile, "%d,%s,%s\n", d.id, d.nombre.c_str(), d.especialidad.c_str());
    }
    fclose(outFile);
    std::cout << "Doctores guardados en " << archivo << "\n";
}

// Cargar doctores
void Doctor::cargarDoctores(const std::string& archivo) {
    FILE* inFile = fopen(archivo.c_str(), "r");
    if (!inFile) {
        std::cout << "Error al abrir el archivo.\n";
        return;
    }
    medicos.clear();
    char nombre[101], especialidad[101];
    int id;
    while (fscanf(inFile, "%d,%100[^,],%100s", &id, nombre, especialidad) == 3) {
        medicos.emplace_back(nombre, id, especialidad);
    }
    fclose(inFile);
    std::cout << "Doctores cargados desde " << archivo << "\n";
}
