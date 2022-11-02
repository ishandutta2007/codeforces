namespace Solution{  
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    operation Solve(q : Qubit) : Int {
        // ...
        mutable count = 0;
        let rnd = RandomInt(2);
        if(rnd == 0){
            if(M(q) == One){
                set count = 1;
            }else{
                set count = -1;
            }
        }else{
            H(q);
            if(M(q) == One){
                set count = 0;
            }else{
                set count = -1;
            }
        }
        return count;
    }
}