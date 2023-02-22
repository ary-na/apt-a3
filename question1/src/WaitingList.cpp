#include "../include/WaitingList.h"

WaitingList::WaitingList() {
}

WaitingList::WaitingList(const WaitingList &other) {
    this->waitingList = other.waitingList;
}

WaitingList::WaitingList(WaitingList &&other) {
    this->waitingList = other.waitingList;
    this->waitingList.clear();
}

WaitingList::~WaitingList() = default;

void WaitingList::addPatientsToWaitingList(Queue *queue) {
    if (!this->isPatientInQueue(queue)) {
        this->waitingList.push_front(queue);
    }
}

void WaitingList::removePatientFromWaitingList(Queue *queue) {
    if (this->isPatientInQueue(queue) && queue->getStartSurgery()) {
        this->waitingList.pop_back();
    }
}

bool WaitingList::isPatientInQueue(Queue *queue) {
    bool match = false;
    for (auto &q: this->waitingList) {
        if (q->getQueueNumber() == queue->getQueueNumber()) {
            match = true;
        }
    }
    return match;
}

int WaitingList::getNumberOfPatientsInWaitingList() {
    return this->waitingList.size();
}

