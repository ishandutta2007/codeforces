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
using T = tuple<ll, ll, ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<T> vt(n);
    for(int i = 0; i < n; i++){
        ll a, b, k; cin >> a >> b >> k;
        vt[i] = T(b, a, k);
    }
    sort(vt.begin(), vt.end(), greater<T>());
    auto dp = vec2d(n+1, n+1, -inf);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        auto [b, a, k] = vt[i];
        for(int j = 0; j <= i; j++){
            // 
            chmax(dp[i+1][j], dp[i][j]);
            // 
            chmax(dp[i+1][j+1], dp[i][j]+a-b*j);
            // 
            chmax(dp[i+1][j], dp[i][j]+a-b*k);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= n; i++) chmax(ans, dp[n][i]);
    cout << ans << endl;
}