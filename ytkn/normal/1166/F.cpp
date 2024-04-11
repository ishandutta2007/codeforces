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
    vector<set<int>> st;
    UnionFind(int size) : data(size, -1) {
        for(int i = 0; i < size; i++) {
            st.push_back({i});
        }
    }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        if(st[x].size() > st[y].size()){
            for(int a: st[y]) st[x].insert(a);
            st[y].clear();
        }else{
            for(int a: st[x]) st[y].insert(a);
            st[x].clear();
            st[x] = move(st[y]);
        }
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
    int n, m, c, q; cin >> n >> m >> c >> q;
    map<P, vector<int>> g;
    UnionFind uf(2*n);
    auto add_edge = [&](P p, int to){
        if(g.count(p)){
            uf.unionSet(g[p].back(), to);
        }
        uf.st[uf.root(p.first)].insert(to);
        g[p].push_back(to);
    };
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z; x--; y--; z--;
        add_edge(P(x, z), y);
        add_edge(P(y, z), x);
    }
    while(q--){
        char c; cin >> c;
        if(c == '+'){
            int x, y, z; cin >> x >> y >> z; x--; y--; z--;
            add_edge(P(x, z), y);
            add_edge(P(y, z), x);
        }else{
            int x, y; cin >> x >> y; x--; y--;
            if(uf.findSet(x, y) || uf.st[uf.root(x)].count(y)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}