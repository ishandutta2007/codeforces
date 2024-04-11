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

struct edge{
    int to, cost;
    edge(int to, int cost): to(to), cost(cost) {}
};

using T = tuple<int, int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<edge>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }
    for(int i = 0; i < n; i++){
        if(g[i].size() == 2){
            cout << "NO" << endl;
            return 0;
        }
    }
    int root = -1;
    for(int i = 0; i < n; i++){
        if(g[i].size() == 1){
            root = i;
            break;
        }
    }
    vector<int> ch(n);
    function<void(int, int)> calc_child = [&](int v, int par){
        ch[v] = v;
        for(edge e: g[v]){
            if(e.to == par) continue;
            calc_child(e.to, v);
            ch[v] = ch[e.to];
        }
    };
    calc_child(root, -1);
    vector<T> ans;
    function<void(int, int, int)> dfs = [&](int v, int par, int x){
        vector<int> children;
        for(edge e: g[v]){
            if(e.to == par) continue;
            children.push_back(e.to);
        }
        for(edge e: g[v]){
            if(e.to == par) continue;
            int y = ch[e.to] == ch[v] ? (e.cost-x)/2 : e.cost/2;
            int u = e.to == children[0] ? children.back() : children[0];
            // cout << v << ' ' << e.to << ':' << u << ' ' << y << endl;
            ans.push_back(T(root, ch[e.to], y));
            ans.push_back(T(root, ch[u], -y));
            ans.push_back(T(ch[u], ch[e.to], y));
            dfs(e.to, v, e.cost);
        }
    };
    ans.push_back(T(root, ch[root], g[root][0].cost));
    dfs(g[root][0].to, root, g[root][0].cost);
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto [u, v, w]: ans){
        cout << u+1 << ' ' << v+1 << ' ' << w << endl;
    }
}