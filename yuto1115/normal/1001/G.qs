namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;

    operation Solve (x : Qubit[], y : Qubit, k : Int) : Unit {
        CNOT(x[k],y);
    }
}