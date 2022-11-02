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


template<typename T>
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
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

using P = pair<int, int>;

Compress<P> make_compress(vector<P> p1, vector<P> p2){
    for(auto p: p2) p1.push_back(p);
    return Compress<P>(p1); 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> t(m);
    auto edge = vec2d(2, m, P(0, 0));
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> t[i] >> x >> y; x--; y--;
        if(x > y) swap(x, y);
        edge[0][i] = P(x, y);
        x = (x+1)%n; y = (y+1)%n;
        if(x > y) swap(x, y);
        edge[1][i] = P(x, y);
    }
    auto cp = make_compress(edge[0], edge[1]);
    auto indices = vec2d(2, m, 0);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 2; j++){
            indices[j][i] = cp[edge[j][i]];
        }
    }
    vector<int> last(m+1);
    int sq = sqrt(m);
    UnionFind uf(n);
    vector<vector<int>> g(n);
    string ans;
    int sz = cp.data.size();
    vector<bool> used(sz);
    vector<bool> seen(n);
    vector<int> pending;
    // sq = m;
    for(int i = 0; i < m; i++){
        if(i%sq == 0){
            vector<bool> maybe_used(sz);
            pending.clear();
            for(int j = i; j < i+sq && j < m; j++){
                if(t[j] == 2) continue;
                pending.push_back(indices[0][j]);
                pending.push_back(indices[1][j]);
                maybe_used[indices[0][j]] = true;
                maybe_used[indices[1][j]] = true;
            }
            uf = UnionFind(n);
            for(int j = 0; j < i; j++){
                if(t[j] == 1){
                    int idx = indices[last[j]][j];
                    if(!maybe_used[idx] && used[idx]) {
                        auto [u, v] = cp.data[idx];
                        uf.unionSet(u, v);
                    }
                }
            }
        }
        if(t[i] == 1){
            int idx = indices[last[i]][i];
            used[idx] = !used[idx];
            last[i+1] = last[i];
            continue;
        }
        vector<int> vs;
        int l = (i/sq)*sq;
        for(int idx: pending){
            if(used[idx]) {
                auto [u, v] = cp.data[idx];
                // assert(edge[k][j] == cp.data[idx]);
                int ur = uf.root(u);
                int vr = uf.root(v);
                vs.push_back(ur);
                vs.push_back(vr);
                g[ur].push_back(vr);
                g[vr].push_back(ur);
            }
        }
        auto [u, v] = edge[last[i]][i];
        int ur = uf.root(u);
        int vr = uf.root(v);
        queue<int> que;
        que.push(ur);
        seen[ur] = true;
        vs.push_back(ur);
        while(!que.empty()){
            int v = que.front(); que.pop();
            if(v == vr){
                break;
            }
            for(int to: g[v]){
                if(!seen[to]){
                    que.push(to);
                    seen[to] = true;
                }
            }
        }
        if(seen[vr]){
            ans += '1';
            last[i+1] = 1;
        }else{
            ans += '0';
            last[i+1] = 0;
        }
        for(int v: vs) {
            g[v].clear();
            seen[v] = false;
        }
    }
    cout << ans << endl;
}