#ifndef TXC5_H_
#define TXC5_H_

#include <omnetpp.h>

using namespace omnetpp;

class Txc5: public cSimpleModule {
public:
    Txc5();

    virtual ~Txc5();

protected:
    void initialize() override;

    void handleMessage(cMessage *msg) override;

private:
    cMessage *event;
    cMessage *tictocMsg;
};

Define_Module(Txc5);

#endif /* TXC5_H_ */
