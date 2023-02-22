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

    // This function adds a patient to the linked list.
    void addPatient(Patient *patient);

    // This function removes a patient to the linked list.
    void removePatient(Patient *patient);

    // This function returns a boolean if patient exists in the linked list.
    bool isPatientRegistered(int registrationNo);

    // This functions takes a registration number and return a patient from the
    // linked list.
    Patient *getPatient(int registrationNo);

    // This functions takes a registration number and return a patient from the
    // linked list.
    Patient &operator[](int registrationNo);

private:
    // I have utilised doubly linked list as it is very efficient when
    // we don't know ahead of time how many entries we are going to record.
    std::list<Patient *> patients;
};


#endif //PATIENTREGISTER_H
