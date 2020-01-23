package omnetpp_tictoc;

simple Txc2
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

network Tictoc2
{
    submodules:
        tic: Txc2 {
            parameters:
                @display("i=,cyan");
        };
        toc: Txc2 {
            parameters:
                @display("i=,gold");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        tic.in <-- {  delay = 100ms; } <-- toc.out;
}
