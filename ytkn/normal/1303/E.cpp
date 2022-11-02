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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<bool> used(n);
    vector<bool> ok(m);
    int idx = 0;
    auto sub_solve = [&](int c) -> bool{
        string a, b;
        for(int i = 0; i < c; i++) a += t[i];
        for(int i = c; i < m; i++) b += t[i];
        auto dp = vec2d(n+1, a.size()+1, -1);
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= a.size(); j++){
                if(dp[i][j] == -1) continue;
                chmax(dp[i+1][j], dp[i][j]);
                if(j < a.size() && s[i] == a[j]){
                    chmax(dp[i+1][j+1], dp[i][j]);
                }
                if(dp[i][j] < b.size() && s[i] == b[dp[i][j]]){
                    chmax(dp[i+1][j], dp[i][j]+1);
                }
            }
        }
        return dp[n][a.size()] == b.size();
    };
    for(int i = 0; i < m; i++){
        if(sub_solve(i)){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}