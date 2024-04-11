namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            mutable firstBit = -1;
            for (i in 0..Length(qs) - 1)
            {
                if (bits[i])
                {
                    if (firstBit == -1)
                    {
                        H(qs[i]);
                        set firstBit = i;
                    }
                    else
                    {
                        CNOT(qs[firstBit], qs[i]);
                    }
                }
            }
        }
    }
}