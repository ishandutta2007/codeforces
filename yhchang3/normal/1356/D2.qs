namespace Solution {
    open Microsoft.Quantum.MachineLearning;
 
    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        let model = [
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ];
        let parameters = [1.1418061687968337];
        let bias = 0.28486846648022845;
        return (model, (parameters, bias));
    }
}