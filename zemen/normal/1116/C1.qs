namespace Solution {

open Microsoft.Quantum.Canon;
open Microsoft.Quantum.Primitive;
open Microsoft.Quantum.Extensions.Diagnostics;

operation Set(q : Qubit, val : Result) : Unit {
  body (...) {
    let res = M(q);
    if (res != val) {
      X(q);
    }
  }
}

operation Solve(x : Qubit[], y : Qubit) : Unit {
  body (...) {
    let n = Length(x);
    for (i in 1..2..n-1) {
      X(x[i]);
    }

    Controlled X(x, y);
    for (i in 0..n-1) {
      X(x[i]);
    }
    Controlled X(x, y);

    for (i in 0..2..n-1) {
      X(x[i]);
    }
  }
  adjoint auto;
}

operation Go() : (Int) {
  body (...) {
    let count = 3;
    using (qs = Qubit[count]) {
      ResetAll(qs);

      X(qs[0]);
      X(qs[1]);
      //X(qs[2]);

      Solve(qs[0..count-2], qs[count-1]);

      DumpMachine("dump.txt");

      ResetAll(qs);
    }
    return 0;
  }
}

}