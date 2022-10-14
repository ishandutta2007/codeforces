namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Convert;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            H(qs[0]);
            H(qs[1]);
            //DumpRegister("", qs);
            mutable res = 0;
            if (M(qs[0]) == One)
            {
                set res = res + 2;
            }
            if (M(qs[1]) == One)
            {
                set res = res + 1;
            }
            return res;
        }
    }
}