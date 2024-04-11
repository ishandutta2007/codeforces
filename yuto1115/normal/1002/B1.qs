namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Int {
        for(i in 0..Length(qs)-1) {
            if(M(qs[i]) == One) {
                return 1;
            }
        }
        return 0;
    }
}