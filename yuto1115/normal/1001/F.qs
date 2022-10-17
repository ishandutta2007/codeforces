namespace Solution {
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Convert;

    operation Solve (qs : Qubit[], bits0 : Bool[], bits1 : Bool[]) : Int {
        let n = Length(qs);
        for(i in 0..n-1) {
            let res = M(qs[i]);
            if(ResultAsBool(res) != bits0[i]) {
                return 1;
            } 
            if(ResultAsBool(res) != bits1[i]) {
                return 0;
            }
        }
        return -1;
    }
}