#ifndef QUEUE_H
#define QUEUE_H

#include "Patient.h"

class Queue {

public:
    Queue(Patient* patient, int queueNo);

    Queue(const Queue &other);

    Queue(Queue &&other);

    ~Queue();

    // Getter and setter
    Patient* getPatient();

    int getQueueNumber();

    bool getStartSurgery();

    void setPatient(Patient* patient);

    void setQueueNumber(int queueNo);

    void setStartSurgery(bool startSurgery);

private:
    Patient* patient;
    int queueNo;
    bool startSurgery;
};


#endif //QUEUE_H
