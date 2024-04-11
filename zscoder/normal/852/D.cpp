#include <bits/stdc++.h>
#define ii pair < int, int >
using namespace std;

const int N = 700;
const int S = 200;
const int M = N * S + 100;
const int INF = 1000 * 1000 * 1000;


/*
    Hopcroft Karp Max Matching in O(E * sqrt(V))
    N = Number of Nodes, M = Number of Edges
    n1 = Size of left partite, n2 = Size of right partite
    Nodes are numbered from [0, n1 - 1] and [0, n2 - 1]

    init(n1, n2) declares the two partite sizes and resets arrays
    addEdge(x, y) adds an edge between x in left partite and y in right partite
    maxMatching() returns the maximum matching

    Maximum Matching = Minimum Vertex Cover (Konig's Theorem)
    N - Maximum Matching = Maximal Independent Set
*/


int n1, n2, edges, last[N], previous[M], head[M];
int matching[N], dist[N], Q[N];
bool used[N], vis[N];

inline void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

inline void addEdge(int u, int v) {
    head[edges] = v;
    previous[edges] = last[u];
    last[u] = edges++;
}

inline void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for(int u = 0; u < n1; ++u){
        if(!used[u]){
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for(int i = 0; i < sizeQ; i++){
        int u1 = Q[i];
        for(int e = last[u1]; e >= 0; e = previous[e]){
            int u2 = matching[head[e]];
            if(u2 >= 0 && dist[u2] < 0){
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

inline bool dfs(int u1) {
    vis[u1] = true;
    for(int e = last[u1]; e >= 0; e = previous[e]){
        int v = head[e];
        int u2 = matching[v];
        if(u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)){
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

inline int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for(int res = 0; ;){
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for(int u = 0; u < n1; ++u)
            if(!used[u] && dfs(u))
                ++f;
        if(!f) return res;
        res += f;
    }
}

// End of Hopcroft Karp Template

#define dist sp

int V, E, n, k;
int dist[N][N];
int par[N][N];
int home[N];
vector < pair < int, int > > adj[N];

inline void dijkstra(int s) {
    for (int i = 0; i <= V; i++) {
        dist[s][i] = INF;
        par[s][i] = -1;
    }
    dist[s][s] = 0; par[s][s] = -1;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));
    while(!pq.empty()) {
        int u = pq.top().second; int d = pq.top().first; pq.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first; int w = adj[u][i].second;
            if(d + w < dist[s][v]) {
                dist[s][v] = d + w;
                par[s][v] = u;
                pq.push(ii(dist[s][v], v));
            }
        }
    }
}

inline bool solve(int x) {
    init(V + 1, V + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            if (dist[home[i]][j] <= x) {
                addEdge(i, j);
            }
        }
    }
    int result = maxMatching();
    return (result >= k);
}

int main(){
    scanf("%d %d %d %d", &V, &E, &n, &k);
    set < int > roots;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &home[i]);
        roots.insert(home[i]);
    }
    for (int i = 1; i <= E; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back(ii(v, w));
        adj[v].push_back(ii(u, w));
    }
    for (int root: roots) {
        dijkstra(root);
    }
    int l = 0, r = 1731312;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (solve(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}