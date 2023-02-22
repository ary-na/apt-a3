#include "../include/Patient.h"

Patient::Patient() {}

Patient::Patient(std::string name, std::string dateOfBirth,
                 int registrationNo) {
    this->name = name;
    this->dateOfBirth = dateOfBirth;
    this->registrationNo = registrationNo;
}

Patient::Patient(const Patient &other) {
    this->name = other.name;
    this->dateOfBirth = other.dateOfBirth;
    this->registrationNo = other.registrationNo;
    this->admissionHistory = other.admissionHistory;
}

Patient::Patient(Patient &&other) {
    this->name = other.name;
    this->dateOfBirth = other.dateOfBirth;
    this->registrationNo = other.registrationNo;
    this->admissionHistory = other.admissionHistory;
    other.name = "";
    other.dateOfBirth = "";
    other.registrationNo = 0;
    for (auto &admission: other.admissionHistory) {
        admission.setAdmissionDate("");
        admission.setDischargeDate("");
        admission.setAdmittedWard("");
    }
}

Patient::~Patient() = default;

void Patient::addAdmission(std::string admissionDate, std::string dischargeDate,
                           std::string admittedWard) {
    PatientAdmission newAdmission(admissionDate, dischargeDate, admittedWard);
    this->admissionHistory.push_back(newAdmission);
}

int Patient::getRegistrationNo(){
    return this->registrationNo;
}

std::string Patient::toString() const {

    std::string patientName = "\nName: " + this->name;
    std::string patientDateOfBirth = "\nDate of Birth: " + this->dateOfBirth;
    std::string patientRegistrationNo =
            "\nRegistration Number: " +
            std::to_string(abs(this->registrationNo));
    std::string patientAdmissionHistory = "\n\nAdmission History";
    for (auto patientAdmission: this->admissionHistory) {
        patientAdmissionHistory += "\n" + patientAdmission.toString();
    }

    std::string patient =
            patientName + patientDateOfBirth + patientRegistrationNo +
            patientAdmissionHistory + "\n";
    return patient;

}