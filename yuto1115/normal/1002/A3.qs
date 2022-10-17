namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Unit {
        mutable pos = -1;
        for(i in 0 .. Length(qs)-1) {
            if(bits0[i] != bits1[i]) {
                if(pos == -1) {
                    set pos = i;
                    H(qs[i]);
                } else {
                    CNOT(qs[pos],qs[i]);
                    if(bits0[pos] != bits0[i]) {
                        X(qs[i]);
                    }
                }
            } else {
                if(bits0[i]) {
                    X(qs[i]);
                }
            }
        }
    }
}