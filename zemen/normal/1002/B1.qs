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
            for (i in 1..Length(qs)-1) {
                CNOT(qs[i], qs[0]);
            }
            if (M(qs[0]) == One) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    operation Go() : (Int) {
        body {
            let count = 3;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                let res = Solve(qs);
                Message($"res: {res}");
                DumpMachine("dump.txt");

                ResetAll(qs);
            }
            return 0;
        }
    }
}