#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int n,m;

vector<pair<int,int> >g[N];

int d[N][2],f[N];

queue<int>q;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        g[v].push_back(make_pair(u,c));
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            d[i][j]=n+1;
    q.push(n);
    d[n][0]=d[n][1]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto [v,c]:g[x])
        {
            if(d[v][c]!=n+1)
                continue;
            d[v][c]=max(d[x][0],d[x][1])+1;
            if(d[v][0]!=n+1&&d[v][1]!=n+1)
                q.push(v);
        }
    }
    int ans=max(d[1][0],d[1][1]);
    printf("%d\n",ans==n+1?-1:ans);
    for(int i=1;i<=n;i++)
        printf("%d",d[i][1]>d[i][0]);
    puts("");
}