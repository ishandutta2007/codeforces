namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
 
    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable numOnes = 0;
        using (q = Qubit[2]) {
            Set(Zero, q[0]);
            Set(Zero, q[1]);
            unitary(q);
            let res = M(q[1]);
            if (res == Zero) {
                set numOnes += 1;
            }
            Set(Zero, q[0]);
            Set(Zero, q[1]);
        }
        return numOnes;
    }
}