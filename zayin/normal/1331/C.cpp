#include<bits/stdc++.h>
using namespace std;
int main()  {
    vector<int> A;
    int a;
    cin>>a;
    for (int i=0;i<6;++i)
        A.push_back(a>>i&1);
    reverse(A.begin(),A.end());
    printf("%d\n",A[0]*32+A[5]*16+A[3]*8+A[2]*4+A[4]*2+A[1]);
    return 0;
}