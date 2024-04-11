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
            Ry(0.785398, q);
            //Rx(1.570796, q);
            let res = M(q);
            if (res == One) {
                return 1;
            } else {
                return 0;
            }
        }
    }

    operation Go() : (Int) {
        body {
            let count = 1;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                H(qs[0]);
                let res = Solve(qs[0]);
                DumpMachine("dump.txt");
                Message($"res: {res}");

                ResetAll(qs);
            }
            return 0;
        }
    }
}