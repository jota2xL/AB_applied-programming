#include <iostream>
#include "myapp/include/Patient.h"
#include "myapp/include/Doctor.h"
#include "myapp/include/Appointment.h"

int main() {
    // Cargar datos al iniciar
    Patient::cargarPacientes("pacientes.txt");
    Doctor::cargarDoctores("medicos.txt");
    Appointment::cargarCitas("citas.txt");

    int opcionPrincipal = 0, opcionSubmenu = 0;

    while (opcionPrincipal != 4) {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Gestion de Pacientes\n";
        std::cout << "2. Gestion de Medicos\n";
        std::cout << "3. Gestion de Citas\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcionPrincipal;

        if (opcionPrincipal == 1) {
            while (opcionSubmenu != 6) {
                std::cout << "\n--- Gestion de Pacientes ---\n";
                std::cout << "1. Registrar Paciente\n";
                std::cout << "2. Buscar Paciente\n";
                std::cout << "3. Eliminar Paciente\n";
                std::cout << "4. Listar Pacientes\n";
                std::cout << "5. Modificar Paciente\n";
                std::cout << "6. Volver al Menu Principal\n";
                std::cout << "Seleccione una opcion: ";
                std::cin >> opcionSubmenu;

                if (opcionSubmenu == 1) {
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
                }
                else if (opcionSubmenu == 2) {
                    int id;
                    std::cout << "Ingrese el ID del paciente a buscar: ";
                    std::cin >> id;
                    Patient::buscarPaciente(id);
                }
                else if (opcionSubmenu == 3) {
                    int id;
                    std::cout << "Ingrese el ID del paciente a eliminar: ";
                    std::cin >> id;
                    Patient::eliminarPaciente(id);
                }
                else if (opcionSubmenu == 4) {
                    Patient::listarPacientes();
                }
                else if (opcionSubmenu == 5) {
                    int id;
                    std::cout << "Ingrese el ID del paciente a modificar: ";
                    std::cin >> id;
                    Patient::modificarPaciente(id);
                }
            }
            opcionSubmenu = 0; // Resetear para volver al menú principal
        }
        else if (opcionPrincipal == 2) {
            while (opcionSubmenu != 4) {
                std::cout << "\n--- Gestion de Medicos ---\n";
                std::cout << "1. Registrar Medico\n";
                std::cout << "2. Eliminar Medico\n";
                std::cout << "3. Listar Medicos\n";
                std::cout << "4. Volver al Menu Principal\n";
                std::cout << "Seleccione una opcion: ";
                std::cin >> opcionSubmenu;

                if (opcionSubmenu == 1) {
                    std::string nombre, especialidad;
                    int id;
                    std::cout << "Ingrese el nombre del medico: ";
                    std::cin.ignore();
                    std::getline(std::cin, nombre);
                    std::cout << "Ingrese el ID del medico: ";
                    std::cin >> id;
                    std::cout << "Ingrese la especialidad del medico: ";
                    std::cin.ignore();
                    std::getline(std::cin, especialidad);
                    Doctor::registrarDoctor(Doctor(nombre, id, especialidad));
                }
                else if (opcionSubmenu == 2) {
                    int id;
                    std::cout << "Ingrese el ID del medico a eliminar: ";
                    std::cin >> id;
                    Doctor::eliminarDoctor(id);
                }
                else if (opcionSubmenu == 3) {
                    Doctor::listarDoctores();
                }
            }
            opcionSubmenu = 0; // Resetear para volver al menú principal
        }
        else if (opcionPrincipal == 3) {
            while (opcionSubmenu != 4) {
                std::cout << "\n--- Gestion de Citas ---\n";
                std::cout << "1. Registrar Cita\n";
                std::cout << "2. Eliminar Cita\n";
                std::cout << "3. Listar Citas\n";
                std::cout << "4. Volver al Menu Principal\n";
                std::cout << "Seleccione una opcion: ";
                std::cin >> opcionSubmenu;

                if (opcionSubmenu == 1) {
                    int id, pacienteId, medicoId;
                    std::string descripcion, fecha, hora;
                    std::cout << "Ingrese ID de la cita: ";
                    std::cin >> id;
                    std::cout << "Ingrese descripcion de la cita: ";
                    std::cin.ignore();
                    std::getline(std::cin, descripcion);
                    std::cout << "Ingrese fecha (YYYY-MM-DD): ";
                    std::cin >> fecha;
                    std::cout << "Ingrese hora (HH:MM): ";
                    std::cin >> hora;
                    std::cout << "Ingrese ID del paciente: ";
                    std::cin >> pacienteId;
                    std::cout << "Ingrese ID del medico: ";
                    std::cin >> medicoId;
                    Appointment::registrarCita(Appointment(id, descripcion, fecha, hora, pacienteId, medicoId));
                }
                else if (opcionSubmenu == 2) {
                    int id;
                    std::cout << "Ingrese ID de la cita a eliminar: ";
                    std::cin >> id;
                    Appointment::eliminarCita(id);
                }
                else if (opcionSubmenu == 3) {
                    Appointment::listarCitas();
                }
            }
            opcionSubmenu = 0; // Resetear para volver al menú principal
        }
        else if (opcionPrincipal == 4) {
            std::cout << "Saliendo del sistema...\n";
        }
        else {
            std::cout << "Opcion no valida. Intente nuevamente.\n";
        }
    }

    // Guardar datos antes de salir
    Patient::guardarPacientes("pacientes.txt");
    Doctor::guardarDoctores("medicos.txt");
    Appointment::guardarCitas("citas.txt");

    return 0;
}
