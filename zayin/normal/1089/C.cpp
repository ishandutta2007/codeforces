#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n,m;
vector<int> G[maxn];

bool vis[maxn];
int dis[maxn][maxn];

int main()  {
    scanf("%d%d",&n,&m);
    while (m--) {
        int sz,u,v;
        scanf("%d%d",&sz,&u);
        while (--sz)    {
            scanf("%d",&v);
            G[u].push_back(v);
            G[v].push_back(u);
            u=v;
        }
    }


    memset(dis,-1,sizeof(dis));
    for (int i=1;i<=n;++i)  {
        queue<int> q;
        q.push(i),dis[i][i]=0;
        while (!q.empty())  {
            int k=q.front(); q.pop();
            for (int j:G[k])    {
                if (~dis[i][j]) continue;
                q.push(j),dis[i][j]=dis[i][k]+1;
            }
        }
    }

    for (int t=1;t<=n;++t)  {
        for (int i=1;i<=n;++i) vis[i]=0;

        while (1)   {
            int v,u=0,mn=n*n;
            for (int i=1;i<=n;++i)  {
                if (vis[i]) continue;
                int sum=0;
                for (int j=1;j<=n;++j)
                    if (!vis[j])
                        sum+=dis[i][j];
                if (sum<mn)
                    u=i,mn=sum;
            }

            cout<<u<<endl;
            string s;
            cin>>s;
            if (s=="FOUND") break;
            cin>>v;
            for (int i=1;i<=n;++i)
                if (dis[u][i]<=dis[v][i])
                    vis[i]=1;
            u=v;
        }
    }
    return 0;
}