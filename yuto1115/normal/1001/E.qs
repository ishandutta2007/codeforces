namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Int {
        CNOT(qs[0],qs[1]);
        let res = M(qs[1]);
        H(qs[0]);
        if(res == Zero) {
            let res2 = M(qs[0]);
            if(res2 == Zero) {
                return 0;
            } else {
                return 1;
            }
        } else {
            let res2 = M(qs[0]);
            if(res2 == Zero) {
                return 2;
            } else {
                return 3;
            }
        }
    }
}