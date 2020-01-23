#ifndef TXC1_H_
#define TXC1_H_

#include <omnetpp.h>

using namespace omnetpp;

class Txc1 : public omnetpp::cSimpleModule {

protected:
    void initialize() override;

    void handleMessage(cMessage *msg) override;
};

Define_Module(Txc1);

#endif /* TXC1_H_ */
