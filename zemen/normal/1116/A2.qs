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

operation Solve(x : Qubit[], bits : Bool[][]) : Unit {
  body (...) {
    let n = Length(x);
    using (q = Qubit[2]) {
      H(q[0]);
      H(q[1]);
      X(q[0]);
      X(q[1]);

      for (i in 0..3) {
        for (j in 0..n-1) {
          if (bits[i][j]) {
            Controlled X(q, x[j]);
          }
        }
        X(q[0]);
        if (i == 1 || i == 3) {
          X(q[1]);
        }
      }

      for (i in 0..3) {
        for (j in 0..n-1) {
          if (not bits[i][j]) {
            X(x[j]);
          }
        }
        if (i == 0 || i == 2) {
          Controlled X(x, q[0]);
        }
        if (i == 0 || i == 1) {
          Controlled X(x, q[1]);
        }
        for (j in 0..n-1) {
          if (not bits[i][j]) {
            X(x[j]);
          }
        }
      }

      let r0 = M(q[0]);
      let r1 = M(q[1]);
      if (r0 == One || r1 == One) {
        fail "SOS";
      }

      ResetAll(q);
    }
  }
}

operation Go() : (Int) {
  body (...) {
    let count = 3;
    mutable bits = new Bool[][4];
    for (i in 0..3) {
      set bits[i] = new Bool[count];
    }
    set bits[0][0] = false;
    set bits[0][1] = false;
    set bits[0][2] = true;
    set bits[1][0] = true;
    set bits[1][1] = false;
    set bits[2][0] = false;
    set bits[2][1] = true;
    set bits[3][0] = true;
    set bits[3][1] = true;
    using (qs = Qubit[count]) {
      ResetAll(qs);

      //X(qs[0]);
      //X(qs[1]);
      //X(qs[2]);
      //X(qs[3]);
      //X(qs[4]);

      Solve(qs, bits);

      DumpMachine("dump.txt");

      ResetAll(qs);
    }
    return 0;
  }
}

}