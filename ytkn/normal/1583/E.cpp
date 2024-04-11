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

void dfs(int v, vector<vector<int>> &g, vector<vector<int>> &tree, vector<bool> &seen){
    seen[v] = true;
    for(int to: g[v]){
        if(!seen[to]) {
            tree[v].push_back(to);
            tree[to].push_back(v);
            dfs(to, g, tree, seen);
        }
    }
}

bool find_path(int v, int to, vector<vector<int>> &g, vector<bool> &seen, vector<int> &path){
    seen[v] = true;
    if(v == to){
        path.push_back(to);
        return true;
    }
    for(int u: g[v]){
        if(!seen[u]) {
            if(find_path(u, to, g, seen, path)){
                path.push_back(v);
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int q; cin >> q;
    vector<int> a(q), b(q);
    vector<int> cnt(n);
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i]; a[i]--; b[i]--;
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(cnt[i]%2 == 1) sum++;
    }
    if(sum > 0){
        cout << "NO" << endl;
        cout << sum/2 << endl;
        return 0;
    }
    vector<bool> seen(n, false);
    vector<vector<int>> tree(n);
    dfs(0, g, tree, seen);
    cout << "YES" << endl;
    for(int i = 0; i < q; i++){
        vector<int> path;
        seen.assign(n, false);
        find_path(a[i], b[i], tree, seen, path);
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for(int x: path) cout << x+1 << ' ';
        cout << endl;
    }
}