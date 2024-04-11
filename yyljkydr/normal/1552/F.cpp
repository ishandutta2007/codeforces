#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=998244353;

int n,x[N],y[N],t[N];

int f[N],s[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&x[i],&y[i],&t[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int p=lower_bound(x+1,x+i+1,y[i])-x;
        f[i]=(s[i-1]-s[p-1])%P;
        f[i]=(f[i]+x[i]-y[i])%P;
        s[i]=(s[i-1]+f[i])%P;
        if(t[i])
            ans=(ans+f[i])%P;
    }
    ans=(ans+x[n]+1)%P;
    if(ans<0)
        ans+=P;
    printf("%d\n",ans);
}