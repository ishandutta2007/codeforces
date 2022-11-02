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
    string s, t, p; cin >> s >> t >> p;
    vector<int> s_cnt(26), t_cnt(26), p_cnt(26);
    for(char c: s) s_cnt[c-'a']++;
    for(char c: t) t_cnt[c-'a']++;
    for(char c: p) p_cnt[c-'a']++;
    for(int i = 0; i < 26; i++){
        if(s_cnt[i]+p_cnt[i] < t_cnt[i]){
            cout << "NO" << endl;
            return;
        }
    }
    int n = s.size();
    int m = t.size();
    vector<int> dp(m+1, 0);
    for(int i = 0; i < m; i++){
        dp[i+1] = dp[i];
        if(dp[i] < n && s[dp[i]] == t[i]) dp[i+1] = dp[i]+1;
    }
    if(dp[m] == n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}