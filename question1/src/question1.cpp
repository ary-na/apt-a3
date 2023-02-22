#include "../include/Patient.h"

std::ostream& operator<<(std::ostream &os, const Patient& patient);

int main() {
    Patient patient("Arian", "07-01-1993", 1234567);
    patient.addAdmission("18-02-2023", "20-02-2023");
    patient.addAdmission("20-02-2022", "21-02-2023", "Emergency");
    std::cout << patient << std::endl;
    return EXIT_SUCCESS;
}

std::ostream& operator<<(std::ostream &os, const Patient& patient) {
    return os << patient.toString();
}