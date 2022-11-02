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

const int inf = 1e9;

void solve(){
    string s; cin >> s;
    int n = s.size();
    auto dp = vec2d(n+1, 5, inf);
    auto pre = vec2d(n+1, 5, inf);
    dp[0][0] = 0;
    auto calc_nx = [&](int pre, char c){
        if(pre == 1 && c == 'n') return 2;
        if(pre == 2 && c == 'e') return -1;
        if(pre == 3 && c == 'w') return 4;
        if(pre == 4 && c == 'o') return -1;
        if(c == 'o') return 1;
        if(c == 't') return 3;
        return 0;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            int nx = calc_nx(j, s[i]);
            if(nx != -1 && chmin(dp[i+1][nx], dp[i][j])) pre[i+1][nx] = j;
            if(chmin(dp[i+1][j], dp[i][j]+1)) pre[i+1][j] = j;
        }
    }
    int ans = n;
    int idx = -1;
    for(int j = 0; j < 5; j++){
        if(chmin(ans, dp[n][j])) idx = j;
    }
    vector<int> erased;
    for(int i = n-1; i >= 0; i--){
        int prev_idx = pre[i+1][idx];
        if(dp[i+1][idx] == dp[i][prev_idx]+1) erased.push_back(i);
        idx = prev_idx;
    }
    reverse(erased.begin(), erased.end());
    cout << ans << endl;
    for(int i: erased) cout << i+1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}