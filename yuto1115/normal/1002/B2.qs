namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Int {
        mutable cnt = 0;
        for(i in 0..Length(qs)-1) {
            if(M(qs[i]) == One) {
                set cnt += 1;
            }
        }
        if(cnt == 1) {
            return 1;
        } else {
            return 0;
        }
    }
}