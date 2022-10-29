#include <bits/stdc++.h>
using namespace std;

struct DJS {
    static const int N = 100006;
    int p[N];
    void init(int n) {
        for (int i=0;i<=n;++i) p[i]=i;
    }
    int Find(int x) {
        return p[x] ==x?x:p[x]=Find(p[x]);
    }
    void Union(int x,int y) {
        p[Find(x)] = Find(y);
    }
} djs;

struct Edge {
    int a,b,c;
    Edge(int _a,int _b,int _c) {
        a = _a;
        b = _b;
        c = _c;
    }
};

const int N = 100006;
typedef pair<int,int> pii;

vector<pii> G[N];

bool cool[N];
int vis[N];

int main () {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int st=-1;
    for (int i=1;i<=k;++i) {
        int x;
        scanf("%d",&x);
        cool[x] = true;
        st=x;
    }
    vector<Edge> v;
    for (int i=1;i<=m;++i) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        v.push_back(Edge(x,y,z));
    }
    sort(v.begin(),v.end(),[](const Edge &e1,const Edge &e2) {
        return e1.c<e2.c;
    });
    djs.init(n);
    for (Edge e:v) {
        if (djs.Find(e.a) == djs.Find(e.b)) continue;
        djs.Union(e.a,e.b);
        G[e.a].push_back({e.b,e.c});
        G[e.b].push_back({e.a,e.c});
    }
    queue<int> que;
    que.push(st);
    vis[st] = -1;
    int ans=0;
    while (!que.empty()) {
        int t=que.front();
        que.pop();
        if (cool[t]) ans = max(ans,vis[t]);
        for (pii p:G[t]) {
            int to=p.first;
            int w=p.second;
            if (vis[to] == 0) {
                vis[to] = max(vis[t],w);
                que.push(to);
            }
        }
    }
    for (int i=1;i<=k;++i) {
        printf("%d%c",ans," \n"[i==k]);
    }
}