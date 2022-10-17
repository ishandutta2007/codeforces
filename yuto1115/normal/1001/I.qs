namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;

    operation Solve (n : Int, Uf : ((Qubit[], Qubit) => Unit)) : Bool {
        mutable ans = true;
        using(x = Qubit[n]) {
            for(i in 0..n-1) {
                H(x[i]);
            }
            using(y = Qubit()) {
                X(y);
                H(y);
                Uf(x,y);
                Reset(y);
            }
            for(i in 0..n-1) {
                H(x[i]);
            }
            for(i in 0..n-1) {
                let res = M(x[i]);
                if(res == One) {
                    set ans = false;
                }
            }
            ResetAll(x);
        }
        return ans;
    }
}