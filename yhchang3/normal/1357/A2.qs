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
            if(MResetZ(q[0]) == One and MResetZ(q[1]) == One ) {
                using(qq = Qubit[2]){
                    Set(One, qq[0]);
                    Set(Zero, qq[1]);
                    unitary(qq);
                    let res1 = M(qq[0]);
                    Set(Zero, qq[0]);
                    Set(Zero, qq[1]);
                    return res1 == One ? 0 | 3;
                }
            }
            else {
                Set(Zero, q[0]);
                Set(Zero, q[1]);
                using (qqq = Qubit[2]) {
                    Set(One, qqq[0]);
                    Set(One, qqq[1]);
                    unitary(qqq);
                    let res2 = M(qqq[0]);
                    Set(Zero, qqq[0]);
                    Set(Zero, qqq[1]);
                    return res2 == One ? 1 | 2;
                }
            }
        }
    }
}