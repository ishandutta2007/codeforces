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

void solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k1; cin >> k1;
    vector<int> x(k1);
    vector<bool> is_subtree1(n);
    for(int i = 0; i < k1; i++){
        cin >> x[i]; x[i]--;
        is_subtree1[x[i]] = true;
    }

    int k2; cin >> k2;
    vector<int> y(k2);
    vector<bool> is_subtree2(n);
    for(int i = 0; i < k2; i++){
        cin >> y[i]; y[i]--;
        is_subtree2[y[i]] = true;
    }
    vector<int> par(n);
    function<void(int, int)> dfs = [&](int v, int p){
        par[v] = p;
        for(int to: g[v]){
            if(to == p) continue;
            dfs(to, v);
        }
    };
    dfs(x[0], -1);
    auto ask1 = [&](int v){
        cout << "A " << v+1 << endl;
        int ans; cin >> ans; ans--;
        return ans;
    };
    auto ask2 = [&](int v){
        cout << "B " << v+1 << endl;
        int ans; cin >> ans; ans--;
        return ans;
    };
    auto verify = [&](int v){
        if(v != -1) v++;
        cout << "C " << v << endl;
    };
    int u = ask2(y[0]);
    if(is_subtree1[u]){
        verify(u);
        return;
    }
    int v = u;
    while(!is_subtree1[v]){
        v = par[v];
    }
    int w = ask1(v);
    if(is_subtree2[w]){
        verify(v);
    }else{
        verify(-1);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}