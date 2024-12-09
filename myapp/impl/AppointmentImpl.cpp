#include "myapp/model/Appointment.h"
#include <iostream>

void registrarCita(Appointment& cita) {
    std::cout << "Cita registrada: " << cita.descripcion
        << " (Fecha: " << cita.fecha << ", Hora: " << cita.hora
        << ", Paciente ID: " << cita.pacienteId
        << ", M�dico ID: " << cita.medicoId << ")\n";
}
