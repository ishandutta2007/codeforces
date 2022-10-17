#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int Mod=998244353;
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
inline int C(int n,int k)
{
    if(k<0 || n<k)return 0;
    return 1LL*fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
int main()
{
    for(int i=(fac[0]=1);i<MAXN;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    for(int i=0;i<MAXN;i++)
        inv[i]=fp(fac[i],Mod-2);
    int n,cb=0,cw=0;
    scanf("%d",&n);
    map<string,int> cnt;
    for(int i=1;i<=n;i++)
    {
        static char buf[5];
        scanf("%s",buf);
        cnt[buf]++;
        for(int j=0;buf[j];j++)
        {
            cb+=(buf[j]=='B');
            cw+=(buf[j]=='W');
        }
    }
    if(cb>n || cw>n)return 0*printf("0\n");
    int res=C(2*n-cb-cw,n-cw);
    if(cnt["WW"]==0 && cnt["BB"]==0)
    {
        res=(res+Mod-fp(2,cnt["??"]))%Mod;
        if(cnt["BW"]==0 && cnt["B?"]==0 && cnt["?W"]==0)res=(res+1)%Mod;
        if(cnt["WB"]==0 && cnt["W?"]==0 && cnt["?B"]==0)res=(res+1)%Mod;
    }
    return 0*printf("%d\n",res);
}