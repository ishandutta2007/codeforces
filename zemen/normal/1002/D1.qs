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

    operation Solve(x : Qubit[], y : Qubit, b : Int[]) : () {
        body {
            for (i in 0..Length(b)-1) {
                if (b[i] == 1) {
                    CNOT(x[i], y);
                }
            }
        }
    }

    operation Go() : (Int) {
        body {
            let count = 4;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                X(qs[1]);
                X(qs[1]);
                X(qs[2]);

                Solve(qs[0..count-2], qs[count-1], [1; 1; 0]);
                DumpMachine("dump.txt");

                ResetAll(qs);
            }
            return 0;
        }
    }
}