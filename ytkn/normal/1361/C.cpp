#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

vector<int> EulerianTrail(const int s, vector<multiset<int>> &g, const bool directed) {
    function<void (int, vector<int> &)> dfs = [&](int u, vector<int> &trail) {
        while (!g[u].empty()) {
            int v = *g[u].begin();
            g[u].erase(g[u].find(v));
            if (!directed) {
                for (int x : g[v]) {
                    if (x == u) {
                        g[v].erase(g[v].find(x));
                        break;
                    }
                }
            }
            dfs(v, trail);
        }
        trail.push_back(u);
    };
    vector<int> trail;
    dfs(s, trail);
    reverse(trail.begin(), trail.end());
    return trail;
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

struct HashPair {

    // const
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {

        //first
        auto hash1 = hash<T1>{}(p.first);

        //second
        auto hash2 = hash<T2>{}(p.second);

        //
        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> p(2*n);
    for(int i = 0; i < 2*n; i++) cin >> p[i];
    auto judge = [&](int x){
        UnionFind uf(1<<x);
        int m = (1<<x)-1;
        vector<vector<int>> g(1<<x);
        vector<bool> used(1<<x);
        int cnt = 0;
        int example = -1;
        // cout << "===" << endl;
        for(int i = 0; i < 2*n; i+=2){
            int a = p[i]&m;
            int b = p[i+1]&m;
            example = a;
            g[a].push_back(b);
            g[b].push_back(a);
            uf.unionSet(a, b);
            if(!used[a]) {
                cnt++;
                used[a] = true;
            }
            if(!used[b]) {
                cnt++;
                used[b] = true;
            }
            // cout << a << '-' << b << endl;
        }
        if(uf.size(example) != cnt) return false;
        bool ok = true;
        for(int i = 0; i < (1<<x); i++){
            if(g[i].size()%2 == 1) ok = false;
        }
        return ok;
    };
    int x = -1;
    if(judge(20)){
        x = 20;
    }else{
        int l = 0, r = 20;
        while(r-l > 1){
            int c = (l+r)/2;
            if(judge(c)) l = c;
            else r = c;
        }
        x = l;
    }
    cout << x << endl;
    int m = (1<<x)-1;
    vector<multiset<int>> g(1<<x);
    int example = -1;
    for(int i = 0; i < 2*n; i+=2){
        int a = p[i]&m;
        int b = p[i+1]&m;
        example = a;
        g[a].insert(b);
        g[b].insert(a);
    }
    vector<int> path = EulerianTrail(example, g, false);

    unordered_map<P, unordered_set<int>, HashPair> mp;
    for(int i = 0; i < 2*n; i+=2){
        int a = p[i]&m;
        int b = p[i+1]&m;
        if(a > b) swap(a, b);
        mp[P(a, b)].insert(i);
    }
    int len = path.size();
    for(int i = 1; i < len; i++){
        P e = (path[i-1] <= path[i] ? P(path[i-1], path[i]) : P(path[i], path[i-1]));
        int idx = *mp[e].begin();
        assert(!mp[e].empty());
        mp[e].erase(idx);
        if(path[i-1] == (p[idx]&m)){
            cout << idx+1 << ' ' << idx+2 << ' ';
        }else{
            cout << idx+2 << ' ' << idx+1 << ' ';
        }
    }
    cout << endl;
}