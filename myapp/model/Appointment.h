#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "MedicalEntity.h"

class Appointment : public MedicalEntity {
public:
    std::string fecha;
    std::string hora;
    int pacienteId; // ID del paciente asociado
    int medicoId;   // ID del médico asociado

    Appointment(int i, std::string d, std::string f, std::string h, int pId, int mId)
        : MedicalEntity(i, d), fecha(f), hora(h), pacienteId(pId), medicoId(mId) {
    }
};

#endif
