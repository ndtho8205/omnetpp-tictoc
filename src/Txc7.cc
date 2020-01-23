#include "Txc7.h"

Tic7::Tic7() {
    timeoutEvent = message = nullptr;
}

Tic7::~Tic7() {
    cancelAndDelete(timeoutEvent);
    delete message;
}

cMessage *Tic7::generateNewMessage() {
    char msgname[20];
    sprintf(msgname, "tic-%d", ++seq);
    cMessage *msg = new cMessage(msgname);
    return msg;
}

void Tic7::sendCopyOf(cMessage *msg) {
    cMessage *copy = msg->dup();
    send(copy, "out");
}

void Tic7::initialize() {
    seq = 0;
    timeout = 1.0;
    timeoutEvent = new cMessage("timeoutEvent");

    EV << "Sending initial message\n";
    message = generateNewMessage();
    sendCopyOf(message);
    scheduleAt(simTime() + timeout, timeoutEvent);
}

void Tic7::handleMessage(cMessage *msg) {
    if (msg == timeoutEvent) {
        EV << "Timeout expired, resending message and restarting timer\n";
        sendCopyOf(message);
        scheduleAt(simTime() + timeout, timeoutEvent);
    } else {
        EV << "Received: " << msg->getName() << "\n";
        delete msg;

        EV << "Timer cancelled.\n";
        cancelEvent(timeoutEvent);
        delete message;

        message = generateNewMessage();
        sendCopyOf(message);
        scheduleAt(simTime() + timeout, timeoutEvent);
    }
}

void Toc7::handleMessage(cMessage *msg) {
    if (uniform(0, 1) < 0.1) {
        EV << "\"Losing\" message\n";
        bubble("message lost");
        delete msg;
    } else {
        EV << "Sending back same message as acknowledgement\n";
        delete msg;
        send(new cMessage("ack"), "out");
    }
}
