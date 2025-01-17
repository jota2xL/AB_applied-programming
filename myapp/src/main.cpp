#include <iostream>
#include "myapp/include/Patient.h"
#include "myapp/include/Doctor.h"
#include "myapp/include/Appointment.h"

static void mostrarMenuPrincipal() {
    std::cout << "\n--- Menu Principal ---\n";
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
    std::cout << "4. Listar Pacientes\n";
    std::cout << "5. Modificar Paciente\n";
    std::cout << "6. Volver al Menú Principal\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    // Cargar al iniciar
    Patient::cargarPacientes("pacientes.txt");

    int opcionPrincipal, opcionSubmenu;
    do {
        mostrarMenuPrincipal();
        std::cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1: 
            do {
                menuPacientes();
                std::cin >> opcionSubmenu;

                switch (opcionSubmenu) {
                case 1: { 
                    std::string nombre, fechaIngreso;
                    int id;

                    std::cout << "Ingrese el nombre del paciente: ";
                    std::cin.ignore(); 
                    std::getline(std::cin, nombre);

                    std::cout << "Ingrese el ID del paciente: ";
                    std::cin >> id;

                    std::cout << "Ingrese la fecha de ingreso (YYYY-MM-DD): ";
                    std::cin >> fechaIngreso;

                    Patient::registrarPaciente(Patient(nombre, id, fechaIngreso));
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
                    int id;
                    std::cout << "Ingrese el ID del paciente a eliminar: ";
                    std::cin >> id;
                    Patient::eliminarPaciente(id);
                    break;
                }
                case 4: 
                    Patient::listarPacientes();
                    break;

                case 5: { 
                    int id;
                    std::cout << "Ingrese el ID del paciente a modificar: ";
                    std::cin >> id;
                    Patient::modificarPaciente(id);
                    break;
                }
                }
            } while (opcionSubmenu != 6);
            break;

        case 2:
            
            break;

        case 3:
            
            break;

        case 4:
            std::cout << "Saliendo del sistema...\n";
            break;

        default:
            std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcionPrincipal != 4);

    // Guardar los pacientes antes de salir
    Patient::guardarPacientes("pacientes.txt");

    return 0;
}
