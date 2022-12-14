namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Arithmetic;
    
    operation RunQsharp () : Bool {
        return true;
    }
    
    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation Solve (unitary : (Qubit => Unit is Adj+Ctl)) : Int {
        mutable res = 0;
        using (q = Qubit[2]){
            H(q[0]);
            Controlled unitary([q[0]], q[1]);
            Controlled unitary([q[0]], q[1]);
            H(q[0]);
            if(MResetZ(q[0]) == One) {
                set res += 1;
                using (qq = Qubit[2]) {
                    H(qq[0]);
                    Controlled unitary([qq[0]], qq[1]);
                    Controlled Z([qq[0]], qq[1]);
                    Controlled X([qq[0]], qq[1]);
                    H(qq[0]);
                    if(MResetZ(qq[0]) == One) {
                        set res += 2;
                    }
                }
            }
            else{
                using (qqq = Qubit[2]) {
                    H(qqq[0]);
                    Controlled unitary([qqq[0]], qqq[1]);
                    Controlled Y([qqq[0]], qqq[1]);
                    H(qqq[0]);
                    if(MResetZ(qqq[0]) == One) {
                        set res += 2;
                    }
                }
            }
        }
        return res;
    }
}