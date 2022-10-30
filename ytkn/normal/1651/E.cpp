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

void dfs(int v, vector<vector<int>> &g, vector<bool> &seen, vector<int> &component){
    seen[v] = true;
    component.push_back(v);
    for(int to: g[v]){
        if(seen[to]) continue;
        dfs(to, g, seen, component);
    }
}

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(2*n);
    for(int i = 0; i < 2*n; i++){
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> seen(2*n);
    vector<vector<int>> components(2*n);
    for(int i = 0; i < 2*n; i++){
        if(seen[i]) continue;
        dfs(i, g, seen, components[i]);
    }
    ll ans = 0;
    auto process = [&](vector<int> component){
        // print_vector(component);
        int M = component.size();
        assert(M%2 == 0);
        int a_min = inf, a_max = -inf;
        int b_min = inf, b_max = -inf;
        auto count = [&](int pre, int nx) -> ll{
            if(a_min <= pre && pre <= a_max) return 0;
            if(a_min <= nx && nx <= a_max) return 0;
            if(b_min <= pre && pre <= b_max) return 0;
            if(b_min <= nx && nx <= b_max) return 0;
            ll l_max = a_min, r_min = a_max;
            ll L_max = b_min, R_min = b_max;
            ll l_min = 0, r_max = n-1;
            ll L_min = n, R_max = 2*n-1;
            auto exclude = [&](int x){
                if(x == -1) return;
                if(x < n){
                    if(x < a_min) chmax<ll>(l_min, x+1);
                    else chmin<ll>(r_max, x-1);
                }else{
                    if(x < b_min) chmax<ll>(L_min, x+1);
                    else chmin<ll>(R_max, x-1);
                }
            };
            exclude(pre);
            exclude(nx);
            return (l_max-l_min+1)*(r_max-r_min+1)*(L_max-L_min+1)*(R_max-R_min+1);
        };
        for(int l = 0; l < M; l++){
            a_min = inf; a_max = -inf;
            b_min = inf; b_max = -inf;
            for(int len = 1; len <= M; len++){
                int r = (l+len-1)%M;
                if(component[r] < n){
                    chmin(a_min, component[r]);
                    chmax(a_max, component[r]);
                }else{
                    chmin(b_min, component[r]);
                    chmax(b_max, component[r]);
                }
                if(len >= 2 && len != M){
                    int pre = component[(l-1+M)%M];
                    int nx = component[(r+1)%M];
                    ans += (len/2)*count(pre, nx);
                }
            }
        }
        ans += (M/2)*count(-1, -1);
    };
    for(int i = 0; i < n; i++){
        if(components[i].empty()) continue;
        process(components[i]);
    }
    cout << ans << endl;
}