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

    operation Solve(q : Qubit, sign : Int) : () {
        body {
            if (sign == -1) {
                X(q);
            }
            H(q);
        }
    }

    operation Go() : (Int) {
        body {
            using (qs = Qubit[1]) {
                Set(qs[0], Zero);
                Solve(qs[0], -1);
                DumpMachine("dump.txt");
                Set(qs[0], Zero);
            }
            return 0;
        }
    }
}