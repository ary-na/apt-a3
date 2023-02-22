#include "../include/Patient.h"
#include "../include/PatientRegister.h"
#include "../include/WaitingList.h"
#include "../include/Queue.h"

std::ostream &operator<<(std::ostream &os, const Patient &patient);

int main() {

    // Testing my Abstract Data Type classes
    Patient patient1("Arian", "07-01-1993", 1234567);
    patient1.addAdmission("18-02-2023", "20-02-2023");
    patient1.addAdmission("20-02-2022", "21-02-2023", "Emergency");
    // std::cout << patient << std::endl;

    Patient patient2("Hil", "10-01-1998", 1234567);
    patient1.addAdmission("18-02-2023", "20-02-2023");
    patient1.addAdmission("20-02-2022", "21-02-2023", "Emergency");

    Patient *patient3 = new Patient("Ary", "10-01-1997", 98765454);
    Patient *patient4 = new Patient("Megan", "10-01-1997", 98765454);

    PatientRegister patientRegister;
    patientRegister.addPatient(&patient1);
    patientRegister.removePatient(patient3);

    bool isPatientRegistered = patientRegister.isPatientRegistered(1234567);
    std::cout << isPatientRegistered << std::endl;

    try {
        std::cout << patientRegister[1234567] << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << "Registration number does not exist!" << std::endl;
    }

    Queue *patientInQueue1 = new Queue(patient3, 100);
    Queue *patientInQueue2 = new Queue(patient4, 101);

    WaitingList *waitingList = new WaitingList();

    waitingList->addPatientsToWaitingList(patientInQueue1);
    waitingList->addPatientsToWaitingList(patientInQueue2);

    patientInQueue1->setStartSurgery(true);
    waitingList->removePatientFromWaitingList(patientInQueue1);

    return EXIT_SUCCESS;
}

std::ostream &operator<<(std::ostream &os, const Patient &patient) {
    return os << patient.toString();
}