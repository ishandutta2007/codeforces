namespace Solution{
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int {
        // ...
        H(qs[1]);
        CNOT(qs[0], qs[1]);
        H(qs[0]);
        mutable m1 = 0;
        mutable m2 = 0;
        if(M(qs[0]) == Zero){
            set m1 = m1 + 1;
        }
        if(M(qs[1]) == Zero){
            set m2 = m2 + 1;
        }
        return m2 * 2 + m1;
    }
}