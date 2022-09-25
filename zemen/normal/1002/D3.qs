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

    operation Solve(x : Qubit[], y : Qubit) : () {
        body {
          CCNOT(x[0], x[1], y);
          CCNOT(x[1], x[2], y);
          CCNOT(x[0], x[2], y);
        }
    }

    operation Go() : (Int) {
        body {
            let count = 4;
            using (qs = Qubit[count]) {
                ResetAll(qs);

                X(qs[0]);
                X(qs[1]);
                X(qs[2]);

                Solve(qs[0..count-2], qs[count-1]);
                DumpMachine("dump.txt");

                ResetAll(qs);
            }
            return 0;
        }
    }
}