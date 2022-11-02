#include<bits/stdc++.h>
#define maxn 400050
using namespace std;
typedef long long LL;

int n,m,q;
int p[maxn];

vector<int> G[maxn],D[maxn];

queue<int> Q;

bool vis[maxn];
int dis[maxn];

void dij(int s,int t)  {
    for (int i=1;i<=n;++i) vis[i]=0;
    vis[t]=1,Q.push(t);
    while (!Q.empty())  {
        int i=Q.front(); Q.pop();
        // cout<<i<<":"<<dis[i]<<endl;
        for (int j:D[i])    {
            if (vis[j]) continue;
            dis[j]=dis[i]+1;
            vis[j]=1,Q.push(j);
        }
    }
    assert(vis[s]);
}

int mn[maxn],mx[maxn];

int main()  {
    scanf("%d%d",&n,&m);
    while (m--) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        D[v].push_back(u);
    }

    scanf("%d",&q);
    for (int i=1;i<=q;++i)
        scanf("%d",p+i);
    dij(p[1],p[q]);

    mn[q]=mx[q]=0;
    for (int i=q-1;i;--i) {
        int cnt=0,disk=-1;
        for (int j:G[p[i]]) {
            if (j==p[i+1])
                disk=dis[j]+1;
            if (dis[p[i]]==dis[j]+1)
                ++cnt;
        }


        assert(disk!=-1);
        if (disk==dis[p[i]])
            mn[i]=mn[i+1];
        else
            mn[i]=mn[i+1]+1;

        assert(cnt>0);
        if (cnt>1||dis[p[i]]<disk)
            mx[i]=mx[i+1]+1;
        else
            mx[i]=mx[i+1];

        // cout<<i<<" "<<disk<<" "<<cnt<<":"<<mn[i]<<" "<<mx[i]<<endl;
    }
    printf("%d %d\n",mn[1],mx[1]);
    return 0;
}