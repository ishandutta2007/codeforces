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

operation Solve2(x : Qubit[]) : Unit {
  body (...) {
    let n = Length(x);
    X(x[0]);
    CCNOT(x[0], x[1], x[2]);
    CCNOT(x[0], x[2], x[1]);
    CCNOT(x[0], x[1], x[2]);
    X(x[0]);

    CNOT(x[1], x[2]);
    X(x[2]);
    Controlled H([x[2]], x[1]);
    X(x[2]);
    CNOT(x[1], x[2]);

    for (i in 0..n-2) {
      CNOT(x[n-1], x[i]);
    }
    H(x[n-1]);
    for (i in 0..n-2) {
      CNOT(x[n-1], x[i]);
    }
  }
  adjoint auto;
}

operation Solve(x : Qubit[]) : Unit {
  body (...) {
    Adjoint Solve2(x);
  }
  adjoint auto;
}

operation DumpUnitaryToFiles (N : Int, unitary : (Qubit[] => Unit)) : Unit {
  let size = 1 <<< N;

  using (qs = Qubit[N]) {
    for (k in 0 .. size - 1) {
      // Prepare k-th basis vector
      let binary = BoolArrFromPositiveInt(k, N);

      //Message($"{k}/{N} = {binary}");
      // binary is little-endian notation, so the second vector tried has qubit 0 in state 1 and the rest in state 0
      ApplyPauliFromBitString(PauliX, true, binary, qs);

      // Apply the operation
      unitary(qs);

      // Dump the contents of the k-th column
      DumpMachine($"DU_{N}_{k}.txt");

      ResetAll(qs);
    }
  }
}

operation Go() : (Int) {
  body (...) {
    DumpUnitaryToFiles(3, Solve);
//    let count = 2;
//    using (qs = Qubit[count]) {
//      ResetAll(qs);
//
//      X(qs[0]);
//      //X(qs[1]);
//      //X(qs[2]);
//
//      Solve(qs[0..count-2], qs[count-1]);
//
//      DumpMachine("dump.txt");
//
//      ResetAll(qs);
//    }
    return 0;
  }
}

}