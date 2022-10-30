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

void dfs(int v, vector<vector<int>> &g, vector<bool> &seen, vector<int> &component){
    seen[v] = true;
    component.push_back(v);
    for(int to: g[v]){
        if(!seen[to]) dfs(to, g, seen, component);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> op(n);
    for(int i = 0; i < k; i++){
        int c; cin >> c;
        for(int j = 0; j < c; j++){
            int x; cin >> x; x--;
            op[x].push_back(i);
        }
    }
    UnionFind uf(k);
    auto cnt = vec2d(k, 2, 0);
    vector<int> col(k);
    vector<bool> fixed_same(k);
    vector<bool> fixed_inv(k);
    for(int i = 0; i < k; i++){
        cnt[i][0] = 1;
    }
    int ans = 0;
    vector<bool> seen(k);
    auto get_count = [&](int i){
        int r = uf.root(i);
        if(fixed_same[r]) return cnt[r][1];
        if(fixed_inv[r]) return cnt[r][0];
        return min(cnt[r][0], cnt[r][1]);
    };
    auto merge = [&](int u, int v){
        int ur = uf.root(u), vr = uf.root(v);
        int sum0 = cnt[ur][0]+cnt[vr][0];
        int sum1 = cnt[ur][1]+cnt[vr][1];
        uf.unionSet(u, v);
        int r = uf.root(u);
        cnt[r][0] = sum0;
        cnt[r][1] = sum1;
        if(fixed_inv[ur] || fixed_inv[vr]){
            fixed_inv[r] = true;
        }
        if(fixed_same[ur] || fixed_same[vr]){
            fixed_same[r] = true; 
        }
    };
    vector<vector<int>> g(k);
    for(int i = 0; i < n; i++){
        if(op[i].empty()){
            cout << ans << "\n";
        }else if(op[i].size() == 1){
            int u = op[i][0];
            int ur = uf.root(u);
            ans -= get_count(u);
            int c = s[i] == '0' ? 1 : 0;
            if(c == col[u]){
                assert(!fixed_inv[ur]);
                fixed_same[ur] = true;
            }else{
                // debug_value(u)
                assert(!fixed_same[ur]);
                fixed_inv[ur] = true;
            }
            ans += get_count(u);
            cout << ans << "\n";
        }else{
            int u = op[i][0]; int ur = uf.root(u);
            int v = op[i][1]; int vr = uf.root(v);
            if(uf.findSet(u, v)){
                cout << ans << "\n";
                continue;
            }
            ans -= get_count(u);
            ans -= get_count(v);
            int cost = s[i] == '0' ? 1 : 0;
            // cout << u << '-' << v << ' ' << cost << endl;
            if(col[u]^cost != col[v]){
                vector<int> component;
                if(uf.size(u) < uf.size(v)){
                    seen[v] = true;
                    dfs(u, g, seen, component);
                    assert(component.size() == uf.size(u));
                    seen[v] = false;
                    swap(cnt[ur][0], cnt[ur][1]);
                    if(fixed_same[ur]){
                        fixed_same[ur] = false;
                        fixed_inv[ur] = true;
                    }else if(fixed_inv[ur]){
                        fixed_same[ur] = true;
                        fixed_inv[ur] = false;
                    }
                }else{
                    seen[u] = true;
                    dfs(v, g, seen, component);
                    assert(component.size() == uf.size(v));
                    seen[u] = false;
                    swap(cnt[vr][0], cnt[vr][1]);
                    if(fixed_same[vr]){
                        fixed_same[vr] = false;
                        fixed_inv[vr] = true;
                    }else if(fixed_inv[vr]){
                        fixed_same[vr] = true;
                        fixed_inv[vr] = false;
                    }
                }
                for(int x: component) {
                    col[x] ^= 1;
                    seen[x] = false;
                }
            }
            merge(u, v);
            int r = uf.root(u);
            ans += get_count(r);
            g[u].push_back(v);
            g[v].push_back(u);
            cout << ans << "\n";
        }
        // for(int j = 0; j < k; j++){
        //     int r = uf.root(j);
        //     int c = 0;
        //     if(fixed_same[r]){
        //         c = col[j];
        //     }else if(fixed_inv[r]){
        //         c = col[j]^1;
        //     }else{
        //         if(cnt[r][0] < cnt[r][1]) c = col[j]^1;
        //         else c = col[j];
        //     }
        //     cout << c << ' ';
        // }
        // cout << endl;
    }
}