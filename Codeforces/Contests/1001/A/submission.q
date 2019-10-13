namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (q : Qubit, sign : Int) : ()
    {
        body
        {
            // your code here
            if(sign ==1)
            {
                H(q);
            }
            else
            {
                H(q);
                Z(q);
            }
        }
    }
}

// Submission Link: https://codeforces.com/contest/1001/submission/39784873
