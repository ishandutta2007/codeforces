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
    for (i in 0..n-2) {
      CNOT(x[n-1], x[i]);
    }
    H(x[n-1]);
    for (i in 0..n-2) {
      CNOT(x[n-1], x[i]);
    }
//    for (i in 0..n-1) {
//      X(x[i]);
//    }
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