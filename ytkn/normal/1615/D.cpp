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

int popcount(int v){
    int ans = 0;
    for(int i = 0; i < 30; i++){
        if(v&(1<<i)) ans++;
    }
    return ans;
}

struct edge{
    int to, p;
};

bool dfs(int v, vector<vector<edge>> &g, vector<int> &col, int c){
    col[v] = c;
    for(edge e: g[v]){
        if(col[e.to] != -1) {
            if(col[e.to] != c^e.p) return false;
            continue;
        }
        if(!dfs(e.to, g, col, c^e.p)) return false;
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<edge>> g(n);
    auto add_edge = [&](int x, int y, int p){
        g[x].push_back(edge{y, p});
        g[y].push_back(edge{x, p});
    };
    vector<int> x(n), y(n), v(n);
    for(int i = 0; i < n-1; i++) {
        cin >> x[i] >> y[i] >> v[i]; x[i]--; y[i]--;
        if(v[i] != -1){
            int p = popcount(v[i])%2;
            add_edge(x[i], y[i], p);
        }
    }
    vector<int> a(m), b(m), p(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> p[i]; a[i]--; b[i]--;
        add_edge(a[i], b[i], p[i]);
    }
    vector<int> col(n, -1);
    for(int i = 0; i < n; i++){
        if(col[i] == -1){
            if(!dfs(i, g, col, 0)){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for(int i = 0; i < n-1; i++){
        if(v[i] == -1){
            v[i] = col[x[i]]^col[y[i]];
        }
        cout << x[i]+1 << ' ' << y[i]+1 << ' ' << v[i] << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}