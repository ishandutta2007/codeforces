#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int maxn=1e6+5;
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
int ppow[maxn],fac[maxn],inv[maxn];
int p[maxn],cnt,mp[maxn];
void prework()
{
    fac[0]=1;
    for(int i=1;i<=k+2;i++)fac[i]=(ll)fac[i-1]*i%mod;
    inv[k+2]=qpow(fac[k+2],mod-2);
    for(int i=k+1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
    ppow[1]=1;
    for(int i=2;i<=k+2;i++)
    {
        if(!mp[i])
        {
            mp[i]=i;ppow[i]=qpow(i,k);
            p[++cnt]=i;
        }
        for(int j=1;j<=cnt&&p[j]<=(k+2)/i;j++)
        {
            ppow[i*p[j]]=(ll)ppow[i]*ppow[p[j]]%mod;
            if(i%p[j]==0)break;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    prework();
    for(int i=1;i<=k+2;i++)ppow[i]=(ppow[i]+ppow[i-1])%mod;
    if(n<=k+2)
    {
        printf("%d",ppow[n]);return 0;
    }    
    for(int i=1;i<=k+2;i++)
    {
        if(((k+2-i)&1)==0)ans=((ll)ans+(ll)ppow[i]*qpow(n-i,mod-2)%mod*inv[i-1]%mod*inv[k+2-i]%mod)%mod;
        else ans=((ll)ans-(ll)ppow[i]*qpow(n-i,mod-2)%mod*inv[i-1]%mod*inv[k+2-i]%mod+mod)%mod;
    }
    for(int i=1;i<=k+2;i++)ans=(ll)ans*(n-i)%mod;
    printf("%d",ans);
    return 0;
}