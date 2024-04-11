namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int
    {
        body
        {
            for (index in 0 .. Length(bits0)) {
                if (bits0[index] != bits1[index]) {
                    mutable res = 0;
                    if (M(qs[index]) == One) {
                        set res = 1 - res;
                    }
                    if (bits0[index]) {
                        set res = 1 - res;
                    }
                    return res;
                }
            }
            return 0;
        }
    }
}