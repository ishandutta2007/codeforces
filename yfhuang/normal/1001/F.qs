namespace Solution
{
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Primitive;

    operation FindfirstDiff(bits0 : Bool[], bits1: Bool[]) : Int{
        for (i in 0..Length(bits0)-1){
            if(bits0[i] != bits1[i]){
                return i;
            }
        }
        return -1;
    }

    operation Solve(qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        let pos = FindfirstDiff(bits0, bits1);
        let res = M(qs[pos]) == One;
        if(bits0[pos] == res){
            return 0;
        }else{
            return 1;
        }
    }
}