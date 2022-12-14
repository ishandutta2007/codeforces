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
    
    operation Solve (unitary : ((Double, Qubit) => Unit is Adj+Ctl)) : Int {
        using(q = Qubit[2]){
            H(q[0]);
            Controlled unitary([q[0]],(PI()*2.0, q[1]));
            H(q[0]);
            return MResetZ(q[0]) == Zero ? 1 | 0;
        }
    }
}