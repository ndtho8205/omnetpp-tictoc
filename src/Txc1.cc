#include "Txc1.h"

void Txc1::initialize() {
    if (strcmp("tic", getName()) == 0) {
        cMessage *msg = new cMessage("tictocMsg");
        send(msg, "out");
    }
}

void Txc1::handleMessage(omnetpp::cMessage *msg) {
    send(msg, "out");
}
