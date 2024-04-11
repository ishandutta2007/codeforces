namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (q : Qubit[],bit : Bool[]) : Unit {
        mutable pos = -1;
        for(i in 0 .. Length(q)-1) {
            if(bit[i]) {
                if(pos == -1) {
                    set pos = i;
                    H(q[i]);
                } else {
                    CNOT(q[pos],q[i]);
                }
            }
        }
    }
}