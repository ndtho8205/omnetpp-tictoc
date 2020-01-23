package omnetpp_tictoc;

simple Tic7
{
    parameters:
        @display("i=block/routing,cyan");
    gates:
        input in;
        output out;
}

simple Toc7 {
    parameters:
        @display("i=block/process,gold");
    gates:
        input in;
        output out;
}

network Tictoc7
{
    submodules:
        tic: Tic7;
        toc: Toc7;
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
