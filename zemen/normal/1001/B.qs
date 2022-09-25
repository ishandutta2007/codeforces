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

    operation Solve(qs : Qubit[], index : Int) : () {
        body {
            H(qs[0]);
            CNOT(qs[0], qs[1]);
            if (index == 1) {
                Z(qs[1]);
            }
            if (index == 2) {
                X(qs[1]);
            }
            if (index == 3) {
                Z(qs[1]);
                X(qs[0]);
            }
        }
    }

    operation Go() : (Int) {
        body {
            let count = 2;
            using (qs = Qubit[count]) {
                for (i in 0..count-1) {
                    Set(qs[i], Zero);
                }

                Solve(qs, 3);
                DumpMachine("dump.txt");

                for (i in 0..count-1) {
                    Set(qs[i], Zero);
                }
            }
            return 0;
        }
    }
}