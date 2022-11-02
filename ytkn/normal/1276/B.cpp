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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

ll tri(ll x){
    return (x*(x-1))/2;
}

using P = pair<int, int>;

void solve(){
    int n, m, a, b; cin >> n >> m >> a >> b;
    a--; b--;
    vector<int> u(m), v(m);
    for(int i = 0; i < m; i++){
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
    }
    UnionFind uf_a(n), uf_b(n);
    for(int i = 0; i < m; i++){
        if(u[i] != a && v[i] != a){
            uf_a.unionSet(u[i], v[i]);
        }
        if(u[i] != b && v[i] != b){
            uf_b.unionSet(u[i], v[i]);
        }
    }
    ll ans = tri(n-2);
    map<P, ll> mp;
    auto add = [&](int ra, int rb){
        P p(ra, rb);
        if(mp.count(p)) mp[p]++;
        else mp[p] = 1;
    };
    for(int i = 0; i < n; i++){
        add(uf_a.root(i), uf_b.root(i));
        if(uf_a.root(i) == i){
            ll sz = uf_a.size(i);
            if(uf_a.findSet(a, i)) sz--;
            if(uf_a.findSet(b, i)) sz--;
            ans -= tri(sz);
        }
        if(uf_b.root(i) == i){
            ll sz = uf_b.size(i);
            if(uf_b.findSet(a, i)) sz--;
            if(uf_b.findSet(b, i)) sz--;
            ans -= tri(sz);
        }
    }
    for(auto [_, c]: mp) ans += tri(c);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}