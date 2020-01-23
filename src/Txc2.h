#ifndef TXC2_H_
#define TXC2_H_

#include <omnetpp.h>

using namespace omnetpp;

class Txc2 : public cSimpleModule {
protected:
    void initialize() override;

    void handleMessage(cMessage *msg) override;

private:
    int counter;
};

Define_Module(Txc2);

#endif /* TXC2_H_ */
