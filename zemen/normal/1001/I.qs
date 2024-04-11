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

    operation Solve(N : Int, Uf : ((Qubit[], Qubit) => ())) : Bool {
        body {
            mutable num_ones = 0;
            using (qs = Qubit[N + 1]) {
                ResetAll(qs);
                X(qs[N]);
                for (i in 0..N) {
                    H(qs[i]);
                }
                Uf(qs[0..N-1], qs[N]);
                for (i in 0..N) {
                    H(qs[i]);
                }
                DumpMachine("dump.txt");
                for (i in 0..N-1) {
                    if (M(qs[i]) == One) {
                        set num_ones = num_ones + 1;
                    }
                }
                ResetAll(qs);
            }
            return num_ones == 0;
        }
    }

    operation Oracle(x : Qubit[], y : Qubit) : () {
        body {
            //CNOT(x[0], y);
        }
    }

    operation Go() : (Int) {
        body {
            let res = Solve(3, Oracle);
            Message($"res: {res}");
            //let count = 3;
            //using (qs = Qubit[count]) {
            //    ResetAll(qs);

            //    X(qs[0]);
            //    Solve(qs[0..count-2], qs[count-1]);
            //    DumpMachine("dump.txt");

            //    ResetAll(qs);
            //}
            return 0;
        }
    }
}