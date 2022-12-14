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
    
     operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((4, [0.5,1.0]), 
                [ControlledRotation((1, [0]), PauliX, 0),
                 ControlledRotation((0, [1]), PauliX, 1),
                 ControlledRotation((1, [0]), PauliX, 2)
                ],
                ([PI()*2.0,PI()*2.0,PI()*2.0], 0.0));
    }
}