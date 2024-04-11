#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

struct edge{
    int to, cost;
};

int n, m, k;
vector<edge> G[200000];
vector<edge> G_inv[200000];


bool forbidden[150][150];

bool ng[10][10];

void input(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w; u--; v--;
        G[u].push_back((edge){v, w});
    }
}

bool comp_edge(edge e1, edge e2){
    return e1.cost < e2.cost;
}

int to_idx(int i, int j){
    return i*(k+1)+j;
}

// UnionFind uf(150);

void preprocess(){
    for(int v = 0; v < n; v++){
        sort(G[v].begin(), G[v].end(), comp_edge);
        for(int i = 0; i < G[v].size(); i++){
            G[v][i].cost = i+1;
            edge e = G[v][i];
            G_inv[e.to].push_back((edge){v, e.cost});
        }
    }
    for(int v = 0; v < n; v++){
        set<int> st;
        for(edge e : G_inv[v]){
            int u = e.to;
            int sz = G[u].size();
            int idx = to_idx(sz, e.cost);
            if(st.count(idx) > 0){
                ng[sz][e.cost] = true;
                // cout << "NG " << sz << ' ' << e.cost << endl;
            }
            st.insert(idx);
        }
        vector<int> v_idx;
        for(int x : st) v_idx.push_back(x);
        for(int i = 0; i < v_idx.size(); i++){
            for(int j = 0; j < v_idx.size(); j++){
                if(i == j) continue;
                forbidden[v_idx[i]][v_idx[j]] = true;
            }
        }
    }
}

int ans;
int buf[10];

bool judge(){
    for(int i = 1; i <= k; i++){
        // cout << buf[i] << ' ';
        for(int j = i+1; j <= k; j++){
            int idx1 = to_idx(i, buf[i]);
            int idx2 = to_idx(j, buf[j]);
            if(forbidden[idx1][idx2]) return false;
        }
    }
    // cout << endl;
    return true;
}

void dfs(int i){
    // cout << i << endl;
    if(i == k+1){
        if(judge()) ans++;
        return;
    }
    for(int j = 1; j <= i; j++){
        if(ng[i][j]) continue;
        buf[i] = j;
        dfs(i+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    preprocess();
    dfs(1);
    cout << ans << endl;
}