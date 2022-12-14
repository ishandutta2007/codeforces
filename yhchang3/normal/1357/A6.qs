namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Arithmetic;
    
    operation RunQsharp () : Bool {
        return true;
    }
    
    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable res = 0;
        using (q = Qubit[2]) {
            H(q[0]);
            CNOT(q[0],q[1]);
            unitary(q[1]);
            CNOT(q[0],q[1]);
            H(q[0]);
            let r0 = MResetZ(q[0]);
            let r1 = MResetZ(q[1]);
            if(r0 == Zero and r1 == Zero) {
                set res = 0;
            }
            if(r0 == Zero and r1 == One) {
                set res = 1;
            }
            if(r0 == One and r1 == Zero) {
                set res = 3;
            }
            if(r0 == One and r1 == One) {
                set res = 2;
            }
        }
        return res;
    }
}