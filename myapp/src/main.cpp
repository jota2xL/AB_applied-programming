#include <iostream>
#include "myapp/include/Utils.h"
#include "myapp/include/Patient.h"
#include "myapp/include/Doctor.h"
#include "myapp/include/Appointment.h"

// Declaramos las funciones como estáticas
static void mostrarMenuPrincipal() {
    std::cout << "\n--- Menú Principal ---\n";
    std::cout << "1. Gestion de Pacientes\n";
    std::cout << "2. Gestion de Medicos\n";
    std::cout << "3. Gestion de Citas\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

static void menuPacientes() {
    std::cout << "\n--- Gestión de Pacientes ---\n";
    std::cout << "1. Registrar Paciente\n";
    std::cout << "2. Buscar Paciente\n";
    std::cout << "3. Eliminar Paciente\n";
    std::cout << "4. Volver al Menú Principal\n";
    std::cout << "Seleccione una opción: ";
}

static void menuMedicos() {
    std::cout << "\n--- Gestión de Médicos ---\n";
    std::cout << "1. Registrar Médico\n";
    std::cout << "2. Eliminar Médico\n";
    std::cout << "3. Volver al Menú Principal\n";
    std::cout << "Seleccione una opción: ";
}

static void menuCitas() {
    std::cout << "\n--- Gestión de Citas ---\n";
    std::cout << "1. Registrar Cita\n";
    std::cout << "2. Cancelar Cita\n";
    std::cout << "3. Ordenar Citas por Fecha\n";
    std::cout << "4. Volver al Menú Principal\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    int opcionPrincipal, opcionSubmenu;

    do {
        mostrarMenuPrincipal();
        std::cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1: // Gestión de Pacientes
            do {
                menuPacientes();
                std::cin >> opcionSubmenu;

                switch (opcionSubmenu) {
                case 1:
                    Patient::registrarPaciente(Patient("Joel López", 1, "2024-05-01"));
                    break;
                case 2:
                    Patient::buscarPaciente(1);
                    break;
                case 3:
                    Patient::eliminarPaciente(1);
                    break;
                }
            } while (opcionSubmenu != 4);
            break;

        case 2: // Gestión de Médicos
            do {
                menuMedicos();
                std::cin >> opcionSubmenu;

                switch (opcionSubmenu) {
                case 1:
                    Doctor::registrarDoctor(Doctor("Dra. Gomez", 2, "Cardiología"));
                    break;
                case 2:
                    Doctor::eliminarDoctor(2);
                    break;
                }
            } while (opcionSubmenu != 3);
            break;

        case 3: // Gestión de Citas
            do {
                menuCitas();
                std::cin >> opcionSubmenu;

                switch (opcionSubmenu) {
                case 1:
                    Appointment::registrarCita(Appointment(1, "Consulta", "2024-06-01", "10:00", 1, 2));
                    break;
                case 2:
                    Appointment::cancelarCita(1);
                    break;
                case 3:
                    Appointment::ordenarCitasPorFecha();
                    break;
                }
            } while (opcionSubmenu != 4);
            break;

        case 4:
            std::cout << "Saliendo del sistema...\n";
            break;

        default:
            std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcionPrincipal != 4);

    return 0;
}
