#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

class CentrioidDecomposition{
    public:
    int n;
    vector<bool> used;
    vector<int> ch;
    vector<vector<int>> g;
    CentrioidDecomposition(int n, vector<vector<int>> g): n(n), g(g) {
        assert(g.size() == n);
        used.assign(n, false);
        ch.assign(n, 0);
    }

    /**
     * returns (root, balanced undirected tree)
     */ 
    pair<int, vector<vector<int>>> build_balanced_tree(){
        vector<vector<int>> tree(n);
        int centroid = find_centroid(0);
        for(int to : g[centroid]){
            if(!used[to]) sub_build(to, centroid, tree);
        }
        return make_pair(centroid, tree);
    }

    private:
    void dfs(int v, vector<int> &visited){
        used[v] = true;
        ch[v] = 1;
        visited.push_back(v);
        for(int to : g[v]){
            if(!used[to]){
                dfs(to, visited);
                ch[v] += ch[to];
            }
        }
    }

    int find_centroid(int r){
        vector<int> visited;
        dfs(r, visited);
        int m = visited.size();
        for(int v : visited) used[v] = false;
        int cur = r;
        int pre = -1;
        while(true){
            int nx = -1;
            int max_ch = -1;
            for(int to : g[cur]){
                if(!used[to] && to != pre){
                    if(ch[to]*2 > m && chmax(max_ch, ch[to])) nx = to;
                }
            }
            if(nx == -1) break;
            pre = cur;
            cur = nx;
        }
        return cur;
    }

    void sub_build(int r, int par, vector<vector<int>> &tree){
        int centroid = find_centroid(r);
        tree[par].push_back(centroid);
        tree[centroid].push_back(par);
        used[centroid] = true;
        for(int to : g[centroid]){
            if(!used[to]) sub_build(to, centroid, tree);
        }
    }
};

void dfs(int v, vector<vector<int>> &g, vector<bool> &used, vector<int> &depth, int d){
    used[v] = true;
    depth[v] = d;
    for(int to : g[v]){
        if(!used[to]) dfs(to, g, used, depth, d+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto cd = CentrioidDecomposition(n, g);
    auto [c, tree] = cd.build_balanced_tree();
    vector<bool> used(n);
    vector<int> depth(n);
    dfs(c, tree, used, depth, 0);
    for(int i = 0; i < n; i++) cout << (char)('A'+depth[i]) << ' ';
    cout << endl;
}