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
            if (Length(qs) == 1) {
                X(qs[0]);
            } else {
                mutable lg = 0;
                mutable ways = 1;
                repeat {
                    H(qs[lg]);
                    set lg = lg + 1;
                    set ways = ways * 2;
                }
                until (ways == Length(qs))
                fixup {
                }
                mutable last = ways-1;
                for (i in ways-1..-1..1) {
                    //Message($"i: {i}");
                    mutable ones = 0;
                    mutable p2 = 1;
                    for (j in 0..lg-1) {
                        let bit = (i / p2) % 2;
                        if (bit == 1) {
                            set ones = ones + 1;
                        }
                        set p2 = p2 * 2;
                    }
                    set p2 = 1;

                    mutable inds = new Int[ones];
                    mutable pos = 0;
                    for (j in 0..lg-1) {
                        let bit = (i / p2) % 2;
                        if (bit == 1) {
                            set inds[pos] = j;
                            set pos = pos + 1;
                        }
                        set p2 = p2 * 2;
                    }
                    //Message($"inds: {inds}");
                    (Controlled X) (Subarray(inds, qs), qs[last]);
                    for (ii in 0..Length(inds)-1) {
                        CNOT(qs[last], qs[inds[ii]]);
                    }
                    set last = last - 1;
                }

                //if (Length(qs) == 4) {
                //    (Controlled X) ([qs[0]; qs[1]], qs[3]);
                //    CNOT(qs[3], qs[1]);
                //    CNOT(qs[3], qs[0]);

                //    (Controlled X) ([qs[0]], qs[2]);
                //    CNOT(qs[2], qs[0]);
                //}

                X(qs[0]);
                for (i in 1..ways-1) {
                    CNOT(qs[i], qs[0]);
                }
            }
        }
    }

    operation Go() : (Int) {
        body {
            let count = 2;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                Solve(qs);
                DumpMachine("dump.txt");

                ResetAll(qs);
            }
            return 0;
        }
    }
}