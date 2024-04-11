namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation Findfirstdiff(bits0 : Bool[], bits1 : Bool[]) : Int{
        for (i in 0..Length(bits0)-1)
        {
            if(bits0[i] != bits1[i]){
                return i;
            }
        }
        return -1;
    }
    

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Unit {
        let pos = Findfirstdiff(bits0, bits1);
        H(qs[pos]);
        for (i in 0..Length(qs)-1)
        {
            if(i != pos){
                if(bits0[i] == bits1[i]){
                    if(bits0[i]){
                        X(qs[i]);
                    }
                }else{
                    CNOT(qs[pos], qs[i]);
                    if(bits0[i] != bits0[pos]){
                        X(qs[i]);
                    }
                } 
            }
        }
    }
}