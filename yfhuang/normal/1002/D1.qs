namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : Unit {
        for (i in 0..Length(b)-1)
        {
            if(b[i] == 1){
                CNOT(x[i], y);
            }
        }
    }
}