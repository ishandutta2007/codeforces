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

using P = pair<ll, int>;

void solve(){
    int n; ll p; cin >> n >> p;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    UnionFind uf(n);
    vector<P> vp;
    for(int i = 0; i < n; i++){
        if(a[i] < p){
            vp.push_back(P(a[i], i));
        }
    }
    ll ans = 0;
    sort(vp.begin(), vp.end());
    for(auto [x, i]: vp){
        for(int j = i-1; j >= 0; j--){
            if(a[j]%x != 0) break;
            if(uf.findSet(i, j)) break;
            uf.unionSet(i, j);
            ans += x;
        }
        for(int j = i+1; j < n; j++){
            if(a[j]%x != 0) break;
            if(uf.findSet(i, j)) break;
            uf.unionSet(i, j);
            ans += x;
        }
    }
    ll n_components = 0;
    for(int i = 0; i < n; i++){
        if(uf.root(i) == i) n_components++;
    }
    ans += (n_components-1)*p;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}