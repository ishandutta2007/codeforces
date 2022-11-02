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
    int n; ll m; cin >> n >> m;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> seen(n);
    vector<ll> sum_people(n);
    vector<ll> sum_happy(n);
    function<bool(int)> dfs = [&](int v){
        seen[v] = true;
        sum_people[v] = p[v];
        ll sum_happy_child = 0;
        for(int to: g[v]){
            if(seen[to]) continue;
            if(!dfs(to)) return false;
            sum_people[v] += sum_people[to];
            sum_happy_child += sum_happy[to];
        }
        if((h[v]+sum_people[v])%2 != 0) return false;
        sum_happy[v] = (h[v]+sum_people[v])/2;
        if(sum_happy[v] > sum_people[v]) return false;
        return sum_happy[v] >= sum_happy_child;
    };
    if(dfs(0)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}