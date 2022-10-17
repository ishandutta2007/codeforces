namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (q : Qubit) : Int {
        H(q);
        let res = M(q);
        if(res == Zero) {
            return 1;
        } else {
            return -1;
        }
    }
}