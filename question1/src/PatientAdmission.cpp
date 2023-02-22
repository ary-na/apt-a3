#include "../include/PatientAdmission.h"

PatientAdmission::PatientAdmission() {
    this->admissionDate = "";
    this->dischargeDate = "";
    this->admittedWard = "";
}

PatientAdmission::PatientAdmission(std::string admissionDate,
                                   std::string dischargeDate,
                                   std::string admittedWard) {
    this->admissionDate = admissionDate;
    this->dischargeDate = dischargeDate;
    this->admittedWard = admittedWard;
}

PatientAdmission::PatientAdmission(const PatientAdmission &other) {
    this->admissionDate = other.admissionDate;
    this->dischargeDate = other.dischargeDate;
    this->admittedWard = other.admittedWard;
}

PatientAdmission::PatientAdmission(PatientAdmission &&other) {
    this->admissionDate = other.admissionDate;
    this->dischargeDate = other.dischargeDate;
    this->admittedWard = other.admittedWard;
    other.admissionDate = nullptr;
    other.dischargeDate = nullptr;
    other.admittedWard = nullptr;
}

PatientAdmission::~PatientAdmission() = default;

std::string PatientAdmission::getAdmissionDate() {
    return this->admissionDate;
}

std::string PatientAdmission::getDischargeDate() {
    return this->dischargeDate;
}

std::string PatientAdmission::getAdmittedWard() {
    return this->admittedWard;
}

void PatientAdmission::setAdmissionDate(std::string admissionDate) {
    this->admissionDate = admissionDate;
}

void PatientAdmission::setDischargeDate(std::string dischargeDate) {
    this->dischargeDate = dischargeDate;
}

void PatientAdmission::setAdmittedWard(std::string admittedWard) {
    this->admittedWard = admittedWard;
}

std::string PatientAdmission::toString() {
    std::string admission =
            "Admission Date: " + this->admissionDate + " | Discharge Date: " +
            this->dischargeDate + " | Admitted Ward: " + this->admittedWard;
    return admission;
}