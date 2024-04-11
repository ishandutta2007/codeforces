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
            mutable res = -1;
            using (qs = Qubit[1]) {
                ResetAll(qs);
                H(qs[0]);
                let rnd = M(qs[0]);
                if (rnd == One) {
                    let m = M(q);
                    if (m == One) {
                        set res = 1;
                    }
                } else {
                    H(q);
                    let m = M(q);
                    if (m == One) {
                        set res = 0;
                    }
                }
                ResetAll(qs);
            }

            return res;
        }
    }

    operation Go() : (Int) {
        body {
            let count = 1;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                //H(qs[0]);
                //DumpMachine("dump.txt");
                let res = Solve(qs[0]);
                Message($"res: {res}");

                ResetAll(qs);
            }
            return 0;
        }
    }
}