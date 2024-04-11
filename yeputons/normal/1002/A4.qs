namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : ()
    {
        body
        {
            X(qs[0]);
            if (Length(qs) > 1)
            {
                mutable curLen = 1;
                repeat
                {
                    for (i in 0..curLen - 1)
                    {
                        CNOT(qs[i], qs[i + curLen]);
                        (Controlled H)(qs[i..i], qs[i + curLen]);
                        Z(qs[i + curLen]);
                        CNOT(qs[i + curLen], qs[i]);
                    }
                    set curLen = curLen * 2;
                }
                until curLen >= Length(qs)
                fixup {};
            }
        }
    }
}