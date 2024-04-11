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

const ll inf = 1e18;
using Arr2 = array<ll, 2>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<Arr2> dp1(n);
    function<void(int, int)> dfs1 = [&](int v, int par){
        vector<Arr2> u;
        for(int to: g[v]){
            if(to == par) continue;
            dfs1(to, v);
            u.push_back(dp1[to]);
        }
        if(u.empty()){
            dp1[v][0] = c[v];
            dp1[v][1] = 0;
        }else{
            ll max_gain = -inf;
            ll sum = 0;
            for(auto a: u){
                sum += a[0];
                chmax(max_gain, a[0]-a[1]);
            }
            dp1[v][0] = min(sum-max_gain+c[v], sum);
            dp1[v][1] = sum-max_gain;
        }
    };
    dfs1(0, -1);
    ll min_cost = dp1[0][0];
    vector<bool> ok(n);
    auto dp2 = vec2d(n, 2, false);
    function<void(int, int)> dfs2 = [&](int v, int par){
        vector<int> ch;
        for(int to: g[v]){
            if(to == par) continue;
            ch.push_back(to);
        }
        if(ch.empty()){
            if(dp2[v][0]){
                ok[v] = true;
            }
        }else{
            ll max_gain = -inf;
            int cnt_max_gain = 0;
            ll sum = 0;
            for(auto u: ch){
                sum += dp1[u][0];
                if(max_gain < dp1[u][0]-dp1[u][1]){
                    max_gain = dp1[u][0]-dp1[u][1];
                    cnt_max_gain = 0;
                }
                if(max_gain == dp1[u][0]-dp1[u][1]){
                    cnt_max_gain++;
                }
            }
            if(dp2[v][0]){
                if(sum-max_gain+c[v] == dp1[v][0]) { // v
                    ok[v] = true;
                    for(int u: ch) {
                        ll gain = dp1[u][0]-dp1[u][1];
                        if(gain != max_gain) dp2[u][0] = true;
                        if(gain == max_gain){
                            dp2[u][1] = true;
                            if(cnt_max_gain > 1) dp2[u][0] = true;
                        }
                    }
                }
                if(sum == dp1[v][0]){
                    for(int u: ch) dp2[u][0] = true;
                }
            }
            if(dp2[v][1]){
                for(int u: ch) {
                    ll gain = dp1[u][0]-dp1[u][1];
                    if(gain != max_gain) dp2[u][0] = true;
                    if(gain == max_gain){
                        dp2[u][1] = true;
                        if(cnt_max_gain > 1) dp2[u][0] = true;
                    }
                }
            }
            for(int u: ch) dfs2(u, v);
        }
    };
    dp2[0][0] = true;
    dfs2(0, -1);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(ok[i]) cnt++;
    }
    cout << min_cost << ' ' << cnt << endl;
    for(int i = 0; i < n; i++) {
        if(ok[i]) cout << i+1 << ' ';
    }
    cout << endl;
}