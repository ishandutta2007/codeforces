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


template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        data = data_;
        sort(begin(data), end(data));
        data.erase(unique(begin(data), end(data)), end(data));
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};


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

struct edge{
    int to, idx;
    edge(int to, int idx): to(to), idx(idx) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> b(n-1), c(n-1);
    for(int i = 0; i < n-1; i++) cin >> b[i];
    for(int i = 0; i < n-1; i++) cin >> c[i];
    for(int i = 0; i < n-1; i++){
        if(b[i] > c[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> v = b;
    for(int x: c) v.push_back(x);
    auto cp = Compress<int>(v);
    int m = cp.size();
    vector<multiset<int>> g(m);
    UnionFind uf(m);
    for(int i = 0; i < n-1; i++){
        int u = cp[b[i]];
        int v = cp[c[i]];
        g[u].insert(v);
        g[v].insert(u);
        uf.unionSet(u, v);
    }
    if(uf.size(0) != m){
        cout << -1 << endl;
        return 0;
    }
    vector<int> odd_v;
    for(int i = 0; i < m; i++){
        if(g[i].size()%2 == 1) odd_v.push_back(i);
    }
    if(odd_v.size() != 0 && odd_v.size() != 2){
        cout << -1 << endl;
        return 0;
    }
    /**
     * thanks: https://kokiymgch.hatenablog.com/entry/2017/12/07/193238
     */ 
    function<void(int, vector<int>&)> dfs = [&](int u, vector<int> &trail) {
        while (!g[u].empty()) {
            int v = *(g[u].begin());
            g[u].erase(g[u].find(v));
            g[v].erase(g[v].find(u));
            dfs(v, trail);
        }
        trail.push_back(u);
    };
    int s = 0;
    if(odd_v.size() == 2){
        s = odd_v[0];
    }
    vector<int> trail;
    dfs(s, trail);
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int idx = trail[i];
        ans[i] = cp.data[idx];
    }
    print_vector(ans);
}