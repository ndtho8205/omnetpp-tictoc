#include "Txc5.h"

Txc5::Txc5() {
    event = tictocMsg = nullptr;
}

Txc5::~Txc5() {
    cancelAndDelete(event);
    delete tictocMsg;
}

void Txc5::initialize() {
    event = new cMessage("event");
    tictocMsg = nullptr;

    if (strcmp("tic", getName()) == 0) {
        EV << "Scheduling first send to t=10.0s\n";
        tictocMsg = new cMessage("tictocMsg");
        scheduleAt(10.0, event);
    }
}

void Txc5::handleMessage(cMessage *msg) {
    if (msg == event) {
        EV << "Wait period is over, sending back message\n";
        send(tictocMsg, "out");
        tictocMsg = nullptr;
    } else {
        if (uniform(0, 1) < 0.1) {
            EV << "\"Losing\" message\n";
            delete msg;
        } else {
            simtime_t delay = par("delayTime");

            EV << "Message arrived, starting to wait " << delay << " sec...\n";
            tictocMsg = msg;
            scheduleAt(simTime() + delay, event);
        }
    }
}

