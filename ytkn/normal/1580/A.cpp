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
    int n, m; cin >> n >> m;
    auto a = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            a[i][j] = c-'0';
        }
    }
    auto a_cumsum = vec2d(n+1, m+1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a_cumsum[i+1][j+1] = a_cumsum[i+1][j]+a_cumsum[i][j+1]-a_cumsum[i][j]+a[i][j];
        }
    }
    auto sect_sum = [&](int i1, int j1, int i2, int j2){
        return a_cumsum[i2+1][j2+1] - a_cumsum[i1][j2+1] - a_cumsum[i2+1][j1] + a_cumsum[i1][j1];
    };
    int ans = 16;
    auto f = [&](int i, int j, int k){
        // cout << i << ' ' << j << ' ' <<  k << endl;
        int flip = (k-j-1) - sect_sum(i, j+1, i, k-1);
        // debug_value(flip);
        for(int l = i+1; l < n; l++){
            if(l >= i+4){
                int tmp = flip + (k-j-1) - sect_sum(l, j+1, l, k-1);
                chmin(ans, tmp);
                // cout << l << ' ' << tmp << ' ' << flip << endl;
            }
            if(a[l][j] != 1) flip++;
            if(a[l][k] != 1) flip++;
            flip += sect_sum(l, j+1, l, k-1);
            // debug_value(flip);
            if(flip > ans) return;
        }
    };
    for(int i = 0; i+5 <= n; i++){
        for(int j = 0; j+4 <= m; j++){
            for(int k = j+3; k < m; k++){
                f(i, j, k);
            }
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