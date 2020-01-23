package omnetpp_tictoc;

simple Txc3
{
    parameters:
        bool sendMsgOnInit = default(false);
        int limit = default(2);
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

network Tictoc3
{
    submodules:
        tic: Txc3 {
            parameters:
                sendMsgOnInit = true;
                @display("i=,cyan");
        };
        toc: Txc3 {
            parameters:
                sendMsgOnInit = false;
                @display("i=,gold");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
