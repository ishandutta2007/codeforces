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
    int to, idx;
    edge(int to, int idx): to(to), idx(idx) {}
};

void solve(){
    int p; cin >> p;
    int n = 1<<p;
    vector<vector<edge>> g(n);  
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(edge(v, i));
        g[v].push_back(edge(u, i));
    }
    vector<int> ans_v(n);
    vector<int> ans_e(n-1);
    function<void(int, int, int)> dfs = [&](int v, int par, int c){
        if(c == 0){
            ans_v[v] = v+(1<<p);
        }else{
            ans_v[v] = v;
        }
        for(edge e: g[v]){
            if(par == e.to) continue;
            dfs(e.to, v, c^1);
            if(c == 0){
                ans_e[e.idx] = e.to+(1<<p);
            }else{
                ans_e[e.idx] = e.to;
            }
        }
    };
    dfs(0, -1, 0);
    ans_v[0] = 1<<p;
    cout << 1 << endl;
    print_vector(ans_v);
    print_vector(ans_e);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}