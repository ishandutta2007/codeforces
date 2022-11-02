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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        if(s[i] == 'L') v[i] = 0;
        else v[i] = 1;
    }
    auto dp = vec3d(n, 4, 4, n);
    for(int i = 0; i < 4; i++){
        dp[1][i][i] = 0;
        for(int j = 0; j < 2; j++){
            int x = v[1-j];
            int y = i&(1<<j) ? 1 : 0;
            if(x != y) dp[1][i][i]++;
        }
    }
    auto ok = [&](int i, int x){
        int y = (i<<1)+x;
        if(y == 0 || y == 7) return false;
        return true;
    };
    auto nx = [&](int i, int x){
        return ((i<<1)&3)+x;
    };
    for(int i = 2; i < n; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++) {
                for(int l = 0; l < 2; l++){
                    if(!ok(k, l)) continue;
                    int add = l == v[i] ? 0 : 1;
                    chmin(dp[i][j][nx(k, l)], dp[i-1][j][k]+add);
                }
            }
        }
    }
    int ans = n;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int x = (j<<2)+i;
            if(x%8 == 0) continue;
            if(x%8 == 7) continue;
            if((x>>1) == 0) continue;
            if((x>>1) == 7) continue;
            chmin(ans, dp[n-1][i][j]);
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