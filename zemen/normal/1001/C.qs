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

    operation Solve(qs : Qubit[]) : () {
        body {
            H(qs[0]);
            for (i in 1..Length(qs)-1) {
                CNOT(qs[0], qs[i]);
            }
        }
    }

    operation Go() : (Int) {
        body {
            let count = 3;
            using (qs = Qubit[count]) {
                for (i in 0..count-1) {
                    Set(qs[i], Zero);
                }

                Solve(qs);
                DumpMachine("dump.txt");

                for (i in 0..count-1) {
                    Set(qs[i], Zero);
                }
            }
            return 0;
        }
    }
}