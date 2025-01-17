#define _CRT_SECURE_NO_WARNINGS
#include "myapp/include/Doctor.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio> 

std::vector<Doctor> medicos;


bool Doctor::validarNombre(const std::string& nombre) {
    return !nombre.empty(); 
}


bool Doctor::validarEspecialidad(const std::string& especialidad) {
    return !especialidad.empty(); 
}


void Doctor::registrarDoctor(const Doctor& doctor) {
    if (!validarNombre(doctor.nombre) || !validarEspecialidad(doctor.especialidad)) {
        std::cout << "Datos inv�lidos para el m�dico.\n";
        return;
    }
    medicos.push_back(doctor);
    std::cout << "M�dico registrado: " << doctor.nombre << "\n";
}


void Doctor::eliminarDoctor(int id) {
    auto it = std::remove_if(medicos.begin(), medicos.end(),
        [id](const Doctor& d) { return d.id == id; });
    if (it != medicos.end()) {
        medicos.erase(it, medicos.end());
        std::cout << "M�dico eliminado.\n";
    }
    else {
        std::cout << "M�dico no encontrado.\n";
    }
}

void Doctor::listarDoctores() {
    if (medicos.empty()) {
        std::cout << "No hay m�dicos registrados.\n";
        return;
    }
    for (const auto& d : medicos) {
        std::cout << "ID: " << d.id << ", Nombre: " << d.nombre << ", Especialidad: " << d.especialidad << "\n";
    }
}


void Doctor::guardarDoctores(const std::string& archivo) {
    FILE* outFile = fopen(archivo.c_str(), "w");
    if (!outFile) {
        std::cout << "Error al abrir el archivo para guardar m�dicos.\n";
        return;
    }
    for (const auto& d : medicos) {
        fprintf(outFile, "%d,%s,%s\n", d.id, d.nombre.c_str(), d.especialidad.c_str());
    }
    fclose(outFile);
    std::cout << "M�dicos guardados en " << archivo << "\n";
}


void Doctor::cargarDoctores(const std::string& archivo) {
    FILE* inFile = fopen(archivo.c_str(), "r");
    if (!inFile) {
        std::cout << "Error al abrir el archivo para cargar m�dicos.\n";
        return;
    }
    medicos.clear();
    char nombre[101], especialidad[101];
    int id;
    while (fscanf(inFile, "%d,%100[^,],%100s", &id, nombre, especialidad) == 3) {
        medicos.emplace_back(nombre, id, especialidad);
    }
    fclose(inFile);
    std::cout << "M�dicos cargados desde " << archivo << "\n";
}
