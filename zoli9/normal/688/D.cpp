#include <bits/stdc++.h>
using namespace std;
long long GCD(long long u, long long v) {
    while ( v != 0) {
        long long r = u % v;
        u = v;
        v = r;
    }
    return u;
}
long long LCM(long long x, long long y)
{
    long long ans=x*y;
    ans/=GCD(x, y);
    return ans;
}
int n;
long long k;
long long t[1000009];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    long long MOD=t[1];
    for(int i=2; i<=n; i++)
    {
        MOD=LCM(MOD, t[i]);
        MOD=GCD(MOD, k);
    }
    if(MOD%k==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}