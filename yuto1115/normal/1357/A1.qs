namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;

    operation Solve (ut : (Qubit[] => Unit)) : Int {
        using(q = Qubit[2]) {
            X(q[1]);
            ut(q);
            let res = M(q[0]);
            ResetAll(q);
            if(res == Zero) {
                return 0;
            } else {
                return 1;
            }
        }
    }
}