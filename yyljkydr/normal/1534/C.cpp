#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,P=1e9+7;

int T,n,a[N],b[N],to[N];

int vis[N];

void dfs(int x)
{
    if(vis[x])
        return;
    vis[x]=1;
    dfs(to[x]);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
            to[a[i]]=b[i],vis[i]=0;
        int ans=0;
        for(int i=1;i<=n;i++)
            if(!vis[i])
                dfs(i),ans++;
        int pw=1;
        for(int i=1;i<=ans;i++)
            pw=pw*2%P;
        printf("%d\n",pw);
    }
}