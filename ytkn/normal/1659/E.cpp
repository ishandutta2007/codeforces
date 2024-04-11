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

const int N = 30;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m), w(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> w[i];
        a[i]--; b[i]--;
    }
    int q; cin >> q;
    vector<int> u(q), v(q);
    for(int i = 0; i < q; i++){
        cin >> u[i] >> v[i]; u[i]--; v[i]--;
    }
    vector<int> ans(q, 2);
    for(int i = 0; i < N; i++){
        {
            UnionFind uf(n);
            for(int j = 0; j < m; j++){
                if(w[j]&(1<<i)){
                    uf.unionSet(a[j], b[j]);
                }
            }
            for(int j = 0; j < q; j++){
                if(uf.findSet(u[j], v[j])) ans[j] = 0;
            }
        }
        if(i != 0){
            UnionFind uf(n);
            for(int j = 0; j < m; j++){
                if((w[j]&(1<<i)) && (w[j]%2 == 1)){
                    uf.unionSet(a[j], b[j]);
                }
                if(w[j]%2 == 0){
                    uf.unionSet(a[j], b[j]);
                }
            }
            vector<bool> ok(n);
            for(int j = 0; j < m; j++){
                if(w[j]%2 == 0){
                    ok[uf.root(a[j])] = true;
                }
            }
            for(int j = 0; j < q; j++){
                if(ok[uf.root(u[j])]) chmin(ans[j], 1);
            }
        }
    }
    print_vector(ans, '\n');
}