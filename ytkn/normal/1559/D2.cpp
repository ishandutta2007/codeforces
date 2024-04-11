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

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m1, m2; cin >> n >> m1 >> m2;
    UnionFind uf1(n), uf2(n);
    for(int i = 0; i < m1; i++){
        int u, v; cin >> u >> v; u--; v--;
        uf1.unionSet(u, v);
    }
    for(int i = 0; i < m2; i++){
        int u, v; cin >> u >> v; u--; v--;
        uf2.unionSet(u, v);
    }
    vector<P> ans;
    for(int j = 1; j < n; j++){
        if(!uf1.findSet(0, j) && !uf2.findSet(0, j)){
            ans.push_back(P(0, j));
            uf1.unionSet(0, j);
            uf2.unionSet(0, j);
        }
    }
    vector<vector<int>> g1(n), g2(n);
    vector<int> root1(n), root2(n);
    for(int i = 0; i < n; i++){
        int r1 = uf1.root(i), r2 = uf2.root(i);
        g1[r1].push_back(i);
        g2[r2].push_back(i);
        root1[i] = r1;
        root2[i] = r2;
    }
    queue<int> que1, que2;
    for(int x: g1[uf1.root(0)]){
        if(x != 0) que1.push(x);
    }
    for(int x: g2[uf2.root(0)]){
        if(x != 0) que2.push(x);
    }
    auto process = [&](){
        while(!que1.empty()){
            int x = que1.front();
            if(!uf2.findSet(0, x)) break;
            que1.pop();
        }
        while(!que2.empty()){
            int x = que2.front();
            if(!uf1.findSet(0, x)) break;
            que2.pop();
        }
    };
    auto connect = [&](int u, int v){
        // cout << u << ':' << v << endl;
        ans.push_back(P(u, v));
        assert(!uf2.findSet(0, u));
        assert(!uf1.findSet(0, v));
        int ur = root2[u];
        for(int x: g2[ur]) que2.push(x);
        int vr = root1[v];
        for(int x: g1[vr]) que1.push(x);
        uf2.unionSet(u, v);
        uf1.unionSet(v, u);
    };
    process();
    while(!que1.empty() && !que2.empty()){
        int u = que1.front(), v = que2.front();
        connect(u, v);
        process();
    }
    cout << ans.size() << endl;
    for(auto [u, v]: ans) cout << u+1 << ' ' << v+1 << endl;
}