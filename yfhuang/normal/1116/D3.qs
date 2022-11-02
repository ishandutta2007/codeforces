namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Extensions.Math;
    operation A1 (qs : Qubit[]) : Unit {
        let theta = ArcSin(1.0 / Sqrt(3.0));
        Ry(theta * 2.0, qs[0]);
        (ControlledOnInt(0, H))([qs[0]], qs[1]);
    }

    operation C1 (x : Qubit[], y : Qubit) : Unit {
        body(...){
            let N = Length(x);
            for(i in 1..2..N-1){
                X(x[i]);
            }
            Controlled X(x, y);
            for(i in 0..N-1){
                X(x[i]);
            }
            Controlled X(x, y);
            for(i in 0..2..N-1){
                X(x[i]);
            }
        }
        adjoint auto;
    }
    operation D1 (qs : Qubit[]) : Unit {
        H(qs[0]);
    }
    operation D2 (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for (i in 0..N-1){
            let j = N-1-i;
            X(qs[j]);
            ApplyToEach((ControlledOnInt(0, H))(qs[j..N-1], _), qs[0..j-1]);
            X(qs[j]);
        }
    }
    operation Solve (qs : Qubit[]) : Unit {
        let N = Length(qs);
        for (i in 1..N-1){
            CNOT(qs[0], qs[i]);
        }    
        H(qs[0]);
        for (i in 1..N-1){
            CNOT(qs[0], qs[i]);
        }
    }
}