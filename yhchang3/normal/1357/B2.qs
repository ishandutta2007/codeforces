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
    
    operation Inc (register : Qubit[]) : Unit is Adj+Ctl {
        for(i in Length(register) - 1 .. -1 .. 1) {
            Controlled X(register[0 .. i-1], register[i]);
        }
        X(register[0]);
    }
    
    operation Counting(register : Qubit[], anc : Qubit[]) : Unit is Adj+Ctl {
        for(i in 0 .. 2 .. Length(register) - 1){
            Controlled Inc([register[i]], anc);
        }
        for(i in 1 .. 2 .. Length(register) - 1){
            Controlled Adjoint Inc([register[i]], anc);
        }
    }
    
    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (anc = Qubit[4]) {
            Counting(inputs, anc);
            (ControlledOnInt(0, X)) (anc, output);
            (ControlledOnInt(3, X)) (anc, output);
            (ControlledOnInt(6, X)) (anc, output);
            (ControlledOnInt(13, X)) (anc, output);
            (ControlledOnInt(10, X)) (anc, output);
            Adjoint Counting(inputs, anc);
        }
    }
}