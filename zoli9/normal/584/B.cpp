#include <bits/stdc++.h>
using namespace std;
long long n;
long long MOD=1000000007;
long long a;
long long b;
long long c;
int main()
{
    cin>>n;
    a=1;
    for(int i=1; i<=n; i++)
    {
        a*=27;
        a%=MOD;
    }
    b=1;
    for(int i=1; i<=n; i++)
    {
        b*=7;
        b%=MOD;
    }
    c=a;
    c+=MOD;
    c-=b;
    c%=MOD;
    cout<<c;
    return 0;
}