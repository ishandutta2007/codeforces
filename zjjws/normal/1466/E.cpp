#include <stdio.h>
#include <string.h>
#define LL long long
using namespace std;
const int mod=1e9+7;
const int N=5e5+3;
const int M=63;
const int lim=60;
inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}


LL a[N];
int n;


int Alpha[M];
int Beta[N];
inline void work()
{
    memset(Beta,0,sizeof(Beta));
    n=rin();
    for(int i=1;i<=n;i++)a[i]=rin();    
    for(int i=1;i<=n;i++)for(int j=0;j<=lim;j++)if(a[i]&(1ll<<j))Beta[j]++;

    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(Alpha,0,sizeof(Alpha));
        for(int j=0;j<=lim;j++)if(a[i]&(1LL<<j))Alpha[j]++;
        LL Gyq=0,Zjj=0;
        for(int j=0;j<=lim;j++)if(Alpha[j])Zjj=(Zjj+((1ll<<j)%mod*Beta[j])%mod)%mod;
        for(int j=0;j<=lim;j++)
        {
            if(Alpha[j]){Gyq=(Gyq+((1ll<<j)%mod*n)%mod)%mod;}
            else Gyq=(Gyq+((1ll<<j)%mod*Beta[j])%mod)%mod;
        }
        ans+=Gyq*Zjj%mod;ans%=mod;
    }
    printf("%lld\n",(ans+mod)%mod);
    return;
}

int main()
{
    int i,j;
    for(int T=rin();T;T--)work();
    return 0;
}