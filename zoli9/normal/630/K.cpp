#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    long long a, b, c, d, ab, ac, ad, bc, bd, cd, abc, abd, acd, bcd, abcd;
    a=n/2;
    b=n/3;
    c=n/5;
    d=n/7;
    ab=n/(2*3);
    ac=n/(2*5);
    ad=n/(2*7);
    bc=n/(3*5);
    bd=n/(3*7);
    cd=n/(5*7);
    abc=n/(2*3*5);
    abd=n/(2*3*7);
    acd=n/(2*5*7);
    bcd=n/(3*5*7);
    abcd=n/(2*3*5*7);
    cout<<(n-a-b-c-d+ab+ac+ad+bc+bd+cd-abc-abd-acd-bcd+abcd);
    return 0;
}