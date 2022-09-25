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

    operation Solve(qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        body {
            for (i in 0..Length(qs)-1) {
                if (bits0[i] != bits1[i]) {
                    let res = M(qs[i]);
                    if ((res == One) == bits0[i]) {
                        return 0;
                    } else {
                        return 1;
                    }
                }
            }
            return -1;
        }
    }

    operation Go() : (Int) {
        body {
            let count = 3;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                X(qs[1]);

                let res = Solve(qs, [false; false; false], [false; true; false]);
                Message($"res: {res}");
                DumpMachine("dump.txt");

                ResetAll(qs);
            }
            return 0;
        }
    }
}