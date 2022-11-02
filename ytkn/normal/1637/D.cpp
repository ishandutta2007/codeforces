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

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    auto dp = vec2d(n+1, n*100+1, false);
    dp[0][0] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 100*i; j++){
            if(dp[i][j]){
                dp[i+1][j+a[i]] = true;
                dp[i+1][j+b[i]] = true;
            }
        }
    }
    ll offset = 0;
    for(int i = 0; i < n; i++){
        offset += (n-1)*a[i]*a[i];
        offset += (n-1)*b[i]*b[i];
    }ll sum_sq = 0;
    for(int i = 0; i < n; i++){
        sum_sq += a[i]*a[i];
        sum_sq += b[i]*b[i];
    }
    ll ans = inf;
    offset -= sum_sq;
    ll sum = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
    for(int x = 0; x <= 100*n; x++){
        ll y = sum-x;
        if(dp[n][x]){
            ll tmp = offset;
            tmp += x*x+y*y;
            chmin(ans, tmp);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}