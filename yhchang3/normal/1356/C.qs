namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
 
    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()) {
            repeat {
                Set(Zero,qs[0]);
                H(qs[0]);
                Set(Zero,qs[1]);
                H(qs[1]);
                Controlled X(qs,q);
            } until (M(q) == Zero)
            fixup {Set(Zero,q);}
        }
        X(qs[0]);
        X(qs[1]);
    }
}