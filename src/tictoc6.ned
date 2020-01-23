package omnetpp_tictoc;

simple Tic6
{
    parameters:
        @display("i=block/routing,cyan");
    gates:
        input in;
        output out;
}

simple Toc6 {
    parameters:
        @display("i=block/process,gold");
    gates:
        input in;
        output out;
}

network Tictoc6
{
    submodules:
        tic: Tic6;
        toc: Toc6;
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
