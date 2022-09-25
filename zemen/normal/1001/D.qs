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

    operation Solve(q : Qubit) : Int {
        body {
            let res = Measure([PauliX], [q]);
            if (res == Zero) {
                return 1;
            } else {
                return -1;
            }
        }
    }

    operation Go() : (Int) {
        body {
            let count = 1;
            using (qs = Qubit[count]) {
                for (i in 0..count-1) {
                    Set(qs[i], Zero);
                }

                X(qs[0]);
                H(qs[0]);
                let res = Solve(qs[0]);
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