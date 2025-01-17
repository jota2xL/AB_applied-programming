#include <iostream>
#include "myapp/include/Patient.h"
#include "myapp/include/Doctor.h"
#include "myapp/include/Appointment.h"

int main() {
    
    Patient::cargarPacientes("pacientes.txt");
    Doctor::cargarDoctores("medicos.txt");

    int opcionPrincipal, opcionSubmenu;
    do {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Gestion de Pacientes\n";
        std::cout << "2. Gestion de Medicos\n";
        std::cout << "3. Gestion de Citas\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionPrincipal;

        switch (opcionPrincipal) {
        case 1: 
            break;

        case 2: 
            do {
                std::cout << "\n--- Gestion de Medicos ---\n";
                std::cout << "1. Registrar Médico\n";
                std::cout << "2. Eliminar Médico\n";
                std::cout << "3. Listar Médicos\n";
                std::cout << "4. Volver al Menú Principal\n";
                std::cout << "Seleccione una opción: ";
                std::cin >> opcionSubmenu;

                switch (opcionSubmenu) {
                case 1: { // Registrar Médico
                    std::string nombre, especialidad;
                    int id;

                    std::cout << "Ingrese el nombre del médico: ";
                    std::cin.ignore();
                    std::getline(std::cin, nombre);

                    std::cout << "Ingrese el ID del médico: ";
                    std::cin >> id;

                    std::cout << "Ingrese la especialidad del médico: ";
                    std::cin.ignore();
                    std::getline(std::cin, especialidad);

                    Doctor::registrarDoctor(Doctor(nombre, id, especialidad));
                    break;
                }
                case 2: { 
                    int id;
                    std::cout << "Ingrese el ID del médico a eliminar: ";
                    std::cin >> id;
                    Doctor::eliminarDoctor(id);
                    break;
                }
                case 3: 
                    Doctor::listarDoctores();
                    break;
                }
            } while (opcionSubmenu != 4);
            break;

        case 3:
            // para la gestion de citas que voy a hacer ahora
            break;

        case 4:
            std::cout << "Saliendo del sistema...\n";
            break;

        default:
            std::cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcionPrincipal != 4);

    // Guardar pacientes y médicos salir
    Patient::guardarPacientes("pacientes.txt");
    Doctor::guardarDoctores("medicos.txt");

    return 0;
}
