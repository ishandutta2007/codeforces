namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (x : Qubit[], y : Qubit, k : Int) : Unit {
        CNOT(x[k], y);
    }
}