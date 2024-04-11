#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include <iostream>
using namespace std;

const int maxn = 200 + 10;
const int INF = 1000000000;

struct Edge {
    int from, to, cap, flow;
};

bool operator < (const Edge& a, const Edge& b) {
    return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct ISAP {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];   // G[i][j]ije
    bool vis[maxn];        // BFS
    int d[maxn];           // i
    int cur[maxn];        // 
    int p[maxn];          // 
    int num[maxn];        // 

    void AddEdge(int from, int to, int cap) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(t);
        vis[t] = 1;
        d[t] = 0;
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]^1];
                if(!vis[e.from] && e.cap > e.flow) {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }

    void ClearAll(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void ClearFlow() {
        for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
    }

    int Augment() {
        int x = t, a = INF;
        while(x != s) {
            Edge& e = edges[p[x]];
            a = min(a, e.cap-e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while(x != s) {
            edges[p[x]].flow += a;
            edges[p[x]^1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }

    int Maxflow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        BFS();
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++) num[d[i]]++;
        int x = s;
        memset(cur, 0, sizeof(cur));
        while(d[s] < n) {
            if(x == t) {
                flow += Augment();
                //if(flow >= need) return flow;
                x = s;
            }
            int ok = 0;
            for(int i = cur[x]; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if(e.cap > e.flow && d[x] == d[e.to] + 1) { // Advance
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i; // 
                    x = e.to;
                    break;
                }
            }
            if(!ok) { // Retreat
                int m = n-1; // 
                for(int i = 0; i < G[x].size(); i++) {
                    Edge& e = edges[G[x][i]];
                    if(e.cap > e.flow) m = min(m, d[e.to]);
                }
                if(--num[d[x]] == 0) break;
                num[d[x] = m+1]++;
                cur[x] = 0; // 
                if(x != s) x = edges[p[x]].from;
            }
        }
        return flow;
    }

    vector<int> Mincut() { // call this after maxflow
        BFS();
        vector<int> ans;
        for(int i = 0; i < edges.size(); i++) {
            Edge& e = edges[i];
            if(!vis[e.from] && vis[e.to] && e.cap > 0) ans.push_back(i);
        }
        return ans;
    }

    void Reduce() {
        for(int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
    }

    void print() {
        printf("Graph:\n");
        for(int i = 0; i < edges.size(); i++)
            printf("%d->%d, %d, %d\n", edges[i].from, edges[i].to , edges[i].cap, edges[i].flow);
    }
};


ISAP g;

vector<int> G[maxn];
bool vis[maxn];
int a[maxn];

bool is_prime[20005];

void pre(){
    memset(is_prime,true,sizeof(is_prime));
    is_prime[1] = false;
    for(int i = 2;i < 20005;i++) if(is_prime[i]){
        for(int j = 2 * i;j < 20005;j += i){
            is_prime[j] = false;
        }
    }
}

vector<int> ans[maxn];

void dfs(int u,int fa,int id){
    ans[id].push_back(u);
    vis[u] = true;
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(vis[v] || v == fa) continue;
        dfs(v,u,id);
    }
}


int main(){
    int n;
    pre();
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
    }
    g.ClearAll(n + 2);
    int odd = 0,even = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] % 2){
            odd++;
            g.AddEdge(0, i, 2);
        }else{
            even++;
            g.AddEdge(i, n + 1, 2);
        }
    }
    if(odd != even){
        printf("Impossible\n");
        return 0;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(is_prime[a[i] + a[j]]){
                if(a[i] % 2){
                    g.AddEdge(i, j, 1);
                }else{
                    g.AddEdge(j, i, 1);
                }
            }
        }
    }
    int f = g.Maxflow(0, n + 1);
    //cout << f << endl;
    if(f == 2 * odd){
        for(int i = 0;i < g.edges.size();i++){
            Edge e = g.edges[i];
            if(e.cap == 1 && e.flow == 1){
                int u = e.from;
                int v = e.to;
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
    }else{
        printf("Impossible\n");
        return 0;
    }
    memset(vis,false,sizeof(vis));
    int now = 0;
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs(i,-1,++now);
        }
    }
    cout << now << endl;
    for(int i = 1;i <= now;i++){
        cout << ans[i].size();
        for(int j = 0;j < ans[i].size();j++){
            cout << " " << ans[i][j] << " ";
        }
        //cout << endl;
    }
    return 0;
}