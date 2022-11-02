namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int {
        CNOT(qs[0], qs[1]);
        let res1 = M(qs[1]);
        H(qs[0]);
        let res0 = M(qs[0]);
        return ResultAsInt([res0, res1]);
    }
}