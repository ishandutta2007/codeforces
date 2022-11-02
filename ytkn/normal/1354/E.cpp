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

bool dfs(int v, vector<vector<int>> &g, vector<int> &col, int c){
    col[v] = c;
    for(int to: g[v]){
        if(col[to] == -1){
            if(!dfs(to, g, col, c^1)) return false;
        }else{
            if(col[to] == c){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    vector<vector<int>> g(n);
    UnionFind uf(n);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        uf.unionSet(u, v);
    }
    vector<int> col(n, -1);
    vector<int> roots;
    vector<vector<int>> components(n);
    for(int i = 0; i < n; i++){
        components[uf.root(i)].push_back(i);
        if(uf.root(i) != i) continue;
        roots.push_back(i);
        if(!dfs(i, g, col, 0)){
            cout << "NO" << endl;
            return 0;
        }
    }
    int nr = roots.size();
    auto dp = vec2d(nr+1, n+1, false);
    auto pre = vec2d(nr+1, n+1, -1);
    auto cnt = vec2d(nr, 2, 0);
    dp[0][0] = true;
    for(int i = 0; i < nr; i++){
        int r = roots[i];
        for(int v: components[r]){
            cnt[i][col[v]]++;
        }
        for(int j = 0; j <= n; j++){
            if(!dp[i][j]) continue;
            dp[i+1][j+cnt[i][0]] = true;
            pre[i+1][j+cnt[i][0]] = j;
            dp[i+1][j+cnt[i][1]] = true;
            pre[i+1][j+cnt[i][1]] = j;
        }
    }
    if(!dp[nr][n2]){
        cout << "NO" << endl;
        return 0;
    }
    vector<bool> f(nr); // 2col=0
    int rem = n2;
    for(int i = nr-1; i >= 0; i--){
        int cur = pre[i+1][rem];
        if(rem-cur == cnt[i][0]){
            f[i] = true;
        }else{
            assert(rem-cur == cnt[i][1]);
        }
        rem = cur;
    }
    vector<int> ans(n);
    for(int i = 0; i < nr; i++){
        int r = roots[i];
        int c2 = f[i] ? 0 : 1;
        for(int v: components[r]){
            if(col[v] == c2){
                ans[v] = 2;
                n2--;
            }else{
                if(n1 > 0){
                    ans[v] = 1;
                    n1--;
                }else{
                    ans[v] = 3;
                    n3--;
                }
            }
        }
    }
    assert(n1 == 0);
    assert(n2 == 0);
    assert(n3 == 0);
    cout << "YES" << endl;
    for(int x: ans) cout << x;
    cout << endl;
}