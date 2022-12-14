namespace Solution {
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : (ControlledRotation[], (Double[], Double)) {
        let model = [
            ControlledRotation((0, new Int[0]), PauliY, 0)
        ];
        let parameters = [3.152800000000015];
        let bias = 0.006199999999999983;
        return (model, (parameters, bias));
    }
}