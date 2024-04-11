#include<bits/stdc++.h>
#define maxb 18
#define maxn 75
#define maxm 205
using namespace std;

int n,m,a,b;

int tot;
int cost[maxm<<1];
int head[maxn],edge[maxm<<1],nxt[maxm<<1];

void join(int u,int v,int w)    {
    cost[tot]=w; edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
    cost[tot]=w; edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

void init() {
    tot=0;
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d",&n,&m,&a,&b);
    while (m--) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        join(u,v,w);
    }
}

bool vis[maxn];
int Q[maxn],l,r;

int N,bel[maxn];

int G,group[maxn];

int bfs(int v)  {
    ++G;
    Q[l=r=1]=v,vis[v]=1;
    while (l<=r)  {
        int i=Q[l++];
        group[i]=G;
        for (int k=head[i];~k;k=nxt[k]) {
            int j=edge[k];
            if (vis[j]||cost[k]==b) continue;
            Q[++r]=j,vis[j]=1;
        }
    }
    return r;
}

int dis[maxn][1<<maxb];
struct node {
    int v,mark;
    node(int v=0,int mark=0):mark(mark),v(v)   {}
    int val() const {
        return dis[v][mark];
    }
    bool operator < (const node& N) {
        return val()<N.val();
    }
};


bool inq[maxn][1<<maxb];
deque<node> Q1,Q2;

bool Min(int &a,int b)  {
    if (a>b)
        return a=b,1;
    return 0;
}

void solve()    {
    for (int i=1;i<=n;++i)  {
        if (vis[i]) continue;
        int sz=bfs(i);
        // cout<<"bfs:"<<i<<" "<<sz<<endl;
        if (sz<=3)  continue;
        // cout<<N<<":";for (int j=1;j<=r;++j) cout<<Q[j]<<" "; cout<<endl;
        for (int j=1;j<=r;++j)
            bel[Q[j]]=1<<N;
        ++N;
    }

    memset(dis,0x3f,sizeof(dis));
    dis[1][bel[1]]=0;
    Q1.push_front(node(1,bel[1])),inq[1][bel[1]]=1;
    while (!Q1.empty()||!Q2.empty())   {
        node now;
        if (!Q1.size()||(Q2.size()&&Q2.front()<Q1.front()) )
            now=Q2.front(),Q2.pop_front();
        else
            now=Q1.front(),Q1.pop_front();
        // cout<<"now:"<<now.v<<" "<<now.mark<<" "<<now.val()<<endl;
        for (int i=now.v,k=head[i];~k;k=nxt[k]) {
            int j=edge[k];
            // cout<<i<<" -> "<<j<<"("<<bel[j]<<") "<<cost[k]<<endl;
            if (cost[k]==a) {
                assert(bel[i]==bel[j]);
                int nm=now.mark;
                if (Min(dis[j][nm],now.val()+a)&&!inq[j][nm])
                    Q1.push_back(node(j,nm)),inq[j][nm]=1;
            } else  {
                if ((bel[j]&now.mark)||(group[i]==group[j]))    continue;
                int nm=now.mark|bel[j];
                if (Min(dis[j][nm],now.val()+b)&&!inq[j][nm])
                    Q2.push_back(node(j,nm)),inq[j][nm]=1;
            }
            // cout<<"end"<<endl;
        }
    }

    for (int i=1;i<=n;++i)  {
        int res=1<<30;
        for (int s=0;s<(1<<N);++s)
            res=min(res,dis[i][s]);
        printf("%d ",res);
    }
}

int main()  {
    init();
    solve();
    return 0;
}