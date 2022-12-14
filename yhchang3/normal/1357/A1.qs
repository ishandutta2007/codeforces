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
    
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        using (q = Qubit[2]) {
            Set(One, q[0]);
            Set(One, q[1]);
            unitary(q);
            let res = M(q[0]);
            Set(Zero, q[0]);
            Set(Zero, q[1]);
            return res == One ? 0 | 1;
        }
    }
}