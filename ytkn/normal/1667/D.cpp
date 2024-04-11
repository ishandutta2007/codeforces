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

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << '\n';
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << '\n';

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
        cout << '\n';
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << '\n';
}

using P = pair<int, int>;

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> from(n, -1);
    vector<int> depth(n);
    vector<int> par(n, -1);
    vector<P> ans;
    vector<P> extra_ans;
    auto make_ans = [&](int u, int v, int a){
        assert(depth[v]%2 != depth[u]%2);
        vector<int> path;
        int cur = v;
        while(cur != a){
            path.push_back(cur);
            cur = par[cur];
        }
        path.push_back(a);
        cur = u;
        vector<int> path_u;
        while(cur != a){
            path_u.push_back(cur);
            cur = par[cur];
        }
        reverse(path_u.begin(), path_u.end());
        for(int x: path_u) path.push_back(x);
        for(int i = 0; i+1 < (int)path.size(); i+=2){
            ans.push_back(P(path[i], path[i+1]));
        }
        for(int i = 1; i+1 < (int)path.size(); i+=2){
            ans.push_back(P(path[i], path[i+1]));
        }
    };

    auto make_extra_ans = [&](int u, int v, int a){
        assert(depth[v]%2 != depth[u]%2);
        vector<int> path;
        int cur = v;
        while(cur != a){
            path.push_back(cur);
            cur = par[cur];
        }
        path.push_back(a);
        cur = u;
        vector<int> path_u;
        while(cur != a){
            path_u.push_back(cur);
            cur = par[cur];
        }
        reverse(path_u.begin(), path_u.end());
        for(int x: path_u) path.push_back(x);
        for(int i = 1; i+1 < (int)path.size(); i+=2){
            extra_ans.push_back(P(path[i], path[i+1]));
        }
        for(int i = 0; i+1 < (int)path.size(); i+=2){
            extra_ans.push_back(P(path[i], path[i+1]));
        }
        
    };

    function<bool(int, int, int)> dfs = [&](int v, int p, int d){
        depth[v] = d;
        par[v] = p;
        vector<vector<int>> vs(2);
        for(int to: g[v]){
            if(to == p) continue;
            if(!dfs(to, v, d+1)) return false;
            vs[(depth[from[to]]-depth[v])%2].push_back(from[to]);
        }
        while(!vs[0].empty() && !vs[1].empty()){
            int a = vs[0].back(); vs[0].pop_back();
            int b = vs[1].back(); vs[1].pop_back();
            make_ans(a, b, v);
        }
        if(vs[0].empty() && vs[1].empty()){
            from[v] = v;
            return true;
        }
        if(vs[0].size() >= 2 || vs[1].size() >= 3){
            return false;
        }
        if(v == 0){ // root
            if(!vs[0].empty() || vs[1].size() > 1) return false;
            make_ans(v, vs[1][0], v);
            return true;
        }
        if(!vs[0].empty()){
            from[v] = vs[0][0];
        }
        if(!vs[1].empty()){
            from[v] = vs[1][0];
            if(vs[1].size() == 2){
                make_extra_ans(vs[1][1], v, v);
            }
        }
        return true;
    };
    if(dfs(0, -1, 0)){
        cout << "YES" << '\n';
        reverse(ans.begin(), ans.end());
        for(auto [x, y]: extra_ans) cout << x+1 << ' ' << y+1 << '\n';
        for(auto [x, y]: ans) cout << x+1 << ' ' << y+1 << '\n';
    }else{
        cout << "NO" << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}