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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    auto dp = vec2d(n+1, n+1, inf);
    dp[0][0] = 0;
    vector<int> t_count(26);
    for(int i = 0; i < n; i++){
        vector<int> s_count(26);
        for(int j = 0; j <= n; j++){
            if(t[i] == s[j] && j < n){
                chmin(dp[i+1][j+1], dp[i][j]);
            }
            int idx = t[i]-'a';
            if(s_count[idx] > t_count[idx]){
                chmin(dp[i+1][j], dp[i][j]+1);
            }
            if(j < n) chmin(dp[i][j+1], dp[i][j]);
            if(j < n) s_count[s[j]-'a']++;
        }
        t_count[t[i]-'a']++;
        // print_vector(dp[i]);
    }
    // print_vector(dp[n]);
    // cout << s << "->" << t << endl;
    if(dp[n][n] == inf) cout << -1 << endl;
    else cout << dp[n][n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}