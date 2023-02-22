#include "../include/PatientRegister.h"

PatientRegister::PatientRegister() {}

PatientRegister::PatientRegister(const PatientRegister &other) {
    this->patients = other.patients;
}

PatientRegister::PatientRegister(PatientRegister &&other) {
    this->patients = other.patients;
    other.patients.clear();
}

PatientRegister::~PatientRegister() = default;

void PatientRegister::addPatient(Patient *patient) {
    if (!isPatientRegistered(patient->getRegistrationNo())) {
        this->patients.push_back(patient);
    } else {
        std::cout << "Patient is already registered!" << std::endl;
    }
}

void PatientRegister::removePatient(Patient *patient) {
    if (this->isPatientRegistered(patient->getRegistrationNo())) {
        this->patients.remove(patient);
    } else {
        std::cout << "Patient is not registered!" << std::endl;
    }
}

bool PatientRegister::isPatientRegistered(int registrationNo) {
    bool match = false;
    for (auto const &patient: this->patients) {
        if (patient->getRegistrationNo() == registrationNo) {
            match = true;
        }
    }
    return match;
}

Patient *PatientRegister::getPatient(int registrationNo) {
    Patient *temp = nullptr;
    for (auto const &patient: this->patients) {
        if (patient->getRegistrationNo() == registrationNo) {
            temp = patient;
        }
    }

    if (temp == nullptr) {
        throw std::invalid_argument("Registration number does not exist!");
    } else {
        return temp;
    }
}

Patient &PatientRegister::operator[](int registrationNo) {
    Patient *temp = nullptr;
    for (auto const &patient: this->patients) {
        if (patient->getRegistrationNo() == registrationNo) {
            temp = patient;
        }
    }

    if (temp == nullptr) {
        throw std::invalid_argument("Registration number does not exist!");
    } else {
        return *temp;
    }
}

