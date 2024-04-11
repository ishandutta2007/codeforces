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
        return ((1, [0.0, 0.0, 0.0, 0.0 , 1.58113883008, 2.5]), 
                [ControlledRotation((0, [1,2]), PauliY, 0),
                 ControlledRotation((0, [1,2]), PauliX, 1),
                 ControlledRotation((1, [0,2]), PauliX, 2),
                 ControlledRotation((0, [1,2]), PauliY, 3),
                 ControlledRotation((0, [1,2]), PauliX, 4),
                 ControlledRotation((2, [0,1]), PauliX, 5)
                ],
                ([-PI()*7.0/18.0, PI(), PI(), PI()/2.0, 0.0, PI()], 0.0));
    }
}