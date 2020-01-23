#ifndef TXC3_H_
#define TXC3_H_

#include <omnetpp.h>

using namespace omnetpp;

class Txc3: public cSimpleModule {
protected:
    void initialize() override;

    void handleMessage(cMessage *msg) override;

private:
    int counter;
};

Define_Module(Txc3);

#endif /* TXC3_H_ */
