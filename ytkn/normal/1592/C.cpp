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

int dfs(int v, int k, vector<vector<int>> &g, vector<int> &a, vector<bool> &seen, int &cnt){
    seen[v] = true;
    int ans = a[v];
    for(int to: g[v]){
        if(!seen[to]){
            ans ^= dfs(to, k, g, a, seen, cnt);
        }
    }
    if(ans == k && v != 0){
        // cout << v << ' ' << a[v] << endl;
        cnt++;
        ans = 0;
    }
    return ans;
}

void solve(){
    int k, n; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int a_xor = accumulate(a.begin(), a.end(), 0, [](int x, int y){ return x^y; });
    if(a_xor == 0) {
        cout << "YES" << endl;
        return;
    }
    if(k == 2){
        cout << "NO" << endl;
        return;
    }
    vector<bool> seen(n, false);
    int cnt = 0;
    dfs(0, a_xor, g, a, seen, cnt);
    if(cnt <= 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}