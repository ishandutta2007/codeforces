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
    
    operation Solve (qs : Qubit[], parity : Int) : Unit {
        for(i in 0 .. Length(qs) - 1) {
            H(qs[i]);
        }
        let res = MeasureAllZ(qs);
        if((res == One and parity == 0) or (res == Zero and parity == 1)) {
            X(qs[0]);
        }
    }
}