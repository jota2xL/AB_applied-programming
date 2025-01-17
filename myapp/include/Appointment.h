#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "MedicalEntity.h"
#include <string>
#include <vector>

class Appointment : public MedicalEntity {
public:
    std::string fecha;
    std::string hora;
    int pacienteId; // paciente asociado
    int medicoId;   // medico asociado

    Appointment(int i, std::string d, std::string f, std::string h, int pId, int mId)
        : MedicalEntity(i, d), fecha(f), hora(h), pacienteId(pId), medicoId(mId) {
    }

    static void registrarCita(const Appointment& cita);
    static void eliminarCita(int id);
    static void listarCitas();
    static void guardarCitas(const std::string& archivo);
    static void cargarCitas(const std::string& archivo);

    static bool validarFecha(const std::string& fecha);
    static bool validarHora(const std::string& hora);
    static bool validarID(int id);
};

#endif
