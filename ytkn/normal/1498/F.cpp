#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
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

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

using Arr = array<int, 40>;

const int N = 100000;
int n, k;
int a[N];
vector<int> g[N];
Arr agg_child[N];
Arr agg_all[N];

Arr calc_xor(Arr &x, Arr &y){
    Arr ans;
    for(int i = 0; i < 2*k; i++) ans[i] = x[i]^y[i];
}

void dfs1(int v, int par){
    agg_child[v][0] ^= a[v];
    for(int to: g[v]){
        if(to == par) continue;
        dfs1(to, v);
        for(int d = 0; d < 2*k; d++){
            agg_child[v][(d+1)%(2*k)] ^= agg_child[to][d];
        }
    }
}

void dfs2(int v, int par, Arr from_par){
    agg_all[v] = agg_child[v];
    for(int d = 0; d < 2*k; d++){
        agg_all[v][(d+1)%(2*k)] ^= from_par[d];
    }
    for(int to: g[v]){
        if(to == par) continue;
        for(int d = 0; d < 2*k; d++){
            agg_all[v][(d+1)%(2*k)] ^= agg_child[to][d];
        }
        dfs2(to, v, agg_all[v]);
        for(int d = 0; d < 2*k; d++){
            agg_all[v][(d+1)%(2*k)] ^= agg_child[to][d];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    dfs1(0, -1);
    dfs2(0, 0, Arr());
    for(int i = 0; i < n; i++){
        int xo = 0;
        for(int d = k; d < 2*k; d++) xo ^= agg_all[i][d];
        if(xo == 0) cout << 0 << ' ';
        else cout << 1 << ' ';
    }
    cout << endl;
}