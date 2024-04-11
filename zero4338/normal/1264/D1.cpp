#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=2e3+5;
const int mod=998244353;
int n;
int ans;
char s[maxn];
int pl[maxn],sr[maxn],pq[maxn],sq[maxn];
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
int fac[maxn],inv[maxn];
void prework()
{
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
    inv[n]=qpow(fac[n],mod-2);
    for(int i=n-1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
}
int C(int n,int m){if(n<m||n<0||m<0)return 0;return (ll)fac[n]*inv[n-m]%mod*inv[m]%mod;}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);prework();
    for(int i=1;i<=n;i++)
    {
        pl[i]=pl[i-1];pq[i]=pq[i-1];
        if(s[i]=='(')pl[i]++;
        else if(s[i]=='?')pq[i]++;
    }
    for(int i=n;i>=1;i--)
    {
        sr[i]=sr[i+1];sq[i]=sq[i+1];
        if(s[i]==')')sr[i]++;
        else if(s[i]=='?')sq[i]++;
    }
    for(int i=1;i<=n-1;i++)ans=((ll)ans+(ll)pl[i]*C(pq[i]+sq[i+1],sq[i+1]+sr[i+1]-pl[i])%mod+(ll)pq[i]*C(pq[i]+sq[i+1]-1,sr[i+1]+sq[i+1]-pl[i]-1)%mod)%mod;
    printf("%d",ans);
    return 0;
}