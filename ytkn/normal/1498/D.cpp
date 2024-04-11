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

// calc ceil(a/b) 
template<typename T>
T ceil_div(T a, T b){
    return (a+b-1)/b;
}

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n, m; cin >> n >> m;
    auto dp = vec2d(2, m+1, inf);
    dp[0][0] = 0;
    vector<int> ans(m+1, -1);
    const ll M = 100000;
    for(int i = 0; i < n; i++){
        int pre = i%2;
        int cur = pre^1;
        for(int j = 0; j <= m; j++){
            if(dp[pre][j] == inf){
                dp[cur][j] = inf;
            }else{
                dp[cur][j] = 0;
            }
        }
        ll t, x, y; cin >> t >> x >> y;
        if(t == 1){
            for(int j = 0; j <= m; j++){
                int nx = j+ceil_div(x, M);
                if(dp[cur][j] < y && nx <= m){
                    chmin(dp[cur][nx], dp[cur][j]+1);
                }
            }
        }else{
            for(int j = 0; j <= m; j++){
                ll nx = ceil_div((ll)j*x, (ll)M);
                if(dp[cur][j] < y && nx <= m){
                    chmin(dp[cur][nx], dp[cur][j]+1);
                }
            }
        }
        for(int j = 1; j <= m; j++){
            if(dp[cur][j] != inf){
                if(ans[j] == -1) {
                    ans[j] = i+1;   
                }
            }
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    cout << endl;
}