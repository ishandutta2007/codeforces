#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long MOD=1000000007;
long long aaa, bbb;
long long nhat[1000009];
long long mpow[1000009];
long long modinv(long long szam)
{
    long long hatvany=MOD-2;
    long long A=szam;
    long long res=1;
    while(hatvany>0)
    {
        if(hatvany%2)
        {
            res*=A;
            res%=MOD;
        }
        A*=A;
        A%=MOD;
        hatvany/=2;
    }
    return res;
}
long long fact[1000009];
long long factinv[1000009];
long long nck[1000009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>aaa>>bbb;
    fact[0]=1;
    factinv[0]=1;
    mpow[0]=1;
    for(long long i=1; i<=max(n, m)+2; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        factinv[i]=(factinv[i-1]*modinv(i))%MOD;
        mpow[i]=(mpow[i-1]*m)%MOD;
    }
    nhat[0]=1;
    for(int i=1; i<=n+2; i++)
    {
        nhat[i]=(nhat[i-1]*n)%MOD;
    }
    nck[0]=1;
    for(int i=1; i<m; i++)
    {
        nck[i]=(fact[m-1]*factinv[i])%MOD;
        nck[i]=(nck[i]*factinv[m-i-1])%MOD;
    }
    long long ans=(nck[n-2]*fact[n-2])%MOD;
    for(long long l=2; l<n; l++)
    {
        long long crt=(l*nhat[n-l-1])%MOD;
        crt=(crt*mpow[n-l])%MOD;
        crt=(crt*nck[l-2])%MOD;
        crt=(crt*fact[n-2])%MOD;
        crt=(crt*factinv[n-l])%MOD;
        ans=(ans+crt)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}