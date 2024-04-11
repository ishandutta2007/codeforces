#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m,a[N],b[N],vis[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        fill(vis+1,vis+100+1,0);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)   
            scanf("%d",&a[i]),vis[a[i]]++;
        int ans=0;
        for(int i=1;i<=m;i++)
            scanf("%d",&b[i]),ans+=vis[b[i]];
        printf("%d\n",ans);
    }
}