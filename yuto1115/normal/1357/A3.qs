namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (ut : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable ans = 0;
        using (q = Qubit()) {
            ut(q);
            X(q);
            ut(q);
            if(M(q) == One) {
                set ans = 1;
            }
            Reset(q);
        }
        return ans;
    }
}