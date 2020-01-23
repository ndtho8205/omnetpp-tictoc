package omnetpp_tictoc;

simple Txc5
{
    parameters:
        volatile double delayTime @unit(s);
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

simple Tic5 extends Txc5
{
    parameters:
        @display("i=,cyan");
}

simple Toc5 extends Txc5 {
    parameters:
        @display("i=,gold");
}

network Tictoc5
{
    submodules:
        tic: Tic5;
        toc: Toc5;
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
