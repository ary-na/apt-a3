#ifndef PATIENTADMISSION_H
#define PATIENTADMISSION_H

#include <string>

class PatientAdmission {
public:
    PatientAdmission();

    PatientAdmission(std::string admissionDate, std::string dischargeDate,
                     std::string admittedWard = "Not applicable");

    PatientAdmission(const PatientAdmission &other);

    PatientAdmission(PatientAdmission &&other);

    ~PatientAdmission();

    std::string toString();

    // Getter and setter
    std::string getAdmissionDate();
    std::string getDischargeDate();
    std::string getAdmittedWard();

    void setAdmissionDate(std::string admissionDate);
    void setDischargeDate(std::string dischargeDate);
    void setAdmittedWard(std::string admittedWard);

private:
    std::string admissionDate;
    std::string dischargeDate;
    std::string admittedWard;
};


#endif //PATIENTADMISSION_H
