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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    vector<int> b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> seen(n);
    auto rem = vec2d(n, 2, 0);
    ll ans = 0;
    function<void(int)> dfs = [&](int v){
        seen[v] = true;
        if(b[v] != c[v]) {
            if(b[v] == 1){
                rem[v][1]++;
            }else{
                rem[v][0]++;
            }
        }
        for(int to: g[v]){
            if(seen[to]) continue;
            chmin(a[to], a[v]);
            dfs(to);
            rem[v][0] += rem[to][0];
            rem[v][1] += rem[to][1];
        }
        int mn = min(rem[v][0], rem[v][1]);
        ans += a[v]*mn*2;
        rem[v][0] -= mn;
        rem[v][1] -= mn;
    };
    dfs(0);
    if(rem[0][0]+rem[0][1] > 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}