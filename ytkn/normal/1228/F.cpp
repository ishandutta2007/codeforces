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

vector<int> tree_diameter(vector<vector<int>> g){
    int n = g.size();
    vector<bool> used(n, false);
    vector<int> dist(n);
    auto clear = [&](){
        for(int i = 0; i < n; i++) used[i] = false;
    };
    auto dfs = [&](auto&& f, int v, int d) -> void{
        used[v] = true;
        dist[v] = d;
        for(int to : g[v]){
            if(!used[to]) f(f, to, d+1);
        }
    };
    dfs(dfs, 0, 0);
    int s = 0;
    for(int i = 0; i < n; i++){
        if(dist[s] < dist[i]) s = i;
    }
    clear();
    dfs(dfs, s, 0);
    int t = 0;
    for(int i = 0; i < n; i++){
        if(dist[t] < dist[i]) t = i;
    }
    int v = t;
    vector<int> path;
    path.push_back(t);
    while(v != s){
        for(int to : g[v]){
            if(dist[to] == dist[v]-1) {
                v = to;
                break;
            }
        }
        path.push_back(v);
    }
    return path;
}

int is_perfect_binary_tree_dfs(int v, vector<bool> &seen, vector<vector<int>> &g){
    seen[v] = true;
    int cnt = 0;
    int depth = -1;
    for(int to: g[v]){
        if(seen[to]) continue;
        cnt++;
        int d = is_perfect_binary_tree_dfs(to, seen, g);
        if(d == -1) return -1;
        if(depth == -1){
            depth = d;
        }else if(depth != d){
            return -1;
        }
    }
    if(cnt > 0 && cnt != 2) return -1;
    return depth+1;
}

bool is_perfect_binary_tree(vector<vector<int>> &g){
    int n = g.size();
    for(int i = 0; i < n; i++){
        if(g[i].size() == 2) {
            vector<bool> seen(n);
            return is_perfect_binary_tree_dfs(i, seen, g) != -1;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int m = 1<<n;
    vector<vector<int>> g(m-2);
    for(int i = 0; i < m-3; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n == 2){
        cout << 2 << endl;
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    vector<int> cnt(5);
    for(int i = 0; i < m-2; i++) {
        if(g[i].size() > 4) {
            cout << 0 << endl;
            return 0;
        }
        cnt[g[i].size()]++;
    }
    auto maybe_root_erased = [&](){
        return cnt[2] == 0 && cnt[4] == 0;
    };
    auto maybe_middle_erased = [&](){
        return cnt[2] == 1 && cnt[4] == 1;
    };
    auto maybe_leaf_erased = [&](){
        return cnt[2] == 2 && cnt[4] == 0;
    };
    vector<int> ans;
    if(maybe_root_erased()){
        auto diam = tree_diameter(g);
        if(diam.size()%2 == 1){
            cout << 0 << endl;
            return 0;
        }
        vector<int> root = {diam[diam.size()/2-1], diam[diam.size()/2]};
        for(int i = 0; i < 2; i++){
            int r = root[i];
            int other = root[i^1];
            vector<vector<int>> h(m-1);
            for(int i = 0; i < m-2; i++){
                for(int j: g[i]) {
                    if(i == other || j == other){
                        h[i].push_back(j);
                    }else if(i == r){
                        continue;
                    }else if(j == r){
                        h[i].push_back(m-2);
                        h[m-2].push_back(i);
                    }else{
                        h[i].push_back(j);
                    }
                }
            }
            h[r].push_back(m-2);
            h[m-2].push_back(r);
            if(is_perfect_binary_tree(h)) ans.push_back(r);
        }
    }else if(maybe_middle_erased()){
        int candidate = [&](){
            for(int i = 0; i < m-2; i++){
                if(g[i].size() == 4) return i;
            }
            assert(false);
        }();
        bool ok = false;
        for(int s = 0; s < 16; s++){
            vector<int> children;
            for(int i = 0; i < 4; i++){
                if(s&(1<<i)) children.push_back(g[candidate][i]);
            }
            if(children.size() != 2) continue;
            vector<vector<int>> h(m-1);
            for(int i = 0; i < m-2; i++){
                for(int j: g[i]) {
                    if(i == candidate && (j == children[0] || j == children[1])){
                        continue;
                    }
                    if(j == candidate && (i == children[0] || i == children[1])){
                        continue;
                    }
                    h[i].push_back(j);
                }
            }
            h[candidate].push_back(m-2);
            h[m-2].push_back(candidate);
            for(int ch: children){
                h[ch].push_back(m-2);
                h[m-2].push_back(ch);
            }
            if(is_perfect_binary_tree(h)) {
                ok = true;
                break;
            }
        }
        if(ok) ans.push_back(candidate);
    }else if(maybe_leaf_erased()){
        vector<int> candidates;
        for(int i = 0; i < m-2; i++){
            if(g[i].size() == 2) candidates.push_back(i);
        }
        for(int v: candidates){
            vector<vector<int>> h(m-1);
            for(int i = 0; i < m-2; i++){
                for(int j: g[i]) h[i].push_back(j);
            }
            h[v].push_back(m-2);
            h[m-2].push_back(v);
            if(is_perfect_binary_tree(h)) ans.push_back(v);
        }
    }

    if(ans.empty()){
        cout << 0 << endl;
    }else{
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        for(int v: ans) cout << v+1 << ' ';
        cout << endl;
    }
}