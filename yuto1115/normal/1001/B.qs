namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[], index : Int) : Unit {
        if(index == 0) {
            H(qs[0]);
            CNOT(qs[0],qs[1]);
        } elif(index == 1) {
            X(qs[0]);
            H(qs[0]);
            CNOT(qs[0],qs[1]);
        } elif (index == 2) {
            H(qs[0]);
            X(qs[1]);
            CNOT(qs[0],qs[1]);
        } else {
            X(qs[0]);
            H(qs[0]);
            X(qs[1]);
            CNOT(qs[0],qs[1]);
        }
    }
}