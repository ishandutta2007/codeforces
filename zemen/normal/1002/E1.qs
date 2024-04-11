namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Set(q : Qubit, val : Result) : () {
        body {
            let res = M(q);
            if (res != val) {
                X(q);
            }
        }
    }

    operation Oracle1(x : Qubit[], y : Qubit) : () {
        body {
            let b = [1; 0; 1];
            for (i in 0..Length(b)-1) {
                if (b[i] == 1) {
                    CNOT(x[i], y);
                }
            }
        }
    }

    operation Oracle2(x : Qubit[], y : Qubit) : () {
        body {
            let b = [1; 0; 1];
            for (i in 0..Length(b)-1) {
                if (b[i] == 1) {
                    CNOT(x[i], y);
                } else {
                    X(x[i]);
                    CNOT(x[i], y);
                    X(x[i]);
                }
            }
        }
    }

    operation Solve(N : Int, Uf : ((Qubit[], Qubit) => ())) : Int[] {
        body {
            mutable res = new Int[N];
            using (qs = Qubit[N+1]) {
                ResetAll(qs);
                X(qs[N]);
                for (i in 0..N) {
                    H(qs[i]);
                }
                Uf(qs[0..N-1], qs[N]);
                for (i in 0..N-1) {
                    H(qs[i]);
                }
                DumpMachine("dump.txt");
                for (i in 0..N-1) {
                    if (M(qs[i]) == One) {
                        set res[i] = 1;
                    } else {
                        set res[i] = 0;
                    }
                }
                ResetAll(qs);
            }
            return res;
        }
    }

    operation Go() : (Int) {
        body {
            let res = Solve(3, Oracle1);
            Message($"res: {res}");
            //let count = 4;
            //using (qs = Qubit[count]) {
            //    ResetAll(qs);

            //    //X(qs[2]);

            //    Solve(qs[0..count-2], qs[count-1], [0; 0; 0]);
            //    DumpMachine("dump.txt");

            //    ResetAll(qs);
            //}
            return 0;
        }
    }
}