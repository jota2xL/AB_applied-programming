#include <iostream>
#include "myapp/include/Utils.h"
#include "myapp/include/Patient.h"
#include "myapp/include/Doctor.h"
#include "myapp/include/Appointment.h"

// Declaramos las funciones como estáticas
static void mostrarMenuPrincipal() {
    std::cout << "\n--- Menu Principal ---\n";
    std::cout << "1. Gestion de Pacientes\n";
    std::cout << "2. Gestion de Medicos\n";
    std::cout << "3. Gestion de Citas\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

static void menuPacientes() {
    int opcionSubmenu;
    do {
        std::cout << "\n--- Gestión de Pacientes ---\n";
        std::cout << "1. Registrar Paciente\n";
        std::cout << "2. Buscar Paciente\n";
        std::cout << "3. Eliminar Paciente\n";
        std::cout << "4. Listar Pacientes\n"; 
        std::cout << "5. Modificar Paciente\n"; 
        std::cout << "6. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcionSubmenu;

        switch (opcionSubmenu) {
        case 1: { // Registrar
            std::string nombre, fechaIngreso;
            int id;

            std::cout << "Ingrese el nombre del paciente: ";
            std::cin.ignore(); // Limpiar buffer
            std::getline(std::cin, nombre);

            std::cout << "Ingrese el ID del paciente: ";
            std::cin >> id;

            std::cout << "Ingrese la fecha de ingreso (YYYY-MM-DD): ";
            std::cin >> fechaIngreso;

            Patient::registrarPaciente(Patient(nombre, id, fechaIngreso));
            Patient::guardarPacientes("pacientes.txt");
            break;
        }
        case 2: { 
            int id;
            std::cout << "Ingrese el ID del paciente a buscar: ";
            std::cin >> id;
            Patient::buscarPaciente(id);
            break;
        }
        case 3: { 
            Patient::listarPacientes();
            int id;
            std::cout << "Ingrese el ID del paciente a eliminar: ";
            std::cin >> id;
            Patient::eliminarPaciente(id);
            Patient::guardarPacientes("pacientes.txt");
            break;
        }
        case 4: { 
            Patient::listarPacientes();
            break;
        }
        case 5: { 
            Patient::listarPacientes();
            int id;
            std::cout << "Ingrese el ID del paciente a modificar: ";
            std::cin >> id;
            Patient::modificarPaciente(id);
            Patient::guardarPacientes("pacientes.txt");
            break;
        }
        case 6:
            std::cout << "Volviendo al Menú Principal...\n";
            break;

        default:
            std::cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcionSubmenu != 6);
}

static void menuMedicos() {
    std::cout << "\n--- Gestion de Medicos ---\n";
    std::cout << "1. Registrar Medico\n";
    std::cout << "2. Eliminar Medico\n";
    std::cout << "3. Volver al Menú Principal\n";
    std::cout << "Seleccione una opción: ";
}

static void menuCitas() {
    std::cout << "\n--- Gestión de Citas ---\n";
    std::cout << "1. Registrar Cita\n";
    std::cout << "2. Cancelar Cita\n";
    std::cout << "3. Ordenar Citas por Fecha\n";
    std::cout << "4. Volver al Menú Principal\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    int opcionPrincipal;

    do {
        mostrarMenuPrincipal();
        std::cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1:
            menuPacientes();
            break;

        case 2:
            menuMedicos();
            break;

        case 3:
            menuCitas();
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
