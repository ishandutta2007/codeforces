namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        X(qs[0]);
        let n = Length(qs);
        mutable k = 0;
        if(n == 2) {
            set k = 1;
        } elif(n == 4) {
            set k = 2;
        } elif(n == 8) {
            set k = 3;
        } elif(n == 16) {
            set k = 4;
        }
        if(k > 0) {
            mutable now = 1;
            for(i in 0 .. k-1) {
                for(j in 0..now-1) {
                    Controlled H([qs[j]], qs[now+j]);
                    CNOT(qs[now+j],qs[j]);
                }
                set now *= 2;
            }
        }
    }
}