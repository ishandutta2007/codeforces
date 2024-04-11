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

void solve(){
    int n, k, z; cin >> n >> k >> z;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto dp = vec3d(k+1, z+1, 2, 0);
    dp[0][0][0] = a[0];
    for(int i = 0; i < k; i++){
        for(int j = 0; j <= z; j++){
            int idx = i-2*j;
            if(idx < 0) continue;
            if(j < z && idx > 0){
                chmax(dp[i+1][j+1][1], dp[i][j][0]+a[idx-1]);
            }
            chmax(dp[i+1][j][0], dp[i][j][0]+a[idx+1]);
            chmax(dp[i+1][j][0], dp[i][j][1]+a[idx+1]);
        }
    }
    int ans = 0;
    for(int j = 0; j <= z; j++){
        chmax(ans, dp[k][j][0]);
        chmax(ans, dp[k][j][1]);
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