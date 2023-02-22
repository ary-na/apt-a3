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

    void addPatientsToWaitingList(Queue *queue);

    void removePatientFromWaitingList(Queue *queue);

    bool isPatientInQueue(Queue *queue);

    int getNumberOfPatientsInWaitingList();

private:
    std::deque<Queue *>(waitingList);
};


#endif //WAITINGLIST_H
