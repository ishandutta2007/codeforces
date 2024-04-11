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

    operation Solve(qs : Qubit[], bits : Bool[]) : () {
        body {
            mutable first = true;
            mutable fi = 0;
            for (i in 0..Length(qs)-1) {
                if (bits[i]) {
                    if (first) {
                        H(qs[i]);
                        set first = false;
                        set fi = i;
                    } else {
                        CNOT(qs[fi], qs[i]);
                    }
                }
            }
        }
    }

    operation Go() : (Int) {
        body {
            let count = 3;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                Solve(qs, [false; true; true]);
                DumpMachine("dump.txt");

                ResetAll(qs);
            }
            return 0;
        }
    }
}