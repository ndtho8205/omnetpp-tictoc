#include "Txc2.h"

void Txc2::initialize() {
    counter = 10;
    WATCH(counter);

    if (strcmp("tic", getName()) == 0) {
        EV << "Sending initial message\n";
        cMessage *msg = new cMessage("tictoc2");
        send(msg, "out");
    }
}

void Txc2::handleMessage(cMessage *msg) {
    counter--;
    if (counter == 0) {
        EV << getName() << "'s counter reached 0, deleting message\n";
        delete msg;
    } else {
        EV << getName() << "'s counter is " << counter << "`, sending back message\n";
        send(msg, "out");
    }
}
