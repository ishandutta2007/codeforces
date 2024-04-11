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

operation Solve(x : Qubit[]) : Unit {
  body (...) {
    let n = Length(x);
    using (q = Qubit()) {
      mutable res = One;
      repeat {
        Set(x[0], Zero);
        Set(x[1], Zero);
        Set(q, Zero);
        H(x[0]);
        H(x[1]);
        Controlled X(x, q);
        set res = M(q);
      } until (res == Zero) fixup {
      }
      Set(q, Zero);
    }
  }
}

operation Go() : (Int) {
  body (...) {
    let count = 2;
    using (qs = Qubit[count]) {
      ResetAll(qs);

      //X(qs[0]);
      //X(qs[1]);
      //X(qs[2]);
      //X(qs[3]);
      //X(qs[4]);

      Solve(qs);

      DumpMachine("dump.txt");

      ResetAll(qs);
    }
    return 0;
  }
}

}