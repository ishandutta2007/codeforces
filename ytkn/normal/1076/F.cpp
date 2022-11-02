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

using P = pair<int, int>;
const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; ll k; cin >> n >> k;
    auto x = vec2d(n, 2, 0ll);
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++) {
            cin >> x[i][j];
        }
    }
    auto dp = vec2d(n+1, 2, inf);
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            if(dp[i][j] > k || (i > 0 && dp[i][j] == 0)) continue;
            ll a = x[i][j], b = x[i][j^1];
            // lastt
            { // 
                ll min_f = ceil_div(b, k), max_f = b;
                ll min_t = min_f-1, max_t = (max_f-1)*k;
                if(a-1 >= min_t){
                    ll max_rem = min(a-1, max_t);
                    ll mn = max(1ll, a-max_rem-(k-dp[i][j]));
                    chmin(dp[i+1][j], mn);
                }
            }
            { // 
                ll min_t = a+dp[i][j] <= k ? 1 : ceil_div(a-(k-dp[i][j]), k)+1;
                ll max_t = a+1;
                ll min_f = min_t-1, max_f = (max_t-1)*k;
                if(b-1 >= min_f){
                    ll max_rem = min(b-1, max_f);
                    ll mn = max(1ll, b-max_rem);
                    chmin(dp[i+1][j^1], mn);
                }
            }
        }
    }
    // for(int j = 0; j < 2; j++){
    //     for(int i = 0; i <= n; i++) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }
    if(dp[n][0] <= k || dp[n][1] <= k) cout << "YES" << endl;
    else cout << "NO" << endl;
}