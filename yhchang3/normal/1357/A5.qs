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
    
    operation Solve (theta : Double, unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        using (q = Qubit()) {
            mutable ok = false;
            for(i in 0 .. 10){
                Set(Zero, q);
                let N = Floor(PI() / theta);
                for(j in 0 .. N - 1) {
                    unitary(q);
                }
                if(MResetZ(q) == One) {
                    set ok = true;
                }
            }
            return ok ? 1 | 0;
        }
    }
}