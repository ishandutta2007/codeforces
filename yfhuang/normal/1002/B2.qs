namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Solve (qs : Qubit[]) : Int {
        mutable counter = 0;
        for (i in 0..Length(qs)-1)
        {
            if(M(qs[i]) == One)
            {
                set counter = counter + 1;
            }
        }
        if(counter == 1)
        {
            return 1;
        }else{
            return 0;
        }
    }
}