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

const int inf = 2e9;
int dp[401][401][401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int l = 0; l < n; l++){
        for(int r = l+1; r < n; r++){
            dp[l][r][1] = dp[l][r-1][1]+a[r]-a[r-1];
            for(int cnt = 2; cnt <= r-l; cnt++) dp[l][r][cnt] = inf;
        }
    }
    for(int cnt = 2; cnt <= n-1; cnt++){
        for(int l = 0; l < n; l++){
            int r = l+1;
            for(int c = l+1; c < n; c++){
                while(r+1 < n && dp[c][r+1][cnt-1] <= dp[l][c][1]) r++;
                chmin(dp[l][r][cnt], dp[l][c][1]);
            }
        }
        for(int r = n-1; r >= 0; r--){
            int l = r-(cnt-1);
            for(int c = r-(cnt-1); c >= 0; c--){
                while(l-1 >= 0 && dp[l-1][c][1] <= dp[c][r][cnt-1]) l--;
                chmin(dp[l][r][cnt], dp[c][r][cnt-1]);
            }
        }
        for(int len = n-1; len >= 1; len--){
            for(int l = 0; l+len < n; l++){
                int r = l+len;
                if(r+1 < n) chmin(dp[l][r][cnt], dp[l][r+1][cnt]);
                if(l-1 >= 0) chmin(dp[l][r][cnt], dp[l-1][r][cnt]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < m; i++){
        int s, f, c, r; cin >> s >> f >> c >> r; s--; f--;
        chmin(r, f-s-1);
        chmax(ans, (ll)dp[s][f][r+1]*c);
        // cout << dp[s][f][r+1]*c << endl;
    }
    cout << ans << endl;
}