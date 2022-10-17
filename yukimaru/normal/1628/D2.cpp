#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int Mod=1000000007;
inline int fp(int a,int k)
{
    if(k<0)a=fp(a,Mod-2),k=-k;
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int fac[MAXN],inv[MAXN];
int C(int n,int k)
{
    return 1LL*fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
int cal(int n,int m)
{
    int res=C(n,m);
    for(int i=1;i<=m;i++)
        res=(res+1LL*(i+3)*fp(2,i-2)%Mod*C(n-i,m-i))%Mod;
    return res;
}
int solve()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int res=1LL*cal(n,m-1)*fp(2,-(n-1))%Mod*k%Mod;
    return 0*printf("%d\n",res);
}
void build()
{
    for(int i=(fac[0]=1);i<MAXN;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    for(int i=0;i<MAXN;i++)
        inv[i]=fp(fac[i],-1);
}
int main()
{
    build();
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}