#include<bits/stdc++.h>
using namespace std;
const int MAXN=400005;
const int Mod=1000000007;
inline int fp(int a,int k)
{
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
void init()
{
    for(int i=(fac[0]=1);i<MAXN;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    for(int i=0;i<MAXN;i++)
        inv[i]=fp(fac[i],Mod-2);
}
inline int C(int n,int k)
{
    return 1LL*fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
int solve()
{
    int n,res=0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        res=(res+C(a+i,i+1))%Mod;
    }
    return 0*printf("%d\n",res);
}
int main()
{
    init();
    int T=1;
    while(T--)solve();
    return 0;
}