package omnetpp_tictoc;

simple Txc4
{
    parameters:
        bool sendMsgOnInit = default(false);
        int limit = default(2);
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

simple Tic4 extends Txc4
{
    parameters:
        @display("i=,cyan");
        sendMsgOnInit = true;
}

simple Toc4 extends Txc4 {
    parameters:
        @display("i=,gold");
        sendMsgOnInit = false;
}

network Tictoc4
{
    submodules:
        tic: Tic4;
        toc: Toc4;
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
