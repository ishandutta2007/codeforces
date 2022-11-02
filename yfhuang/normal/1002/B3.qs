namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int {
        H(qs[0]);
        H(qs[1]);
        let res0 = M(qs[0]);
        let res1 = M(qs[1]);
        return ResultAsInt([res1 , res0]);
    }
}