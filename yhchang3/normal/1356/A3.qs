namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
 
    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable numOnes = 0;
        using (q = Qubit()) {
            Set(Zero, q);
            H(q);
            unitary(q);
            unitary(q);
            H(q);
            let res = M(q);
            if (res == One) {
                set numOnes += 1;
            }
            Set(Zero, q);
        }
        return numOnes;
    }
}