#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 55
#define reg register
#define inl inline
using namespace std;
int n,Mod,val[MAXM],a[MAXN],b[MAXN],tot1,tot2,lim,ans;
void Dfs1(reg int s,reg int sum)
{
    if(s>lim)
    {
        a[++tot1]=sum;
        return;
    }
    Dfs1(s+1,sum);
    Dfs1(s+1,(sum+val[s])%Mod);
}
void Dfs2(reg int s,reg int sum)
{
    if(s>n)
    {
        b[++tot2]=sum;
        return;
    }
    Dfs2(s+1,sum);
    Dfs2(s+1,(sum+val[s])%Mod);
}
int main()
{
    scanf("%d %d",&n,&Mod);
    for(reg int i=1;i<=n;i++) scanf("%d",&val[i]);
    if(n==1) return printf("%d\n",val[1]%Mod),0;
    lim=n/2;
    Dfs1(1,0);
    Dfs2(lim+1,0);
    sort(a+1,a+tot1+1);
    sort(b+1,b+tot2+1);
    reg int i=0,j=tot2;
    while(i<=tot1)
    {//
        while(a[i]+b[j]>=Mod) j--;
        ans=max(ans,a[i]+b[j]);
        i++;
    }
    ans=max(ans,a[tot1]+b[tot2]-Mod);
    printf("%d\n",ans);
    return 0;
}