#include "../include/Queue.h"

Queue::Queue(Patient *patient, int queueNo) {
    this->patient = patient;
    this->queueNo = queueNo;
    this->startSurgery = false;
}

Queue::Queue(const Queue &other) {
    this->patient = other.patient;
    this->queueNo = other.queueNo;
    this->startSurgery = other.startSurgery;
}

Queue::Queue(Queue &&other) {
    this->patient = other.patient;
    this->queueNo = other.queueNo;
    this->startSurgery = other.startSurgery;
    other.patient = nullptr;
    other.queueNo = 0;
    other.startSurgery = false;
}

Queue::~Queue() {
    delete this->patient;
}

Patient *Queue::getPatient() {
    return this->patient;
}

int Queue::getQueueNumber() {
    return this->queueNo;
}

bool Queue::getStartSurgery() {
    return this->startSurgery;
}

void Queue::setPatient(Patient *patient) {
    this->patient = patient;
}

void Queue::setQueueNumber(int queueNo) {
    this->queueNo = queueNo;
}

void Queue::setStartSurgery(bool startSurgery) {
    this->startSurgery = startSurgery;
}