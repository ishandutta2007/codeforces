#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000010;//
const int maxm = 2000010;
const int N=2e6+1e3+7;
int n, m, edgecnt, head[maxn];
struct edge{int v, nxt; } E[maxm*2];
struct link{int pre, nxt; }L[maxn];
void del(int x){
    L[L[x].pre].nxt = L[x].nxt;
    L[L[x].nxt].pre = L[x].pre;
}
void init(){
    memset(head, -1, sizeof(head));
    edgecnt = 0;
}
void addedge(int u, int v){
    E[edgecnt].v = v, E[edgecnt].nxt = head[u], head[u] = edgecnt++;
}
bool vis1[maxn], vis2[maxn]; //vis1vis2
int scc[maxn], scccnt;

vector<int>v[N];

int fa[N];

void bfs(){
    queue <int> q;
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    while(L[0].nxt){//
        int now = L[0].nxt, curscc = 1;
        del(now);
        q.push(now);
        vis2[now] = 1;
        ++scccnt;
        v[scccnt].push_back(now);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = E[i].nxt) vis1[E[i].v] = 1;
            for(int i = L[0].nxt; i; i = L[i].nxt){
                if(!vis1[i] && !vis2[i]){
                    vis2[i] = 1;
                    q.push(i);
                    curscc++;
                    v[scccnt].push_back(i);
                    del(i);
                }
            }
            for(int i = head[u]; ~i; i = E[i].nxt) vis1[E[i].v] = 0; //
        }
        scc[scccnt] = curscc;
    }
}
struct EE{
    int u,v,w;
}e[N*2+1];

bool cmp(EE a,EE b)
{
    return a.w<b.w;
}

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int g[1001][1001];

int main(){
    init();
    scanf("%d%d", &n, &m);
    int s=0;
    for(int i = 1; i <= m; i++){
        int u, v,w;
        scanf("%d%d%d", &u, &v,&w);
        s^=w;
        e[i].u=u,e[i].v=v,e[i].w=w;
        addedge(u, v);
        addedge(v, u);
    }
    sort(e+1,e+m+1,cmp);
    for(int i = 1; i <= n; i++){
        L[i-1].nxt = i; L[i].pre = i - 1;
    } L[n].nxt = 0;
    bfs();
    for(int i=1;i<=n;i++)
        fa[i]=i;
    long long totm=1ll*n*(n-1)/2-m;
    if(n-scccnt==totm)
    {
        assert(n<=1000);
        int tm=m;
        for(int i=1;i<=m;i++)
            g[e[i].u][e[i].v]=g[e[i].v][e[i].u]=1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(!g[i][j])
                {
                    if(i==j)
                        continue;
                    e[++tm]=EE{i,j,0};
                }
        sort(e+1,e+tm+1,cmp);
        assert(tm==1ll*n*(n-1)/2);
        long long ans=1e18;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(!g[i][j])
                {
                    if(i==j)
                        continue;
                    int x=i,y=j;
                    int use=0;
                    long long tot=0;
                    for(int i=1;i<=n;i++)
                        fa[i]=i;
                    for(int i=1;i<=tm;i++)
                    {
                        if(e[i].u==x&&e[i].v==y)
                            continue;
                        if(e[i].w>s&&!use)
                        {
                            int fx=find(x),fy=find(y);
                            if(fx==fy)
                                continue;
                            tot+=s;
                            use=1;
                            fa[fx]=fy;
                        }
                        int fx=find(e[i].u),fy=find(e[i].v);
                        if(fx==fy)
                            continue;
                        tot+=e[i].w;
                        fa[fx]=fy;
                    }
                    ans=min(ans,tot);
                }
        printf("%lld\n",ans);
    }
    else
    {
        for(int i=1;i<=scccnt;i++)
            for(auto x:v[i])
            {
                int fx=find(v[i][0]),fy=find(x);
                if(fx==fy)
                    continue;
                fa[fx]=fy;
            }
        long long ans=0;
        for(int j=1;j<=m;j++)
        {
            int fu=find(e[j].u),fv=find(e[j].v);
            if(fu==fv)
                continue;
            fa[fu]=fv;
            ans+=e[j].w;
        }
        printf("%lld\n",ans);
    }
    // sort(scc + 1, scc + scccnt + 1);
    // printf("%d\n", scccnt);
    // for(int i = 1; i < scccnt; i++) printf("%d ", scc[i]); printf("%d", scc[scccnt]);
    return 0;
}