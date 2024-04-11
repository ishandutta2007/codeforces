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

const ll inf = 1e+15;

vector<vector<ll>> warshallfloyd(vector<vector<ll>> g){
    int n = g.size();
    vector<vector<ll>> dist(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = g[i][j];
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ll new_len = dist[j][i] + dist[i][k];
                dist[j][k] = min(new_len, dist[j][k]);
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    auto g = vec2d(n, n, inf);
    vector<int> u(m), v(m);
    vector<ll> w(m);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i] >> w[i]; u[i]--; v[i]--;
        g[u[i]][v[i]] = w[i];
        g[v[i]][u[i]] = w[i];
    }
    auto dist = warshallfloyd(g);
    auto dp = vec2d(n, n, -inf);
    int q; cin >> q;
    vector<ll> l(q);
    for(int i = 0; i < q; i++){
        int u, v; ll l;
        cin >> u >> v >> l; u--; v--;
        dp[u][v] = l;
        dp[v][u] = l;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                chmax(dp[i][j], dp[k][j]-dist[k][i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        bool ok = false;
        for(int j = 0; j < n; j++){
            if(dp[u[i]][j] >= w[i]+dist[v[i]][j]) ok = true;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}