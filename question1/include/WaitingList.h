#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <deque>
#include <map>
#include "Patient.h"
#include "Queue.h"

class WaitingList {

public:
    WaitingList();

    WaitingList(const WaitingList &other);

    WaitingList(WaitingList &&other);

    ~WaitingList();

    // This function takes a queue object and add it to the queue.
    void addPatientsToWaitingList(Queue *queue);

    // This function takes a queue object and removes it from the queue.
    void removePatientFromWaitingList(Queue *queue);

    // This function takes a queue and return a boolean if a patient is in the queue.
    bool isPatientInQueue(Queue *queue);

    // This function return number of patients in the queue.
    int getNumberOfPatientsInWaitingList();

private:
    // I have used a double ended queue as I needed to iterate and check if
    // a patient is not added to the queue twice. Also, it is very efficient with
    // constant time insertion.
    std::deque<Queue *>(waitingList);
};


#endif //WAITINGLIST_H
