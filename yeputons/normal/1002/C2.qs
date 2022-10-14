namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;
    open Microsoft.Quantum.Extensions.Math;
    open Microsoft.Quantum.Extensions.Diagnostics;

    operation Solve (q : Qubit) : Int
    {
        body
        {
            mutable result = -1;
            let angs1 = [1.0 - 1.0 / 3.0; 1.0 - 1.0 / 9.0];
            let angs2 = [1.0 - 1.0 / 5.0; 1.0 - 1.0 / 17.0];
            using (qs = Qubit[1])
            {
                for (i in 0..1)
                {
                    if (result == -1)
                    {
                        //DumpMachine("");
                        (Controlled H)([q], qs[0]);
                        if (M(qs[0]) == One)
                        {
                            set result = 1;
                            X(qs[0]);
                        }
                        else
                        {
                            //DumpMachine("");
                            Ry(-2.0 * ArcCos(Sqrt(angs1[i])), q);
                            (Controlled H)([q], qs[0]);
                            if (M(qs[0]) == One)
                            {
                                set result = 0;
                                X(qs[0]);
                            }
                            else
                            {
                                //DumpMachine("");
                                Ry(2.0 * ArcCos(Sqrt(angs2[i])), q);
                            }
                        }
                    }
                }
            }
            //DumpMachine("");
            return result;
        }
    }
}