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

    operation Solve(qs : Qubit[]) : Int {
        body {
            CNOT(qs[0], qs[1]);
            H(qs[0]);
            let res0 = M(qs[0]);
            let res1 = M(qs[1]);
            mutable res = 0;
            if (res0 == One) {
                set res = res + 1;
            }
            if (res1 == One) {
                set res = res + 2;
            }
            return res;
        }
    }

    operation Go() : (Int) {
        body {
            let count = 2;
            using (qs = Qubit[count]) {
                for (i in 0..count-1) {
                    Set(qs[i], Zero);
                }

                H(qs[0]);
                CNOT(qs[0], qs[1]);
                Z(qs[0]);
                X(qs[0]);

                let res = Solve(qs);
                Message($"res: {res}");
                DumpMachine("dump.txt");

                for (i in 0..count-1) {
                    Set(qs[i], Zero);
                }
            }
            return 0;
        }
    }
}