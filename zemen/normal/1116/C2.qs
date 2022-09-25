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

    for (p in n-1..-1..1) {
      if ((n == 3 && p == 1) || (n == 5 && p == 2) || (n == 6 && p <= 2) || (n == 7 && p == 3)) {
      } else {
        let m = n-p;
        for (i in 0..m-1) {
          CNOT(x[i + p], x[i]);
          X(x[i]);
        }

        Controlled X(x[0..m-1], y);

        for (i in m-1..-1..0) {
          X(x[i]);
          CNOT(x[i + p], x[i]);
        }
      }
    }

    if (n == 5) {
      X(x[0]);
      X(x[1]);
      X(x[3]);
      X(x[4]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[3]);
      X(x[4]);
    }
    if (n == 5) {
      X(x[2]);
      Controlled X(x, y);
      X(x[2]);
    }
    if (n == 6) {
      X(x[0]);
      X(x[1]);
      X(x[3]);
      X(x[4]);
      X(x[5]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[3]);
      X(x[4]);
      X(x[5]);
    }
    if (n == 6) {
      X(x[0]);
      X(x[1]);
      X(x[2]);
      X(x[4]);
      X(x[5]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[2]);
      X(x[4]);
      X(x[5]);
    }
    if (n == 6) {
      X(x[0]);
      X(x[1]);
      X(x[4]);
      X(x[5]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[4]);
      X(x[5]);
    }
    if (n == 6) {
      X(x[0]);
      X(x[2]);
      X(x[3]);
      X(x[5]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[3]);
      X(x[5]);
    }
    if (n == 6) {
      X(x[1]);
      X(x[4]);
      Controlled X(x, y);
      X(x[1]);
      X(x[4]);
    }
    if (n == 6) {
      X(x[2]);
      X(x[3]);
      Controlled X(x, y);
      X(x[2]);
      X(x[3]);
    }
    if (n == 6) {
      X(x[3]);
      Controlled X(x, y);
      X(x[3]);
    }
    if (n == 6) {
      X(x[2]);
      Controlled X(x, y);
      X(x[2]);
    }
    if (n == 7) {
      X(x[0]);
      X(x[1]);
      X(x[3]);
      X(x[4]);
      X(x[5]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[3]);
      X(x[4]);
      X(x[5]);
      X(x[6]);
    }
    if (n == 7) {
      X(x[0]);
      X(x[1]);
      X(x[4]);
      X(x[5]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[4]);
      X(x[5]);
      X(x[6]);
    }
    if (n == 7) {
      X(x[0]);
      X(x[1]);
      X(x[2]);
      X(x[3]);
      X(x[5]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[2]);
      X(x[3]);
      X(x[5]);
      X(x[6]);
    }
    if (n == 7) {
      X(x[0]);
      X(x[1]);
      X(x[3]);
      X(x[5]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[3]);
      X(x[5]);
      X(x[6]);
    }
    if (n == 7) {
      X(x[0]);
      X(x[1]);
      X(x[2]);
      X(x[5]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[2]);
      X(x[5]);
      X(x[6]);
    }
    if (n == 7) {
      X(x[0]);
      X(x[1]);
      X(x[5]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[5]);
      X(x[6]);
    }
    if (n == 7) {
      X(x[0]);
      X(x[2]);
      X(x[3]);
      X(x[4]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[3]);
      X(x[4]);
      X(x[6]);
    }
    if (n == 7) {
      X(x[1]);
      X(x[5]);
      Controlled X(x, y);
      X(x[1]);
      X(x[5]);
    }
    if (n == 7) {
      X(x[2]);
      X(x[3]);
      X(x[4]);
      Controlled X(x, y);
      X(x[2]);
      X(x[3]);
      X(x[4]);
    }
    if (n == 7) {
      X(x[3]);
      X(x[4]);
      Controlled X(x, y);
      X(x[3]);
      X(x[4]);
    }
    if (n == 7) {
      X(x[2]);
      X(x[4]);
      Controlled X(x, y);
      X(x[2]);
      X(x[4]);
    }
    if (n == 7) {
      X(x[4]);
      Controlled X(x, y);
      X(x[4]);
    }
    if (n == 7) {
      X(x[2]);
      X(x[3]);
      Controlled X(x, y);
      X(x[2]);
      X(x[3]);
    }
    if (n == 7) {
      X(x[2]);
      Controlled X(x, y);
      X(x[2]);
    }

  }
  adjoint auto;
}

operation Go() : (Int) {
  body (...) {
    let count = 6;
    using (qs = Qubit[count]) {
      ResetAll(qs);

      //X(qs[0]);
      //X(qs[1]);
      X(qs[2]);
      //X(qs[3]);
      //X(qs[4]);

      Solve(qs[0..count-2], qs[count-1]);

      DumpMachine("dump.txt");

      ResetAll(qs);
    }
    return 0;
  }
}

}