#ifndef PATIENTREGISTER_H
#define PATIENTREGISTER_H

#include <list>
#include <iterator>
#include "Patient.h"

class PatientRegister {
public:
    PatientRegister();

    PatientRegister(const PatientRegister &other);

    PatientRegister(PatientRegister &&other);

    ~PatientRegister();

    void addPatient(Patient* patient);

    void removePatient(Patient* patient);

    bool isPatientRegistered(int registrationNo);

    Patient* getPatient(int registrationNo);

    Patient &operator[] (int registrationNo);

private:
    std::list<Patient *> patients;
};


#endif //PATIENTREGISTER_H
