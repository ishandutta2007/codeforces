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

vector<vector<int>> tree_pair_distance(vector<vector<int>> g){
    int n = g.size();
    auto dist = vec2d(n, n, -1);
    function<void(int, int, int, int)> dfs = [&](int root, int v, int par, int d){
        dist[root][v] = d;
        for(int to: g[v]){
            if(to == par) continue;
            dfs(root, to, v, d+1);
        }
    };
    for(int i = 0; i < n; i++){
        dfs(i, i, -1, 0);
    }
    return dist;
}

using P = pair<int, int>;
const P not_found = P(-1, -1);

void solve(){
    int n; cin >> n;
    auto is_same = vec3d(n, n, n, false);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            string s; cin >> s;
            for(int k = 0; k < n; k++){
                if(s[k] == '1'){
                    is_same[i][j][k] = true;
                    is_same[j][i][k] = true;
                }
            }
        }
    }
    
    auto verify = [&](vector<P> ans) -> bool{
        if(ans.size() != n-1) return false;
        vector<vector<int>> g(n);
        for(auto [x, y]: ans){
            g[x].push_back(y);
            g[y].push_back(x);
        }
        auto dist = tree_pair_distance(g);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = 0; k < n; k++){
                    if(is_same[i][j][k] && dist[i][k] != dist[j][k]) return false;
                    if(!is_same[i][j][k] && dist[i][k] == dist[j][k]) return false;
                }
            }
        }
        return true;
    };
    
    auto sub_solve = [&](int v) -> vector<P>{
        vector<P> ans;
        vector<bool> used(n);
        used[v] = true;
        used[0] = true;
        function<void(int, int)> dfs = [&](int v, int par){
            for(int to = 0; to < n; to++){
                if(to == par) continue;
                if(used[to]) continue;
                if(is_same[par][to][v]){
                    used[to] = true;
                    ans.push_back(P(to, v));
                    dfs(to, v);
                }
            }
        };
        ans.push_back(P(0, v));
        dfs(0, v);
        dfs(v, 0);
        return ans;
    };
    for(int i = 1; i < n; i++){
        auto edges = sub_solve(i);
        if(verify(edges)){
            cout << "Yes" << endl;
            for(auto [x, y]: edges) cout << x+1 << ' ' << y+1 << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}