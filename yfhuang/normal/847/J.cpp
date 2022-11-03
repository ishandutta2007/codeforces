#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 10005,MAXM = 20100;
const int INF = INT_MAX;
int n,m;
vector<pair<int,int> > e;
struct Dinic {

    struct Edge{
        int from,to,cap,flow,id;
    };
    int n, m, s, t;
    vector < Edge > edges;
    vector < int > G[MAXN];
    bool vis[MAXN];
    int d[MAXN];
    int cur[MAXN];

    void AddEdge(int from, int to, int cap,int id) {
        edges.push_back((Edge) {
                from, to, cap, 0,id
        });
        edges.push_back((Edge) {
                to, from, 0, 0,id
        });
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS() {
        memset(vis, 0, sizeof vis);
        queue < int > Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;

        while(!Q.empty()) {
            int x = Q.front();
            Q.pop();

            for(int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];

                if(!vis[e.to] && e.cap > e.flow) { //
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }

        return vis[t];
    }

    int DFS(int x, int a) {
        if(x == t || a == 0) { // 
            return a;
        }

        int flow = 0, f;

        for(int& i = cur[x]; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];

            if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) { // 
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;// af

                if(a == 0) {//a=0
                    break;
                }
            }
        }

        return flow;
    }

    int Maxflow(int s, int t) {
        this -> s = s;
        this -> t = t;

        int flow = 0;

        while(BFS()) { //  s-t
            memset(cur, 0, sizeof cur); // 
            flow += DFS(s, INF); // 
        }

        return flow;
    }
} dinic;

bool check(vector<pair<int,int> > edge,int cap){
    dinic.n = (n + m + 2);
    dinic.s = 0,dinic.t = n + m + 1;
    dinic.edges.clear();
    for(int i = 0;i < n + m + 2;i++){
        dinic.G[i].clear();
    }
    for(int i = 1;i <= m;i++){
        dinic.AddEdge(0,i,1,-1);
    }
    for(int i = m + 1;i <= m + n;i++){
        dinic.AddEdge(i,n + m + 1,cap,-1);
    }
    for(int i = 0;i < edge.size();i++){
        pair<int,int> p = edge[i];
        dinic.AddEdge(i + 1,p.first + m,1,i + 1);
        dinic.AddEdge(i + 1,p.second + m,1,i + 1);
    }
    return dinic.Maxflow(0,n + m + 1) == m;
}

int f[MAXM];

int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        e.push_back(make_pair(u,v));
        f[i] = u ^ v;
    }

    int l = 0,r = m;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(e,mid)){
           r = mid;
        }else l = mid + 1;
    }
    cout << l << endl;
    check(e,l);
    for(int i = 0;i < dinic.edges.size();i++){
        //cout << dinic.edges[i].from << " " << dinic.edges[i].to << " " << dinic.edges[i].cap << " " << dinic.edges[i].flow << " " << dinic.edges[i].id << endl;
        if(dinic.edges[i].id != -1){
            if(dinic.edges[i].cap > 0 && dinic.edges[i].cap == dinic.edges[i].flow){
                int u = dinic.edges[i].to - m;
                int v = u ^ f[dinic.edges[i].id];
                printf("%d %d\n",u,v);
            }
        }
    }
    return 0;
}