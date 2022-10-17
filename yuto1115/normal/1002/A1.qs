namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (q : Qubit[]) : Unit {
        for(i in 0..Length(q)-1) {
            H(q[i]);
        }
    }
}