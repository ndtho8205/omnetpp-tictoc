#ifndef TXC6_H_
#define TXC6_H_

#include <omnetpp.h>

using namespace omnetpp;

class Tic6 : public cSimpleModule {
public:
    Tic6();

    virtual ~Tic6();

protected:
    void initialize() override;

    void handleMessage(cMessage *msg) override;

private:
    simtime_t timeout;
    cMessage *timeoutEvent;
};

Define_Module(Tic6);

class Toc6 : public cSimpleModule {
protected:
    void handleMessage(cMessage *msg) override;
};

Define_Module(Toc6);

#endif /* TXC6_H_ */
