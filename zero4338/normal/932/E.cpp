#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int maxn=5e3+5;
int n,k;
int ans;
int qpow(int a,int b)
{
    int ret=1;
    for(;b;b>>=1)
    {
        if(b&1)ret=(ll)ret*a%mod;
        a=(ll)a*a%mod;
    }
    return ret;
}
int fac[maxn],inv[maxn],ppow[maxn];
void prework()
{
    int mx=min(n,k);
    fac[0]=1;
    for(int i=1;i<=mx;i++)fac[i]=(ll)fac[i-1]*i%mod;
    inv[mx]=qpow(fac[mx],mod-2);
    for(int i=mx-1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
    for(int i=1;i<=k;i++)ppow[i]=qpow(i,k);
}
int C(int n,int m){return (ll)fac[n]*inv[n-m]%mod*inv[m]%mod;}
int main()
{
    scanf("%d%d",&n,&k);
    prework();
    if(n<k)
    {
        for(int i=1;i<=n;i++)ans=((ll)ans+(ll)C(n,i)*qpow(i,k))%mod;
        printf("%d",ans);return 0;
    }
    int nmul=1,npow=qpow(2,n);
    for(int i=0;i<=k;i++)
    {
        int tmp=0;
        for(int j=1;j<=i;j++)
        {
            if((i-j)&1)tmp=((ll)tmp-(ll)ppow[j]*inv[i-j]%mod*inv[j]%mod+mod)%mod;
            else tmp=((ll)tmp+(ll)ppow[j]*inv[i-j]%mod*inv[j]%mod)%mod;
        }
        ans=((ll)ans+(ll)nmul*npow%mod*tmp%mod)%mod;
        nmul=(ll)nmul*(n-i)%mod;npow=(ll)npow*500000004%mod;
    }
    printf("%d",ans);
    return 0;
}