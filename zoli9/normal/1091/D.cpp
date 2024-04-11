#include <bits/stdc++.h>
using namespace std;
long long MOD=998244353;
long long ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    long long x=1;
    for(long long i=n; i>=2; i--)
    {
        x*=i;
        x%=MOD;
        ans-=x;
        ans+=MOD;
        ans%=MOD;
    }
    x*=n;
    x%=MOD;
    ans+=x;
    ans%=MOD;
cout<<ans<<endl;
    return 0;
}