#define _CRT_SECURE_NO_WARNINGS
#include "myapp/include/Patient.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio> // Para fopen, fclose, fprintf, fscanf
#include <filesystem> //  ruta 

std::vector<Patient> pacientes;


bool Patient::validarNombre(const std::string& nombre) {
    return !nombre.empty(); 
}

// Validar ID
bool Patient::validarID(int id) {
    return id > 0;
}

// YYYY-MM-DD
bool Patient::validarFecha(const std::string& fecha) {
    if (fecha.size() != 10) return false; // 10 caracteres
    if (fecha[4] != '-' || fecha[7] != '-') return false; // Verificar separadores

   
    for (size_t i = 0; i < fecha.size(); ++i) {
        if (i != 4 && i != 7 && !isdigit(fecha[i])) return false;
    }

    return true;
}


void Patient::registrarPaciente(const Patient& paciente) {
    if (!validarNombre(paciente.nombre) || !validarID(paciente.id) || !validarFecha(paciente.fechaIngreso)) {
        std::cout << "Datos inválidos para el paciente.\n";
        return;
    }
    pacientes.push_back(paciente);
    std::cout << "Paciente registrado: " << paciente.nombre << "\n";
}


void Patient::buscarPaciente(int id) {
    for (const auto& p : pacientes) {
        if (p.id == id) {
            std::cout << "Paciente encontrado: " << p.nombre << "\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}


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


void Patient::listarPacientes() {
    if (pacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
        return;
    }

    std::cout << "\nLista de pacientes:\n";
    for (const auto& p : pacientes) {
        std::cout << "ID: " << p.id << ", Nombre: " << p.nombre
            << ", Fecha de ingreso: " << p.fechaIngreso << "\n";
    }
}


void Patient::modificarPaciente(int id) {
    for (auto& p : pacientes) {
        if (p.id == id) {
            std::cout << "Modificando datos del paciente: " << p.nombre << "\n";

            std::cout << "Ingrese el nuevo nombre (o presione Enter para mantener el actual): ";
            std::string nuevoNombre;
            std::cin.ignore(); 
            std::getline(std::cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                p.nombre = nuevoNombre;
            }

            std::cout << "Ingrese la nueva fecha de ingreso (YYYY-MM-DD, o Enter para mantener el actual): ";
            std::string nuevaFecha;
            std::getline(std::cin, nuevaFecha);
            if (!nuevaFecha.empty()) {
                if (validarFecha(nuevaFecha)) {
                    p.fechaIngreso = nuevaFecha;
                }
                else {
                    std::cout << "Fecha inválida. Se mantuvo la anterior.\n";
                }
            }

            std::cout << "Datos del paciente actualizados.\n";
            return;
        }
    }
    std::cout << "Paciente con ID " << id << " no encontrado.\n";
}


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

    // Imprimir la ruta completa del archivo guardado
    std::cout << "Pacientes guardados en: " << std::filesystem::absolute(archivo) << "\n";
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
