namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.MachineLearning;
    
    operation RunQsharp () : Bool {
        return true;
    }
    
    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation Solve (qs : Qubit[]) : Unit {
        using (q = Qubit()) {
            repeat {
                for (i in 0 .. Length(qs) - 1) {
                    Set(Zero,qs[i]);
                    H(qs[i]);
                }
                Controlled X(qs,q);
            } until (M(q) == Zero)
            fixup {Set(Zero,q);}
        }
    }
}