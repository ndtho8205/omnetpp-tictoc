#include "Txc4.h"

void Txc4::initialize() {
    counter = par("limit");

    if (par("sendMsgOnInit").boolValue() == true) {
        EV << "Sending initial message\n";
        cMessage *msg = new cMessage("tictoc2");
        send(msg, "out");
    }
}

void Txc4::handleMessage(cMessage *msg) {
    counter--;
    if (counter == 0) {
        EV << getName() << "'s counter reached 0, deleting message\n";
        delete msg;
    } else {
        EV << getName() << "'s counter is " << counter << "`, sending back message\n";
        send(msg, "out");
    }
}
