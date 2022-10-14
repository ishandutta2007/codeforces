namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            (Controlled Z)(qs[0..0], qs[1]);
            CNOT(qs[0], qs[1]);
            Z(qs[1]);
            H(qs[0]);
            H(qs[1]);

            DumpRegister("a.txt", qs);
            mutable res = 0;
            if (M(qs[0]) == One)
            {
                set res = res + 2;
            }
            if (M(qs[1]) == One)
            {
                set res = res + 1;
            }
            if (res > 0)
            {
                set res = (res + 1) % 3 + 1;
            }
            return res;
        }
    }
}