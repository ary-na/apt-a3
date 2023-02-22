#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include <iostream>
#include "PatientAdmission.h"

class Patient {
public:
    Patient();
    Patient(std::string name, std::string dateOfBirth, int registrationNo);

    Patient(const Patient &other);

    Patient(Patient &&other);

    ~Patient();

    // This function create PatientAdmission object and adds the admissions to it.
    void addAdmission(std::string admissionDate, std::string dischargeDate,
                      std::string admittedWard = "Not applicable");

    // This function returns patient information in form of a string.
    std::string toString() const;

    // Getter
    int getRegistrationNo();

private:
    std::string name;
    std::string dateOfBirth;
    int registrationNo;
    // I have used a vector of PatientAdmission class to store admissions,
    // for each patient. Vector here makes sense as it is very efficient and can
    // Allocate more memory efficiently and automatically when needed.
    std::vector <PatientAdmission> admissionHistory;

};

#endif //PATIENT_H
