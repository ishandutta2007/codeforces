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

    if (n == 1) {
      X(x[0]);
      Controlled X(x, y);
      X(x[0]);
    }
    if (n == 2) {
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
    }
    if (n == 3) {
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[2]);
    }
    if (n == 4) {
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
    }
    if (n == 5) {
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
    }
    if (n == 6) {
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[5]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[5]);
    }
    if (n == 7) {
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[5]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[6]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[5]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[6]);
    }
    if (n == 8) {
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[5]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[4]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[5]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[4]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[7]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[5]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[6]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[5]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[4]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[7]);
    }
    if (n == 9) {
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[5]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[6]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[5]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[7]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[5]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[6]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[5]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[8]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[5]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[6]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[5]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[7]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[5]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[6]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      Controlled X(x, y);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[5]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      X(x[1]);
      Controlled X(x, y);
      X(x[0]);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[4]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[3]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      Controlled X(x, y);
      X(x[2]);
      X(x[0]);
      Controlled X(x, y);
      X(x[1]);
      X(x[0]);
      X(x[8]);
    }


  }
  adjoint auto;
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

      Solve(qs[0..count-2], qs[count-1]);

      DumpMachine("dump.txt");

      ResetAll(qs);
    }
    return 0;
  }
}

}