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

const int N = 1000000;

using P = pair<int, int>;
vector<int> g[N];
map<int, int> mp[N];
int n, k;

void dfs(int v, int par, int d){
    bool is_leaf = g[v].size() == 1;
    if(is_leaf){
        mp[v][d] = 1;
    }
    for(int to: g[v]){
        if(to == par) continue;
        dfs(to, v, d+1);
        bool swapped = false;
        if(mp[to].size() > mp[v].size()){
            swap(to, v);
            swapped = true;
        }
        vector<P> adds;
        for(auto [depth, cnt]: mp[to]){
            int max_depth = k+2*d-depth;
            auto p = mp[v].upper_bound(max_depth);
            if(p == mp[v].begin()){
                adds.push_back(P(depth, cnt));
            }else{
                p--;
                auto [depth1, cnt1] = *p;
                // 
                if(depth1 < depth){
                    assert(cnt1 == 1);
                    adds.push_back(P(depth, cnt));
                    mp[v].erase(depth1);
                }else{
                    assert(cnt == 1);
                    // 
                }
            }
        }
        for(auto [depth, cnt]: adds){
            if(mp[v].count(depth)) mp[v][depth] += cnt;
            else mp[v][depth] = cnt;
        }
        if(swapped){
            swap(to, v);
            mp[v] = move(mp[to]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(g[i].size() == 1){
            dfs(i, -1, 0);
            int ans = 0;
            for(auto [x, cnt]: mp[i]) ans += cnt;
            cout << ans << endl;
            return 0;
        }
    }
}