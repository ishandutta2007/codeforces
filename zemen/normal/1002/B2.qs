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
            for (i in 0..Length(qs)-2) {
                CNOT(qs[i + 1], qs[i]);
                if (M(qs[i]) == One) {
                    return 1;
                }
            }
            return 0;
        }
    }

    operation Go() : (Int) {
        body {
            let count = 3;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                H(qs[0]);
                for (i in 1..count-1) {
                    CNOT(qs[0], qs[i]);
                }

                let res = Solve(qs);
                Message($"res: {res}");
                DumpMachine("dump.txt");

                ResetAll(qs);
            }
            return 0;
        }
    }
}