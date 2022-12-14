namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Math;
    open Microsoft.Quantum.Measurement;
    open Microsoft.Quantum.MachineLearning;
    open Microsoft.Quantum.Arithmetic;
    open Microsoft.Quantum.Convert;
    
    operation RunQsharp () : Bool {
        return true;
    }
    
    operation Set(desired : Result, q1 : Qubit) : Unit {
        if (desired != M(q1)) {
            X(q1);
        }
    }
    
    operation MyQFT (qs : Qubit[]) : Unit is Adj+Ctl {
        QFTLE(LittleEndian(qs));
    }
    
    operation HelpQFT (anc : Qubit[], inputRegister : LittleEndian) : Unit is Adj+Ctl {
        H(anc[0]);
        H(anc[1]);
        Controlled MyQFT([anc[0]], inputRegister!);
        for (i in 0 .. Length(inputRegister!) - 1) {
            CNOT(anc[1],inputRegister![i]);
        }
        Controlled IncrementByInteger([anc[1]],(1, inputRegister));
        Adjoint MyQFT(anc);
    }
    
    operation FQFT(theta : Double, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        using(anc = Qubit[2]) {
            HelpQFT(anc, inputRegister);
            R1(theta, anc[0]);
            R1(theta*2.0, anc[1]);
            Adjoint HelpQFT(anc, inputRegister);
        }
    }
    
    operation Solve (p : Int, inputRegister : LittleEndian) : Unit is Adj+Ctl {
        FQFT((PI() / 2.0) / IntAsDouble(p), inputRegister);
    }
}