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

void dfs_size(int v, vector<vector<int>> &g, vector<int> &par, vector<int> &subtree_size, int &centroid){
    subtree_size[v] = 1;
    bool is_centroid = true;
    int n = g.size();
    for(int to: g[v]){
        if(par[v] != to){
            par[to] = v;
            dfs_size(to, g, par, subtree_size, centroid);
            if (subtree_size[to] > n/2) is_centroid = false;
            subtree_size[v] += subtree_size[to];
        }
    }
    if (n-subtree_size[v] > n/2) is_centroid = false;
    if(is_centroid) centroid = v;
}

using T = tuple<int, int, int>;
using P = pair<int, int>;

void dfs(int v, vector<vector<int>> &g, vector<bool> &seen, int &cur_val, int sum, int step, vector<T> &ans){
    seen[v] = true;
    for(int to: g[v]){
        if(seen[to]) continue;
        cur_val += step;
        ans.push_back(T(v, to, cur_val-sum));
        dfs(to, g, seen, cur_val, cur_val, step, ans);
    } 
}

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    if(n == 1){
        return 0;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> par(n, -1);
    vector<int> subtree_size(n);
    int r = -1;
    dfs_size(0, g, par, subtree_size, r);
    vector<int> vl, vr;
    vector<P> vp;
    for(int to: g[r]){
        if(to == par[r]) continue;
        vp.push_back(P(subtree_size[to], to));
    }
    if(par[r] != -1){
        vp.push_back(P(n-subtree_size[r], par[r]));
    }
    int sum = 1;
    sort(vp.begin(), vp.end());
    for(auto [sz, to]: vp){
        int sl = ceil_div(n, 3);
        int sr = (2*n)/3;
        if(sl <= sum && sum <= sr){
            vr.push_back(to);
        }else{
            sum += sz;
            vl.push_back(to);
            assert(sum <= sr);
        }
    }
    vector<bool> seen(n);
    for(int v: vr) seen[v] = true;
    vector<T> ans;
    int x = 0;
    dfs(r, g, seen, x, 0, 1, ans);
    assert(x == sum-1);
    for(int v: vr) seen[v] = false;
    seen[r] = false;
    x = 0;
    dfs(r, g, seen, x, 0, sum, ans);
    for(auto [u, v, x]: ans) cout << u+1 << ' ' << v+1 << ' ' << x << endl;
}