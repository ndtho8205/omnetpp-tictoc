#ifndef TXC7_H_
#define TXC7_H_

#include <omnetpp.h>

using namespace omnetpp;

class Tic7 : public cSimpleModule {
public:
    Tic7();

    virtual ~Tic7();

protected:
    virtual cMessage *generateNewMessage();

    virtual void sendCopyOf(cMessage *msg);

    void initialize() override;

    void handleMessage(cMessage *msg) override;

private:
    simtime_t timeout;
    cMessage *timeoutEvent;
    int seq;
    cMessage *message;
};

Define_Module(Tic7);

class Toc7 : public cSimpleModule {
protected:
    void handleMessage(cMessage *msg) override;
};

Define_Module(Toc7);

#endif /* TXC7_H_ */
