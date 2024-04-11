#include <bits/stdc++.h>
using namespace std;
long long MOD=1000000007;
long long hat[300009];
vector<long long> t;
long long ans=0;
int main()
{
    ios::sync_with_stdio(false);
    long long n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        long long aa;
        cin>>aa;
        t.push_back(aa);
    }
    sort(t.begin(), t.end());
    hat[0]=1;
    for(long long i=1; i<=300008; i++)
    {
        hat[i]=2*hat[i-1];
        hat[i]%=MOD;
    }
    for(long long i=0; i<t.size(); i++)
    {
        ans+=hat[i]*t[i];
        ans%=MOD;
        long long minusz=hat[n-i-1]*t[i];
        minusz%=MOD;
        ans=ans+MOD-minusz;
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}