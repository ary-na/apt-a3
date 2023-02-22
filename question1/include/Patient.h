#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <iostream>
#include "PatientAdmission.h"

class Patient {
public:
    Patient(std::string name, std::string dateOfBirth, int registrationNo);

    Patient(const Patient &other);

    Patient(Patient &&other);

    ~Patient();

    void addAdmission(std::string admissionDate, std::string dischargeDate,
                      std::string admittedWard = "Not applicable");

    std::string toString() const;

private:
    std::string name;
    std::string dateOfBirth;
    int registrationNo;
    std::vector <PatientAdmission> admissionHistory;

};

#endif //PATIENT_H
