namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (x : Qubit[], y : Qubit, b : Int[]) : Unit {
        for (i in 0..Length(b)-1)
        {
            if(b[i] == 0){
                X(x[i]);
                CNOT(x[i], y);
                X(x[i]);
            }else{
                CNOT(x[i], y);
            }
        }
    }
}