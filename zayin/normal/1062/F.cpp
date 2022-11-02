#include<bits/stdc++.h>
#define maxn 300050
using namespace std;

int n,m;
int u[maxn],v[maxn];

void init()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;++i)
        scanf("%d%d",&u[i],&v[i]);
}

int d[maxn];
vector<int> G[maxn];

int cnt[maxn];
queue<int> q;

void calc(int u[],int v[])
{
    for (int i=1;i<=n;++i)
        G[i].clear();
    for (int i=0;i<m;++i)
        G[u[i]].push_back(v[i]),++d[v[i]];

    int num=n;
    for (int i=1;i<=n;++i)
        if (!d[i])
            q.push(i),--num;
    while (!q.empty())
    {
        int i=q.front(); q.pop();
        // cout<<"bfs:"<<i<<endl;
        if (q.empty())
            cnt[i]+=num;
        else
        if (q.size()==1)
        {
            int f=1,k=q.front();
            for (auto j:G[k])
                f&=d[j]>1;
            if (f)
                cnt[i]+=num;
        }
        for (auto j:G[i])
            if (--d[j]==0)
                q.push(j),--num;
    }
    // for (int i=1;i<=n;++i)
    //     printf("%d %d\n",i,cnt[i]);
    // cout<<"---------------"<<endl;
}

void solve()
{
    calc(u,v);
    calc(v,u);


    int ans=0;
    for (int i=1;i<=n;++i)
        if (cnt[i]>=n-2)
            ++ans;
    printf("%d\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}