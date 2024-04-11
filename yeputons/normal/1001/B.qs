namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Bitwise;

    operation Solve (qs : Qubit[], index : Int) : ()
    {
        body
        {
            H(qs[0]);
            if (And(index, 1) != 0) {
                Z(qs[0]);
            }
            if (And(index, 2) != 0) {
                X(qs[1]);
            }
            CNOT(qs[0], qs[1]);
        }
    }
}