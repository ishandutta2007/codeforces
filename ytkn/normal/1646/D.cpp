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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n == 2){
        cout << 2 << ' ' << 2 << endl;
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
    auto sum = vec2d(n, 2, 0ll);
    auto cnt = vec2d(n, 2, 0ll);
    function<void(int, int)> dfs = [&](int v, int par){
        cnt[v][0] = 0;
        sum[v][0] = 1;
        cnt[v][1] = 1;
        sum[v][1] = g[v].size();
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v);
            auto prev_cnt = cnt[v];
            auto prev_sum = sum[v];
            cnt[v][0] = 0;
            cnt[v][1] = 0;
            sum[v][0] = inf;
            sum[v][1] = inf;
            for(int a = 0; a < 2; a++){
                for(int b = 0; b < 2; b++){
                    if(a == 1 && b == 1) continue;
                    if(cnt[v][a] < prev_cnt[a]+cnt[to][b]){
                        cnt[v][a] = prev_cnt[a]+cnt[to][b];
                        sum[v][a] = prev_sum[a]+sum[to][b];
                    }else if(cnt[v][a] == prev_cnt[a]+cnt[to][b]){
                        chmin(sum[v][a], prev_sum[a]+sum[to][b]);
                    }
                }
            }
        }
    };
    dfs(0, -1);
    int x = [&](){
        if(cnt[0][0] > cnt[0][1]) return 0;
        if(cnt[0][0] < cnt[0][1]) return 1;
        if(sum[0][0] < sum[0][1]) return 0;
        else return 1;
    }();
    vector<int> ans(n);
    function<void(int, int, int)> dfs_ans = [&](int v, int par, int x){
        if(x == 0){
            ans[v] = 1;
        }else{
            ans[v] = g[v].size();
        }
        for(int to: g[v]){
            if(to == par) continue;
            if(x == 0){
                if(cnt[to][0] > cnt[to][1]){
                    dfs_ans(to, v, 0);
                }else if(cnt[to][0] < cnt[to][1]){
                    dfs_ans(to, v, 1);
                }else{
                    if(sum[to][0] < sum[to][1]){
                        dfs_ans(to, v, 0);
                    }else{
                        dfs_ans(to, v, 1);
                    }
                }
            }else{
                dfs_ans(to, v, 0);
            }
        }
    };
    dfs_ans(0, -1, x);
    cout << cnt[0][x] << ' ' << sum[0][x] << endl;
    print_vector(ans);
}