namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (ut : (Qubit[] => Unit)) : Int {
        using(q = Qubit[2]) {
            X(q[1]);
            ut(q);
            let res0 = M(q[0]);
            let res1 = M(q[1]);
            ResetAll(q);
            if(res0 == Zero) {
                mutable ans = 1;
                using(r = Qubit[2]) {
                    X(r[0]);
                    ut(r);
                    let l = M(r[1]);
                    if(l == Zero) {
                        set ans = 0;
                    }
                    ResetAll(r);
                }
                return ans;
            } elif(res1 == One) {
                return 2;
            } else {
                return 3;
            }
        }
    }
}