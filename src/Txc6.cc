#include "Txc6.h"

Tic6::Tic6() {
    timeoutEvent = nullptr;
}

Tic6::~Tic6() {
    cancelAndDelete(timeoutEvent);
}

void Tic6::initialize() {
    timeout = 1.0;
    timeoutEvent = new cMessage("timeoutEvent");

    EV << "Sending initial message\n";
    cMessage *msg = new cMessage("tictocMsg");
    send(msg, "out");
    scheduleAt(simTime() + timeout, timeoutEvent);
}

void Tic6::handleMessage(cMessage *msg) {
    if (msg == timeoutEvent) {
        EV << "Timeout expired, resending message and restarting timer\n";
        cMessage *newMsg = new cMessage("tictocMsg");
        send(newMsg, "out");
        scheduleAt(simTime() + timeout, timeoutEvent);
    } else {
        EV << "Timer cancelled.\n";
        cancelEvent(timeoutEvent);
        delete msg;

        cMessage *newMsg = new cMessage("tictocMsg");
        send(newMsg, "out");
        scheduleAt(simTime() + timeout, timeoutEvent);
    }
}


void Toc6::handleMessage(cMessage *msg) {
    if (uniform(0, 1) < 0.1) {
        EV << "\"Losing\" message\n";
        bubble("message lost");
        delete msg;
    } else{
        EV << "Sending back same message as acknowledgement\n";
        send(msg, "out");
    }
}
