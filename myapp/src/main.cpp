#include <iostream>
#include "myapp/include/Patient.h"
#include "myapp/include/Doctor.h"
#include "myapp/include/Appointment.h"

int main() {
    // Cargar datos al iniciar
    Patient::cargarPacientes("pacientes.txt");
    Doctor::cargarDoctores("medicos.txt");
    Appointment::cargarCitas("citas.txt");

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
        case 1: // Gestión de Pacientes
            do {
                std::cout << "\n--- Gestion de Pacientes ---\n";
                std::cout << "1. Registrar Paciente\n";
                std::cout << "2. Buscar Paciente\n";
                std::cout << "3. Eliminar Paciente\n";
                std::cout << "4. Listar Pacientes\n";
                std::cout << "5. Modificar Paciente\n";
                std::cout << "6. Volver al Menú Principal\n";
                std::cout << "Seleccione una opción: ";
                std::cin >> opcionSubmenu;

                switch (opcionSubmenu) {
                case 1: { // Registrar Paciente
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
                case 2: { // Buscar Paciente
                    int id;
                    std::cout << "Ingrese el ID del paciente a buscar: ";
                    std::cin >> id;
                    Patient::buscarPaciente(id);
                    break;
                }
                case 3: { // Eliminar Paciente
                    int id;
                    std::cout << "Ingrese el ID del paciente a eliminar: ";
                    std::cin >> id;
                    Patient::eliminarPaciente(id);
                    break;
                }
                case 4: // Listar Pacientes
                    Patient::listarPacientes();
                    break;

                case 5: { // Modificar Paciente (implementación opcional)
                    int id;
                    std::cout << "Ingrese el ID del paciente a modificar: ";
                    std::cin >> id;
                    Patient::modificarPaciente(id); // Implementa esta función si lo necesitas
                    break;
                }
                }
            } while (opcionSubmenu != 6);
            break;

        case 2: // Gestión de Médicos
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
                case 2: { // Eliminar Médico
                    int id;
                    std::cout << "Ingrese el ID del médico a eliminar: ";
                    std::cin >> id;
                    Doctor::eliminarDoctor(id);
                    break;
                }
                case 3: // Listar Médicos
                    Doctor::listarDoctores();
                    break;
                }
            } while (opcionSubmenu != 4);
            break;

        case 3: // Gestión de Citas
            do {
                std::cout << "\n--- Gestion de Citas ---\n";
                std::cout << "1. Registrar Cita\n";
                std::cout << "2. Eliminar Cita\n";
                std::cout << "3. Listar Citas\n";
                std::cout << "4. Volver al Menú Principal\n";
                std::cout << "Seleccione una opción: ";
                std::cin >> opcionSubmenu;

                switch (opcionSubmenu) {
                case 1: { // Registrar Cita
                    int id, pacienteId, medicoId;
                    std::string descripcion, fecha, hora;
                    std::cout << "Ingrese ID de la cita: ";
                    std::cin >> id;
                    std::cout << "Ingrese descripción de la cita: ";
                    std::cin.ignore();
                    std::getline(std::cin, descripcion);
                    std::cout << "Ingrese fecha (YYYY-MM-DD): ";
                    std::cin >> fecha;
                    std::cout << "Ingrese hora (HH:MM): ";
                    std::cin >> hora;
                    std::cout << "Ingrese ID del paciente: ";
                    std::cin >> pacienteId;
                    std::cout << "Ingrese ID del médico: ";
                    std::cin >> medicoId;
                    Appointment::registrarCita(Appointment(id, descripcion, fecha, hora, pacienteId, medicoId));
                    break;
                }
                case 2: { // Eliminar Cita
                    int id;
                    std::cout << "Ingrese ID de la cita a eliminar: ";
                    std::cin >> id;
                    Appointment::eliminarCita(id);
                    break;
                }
                case 3: // Listar Citas
                    Appointment::listarCitas();
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

    // Guardar datos antes de salir
    Patient::guardarPacientes("pacientes.txt");
    Doctor::guardarDoctores("medicos.txt");
    Appointment::guardarCitas("citas.txt");

    return 0;
}
