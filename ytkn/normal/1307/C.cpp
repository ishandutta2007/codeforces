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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string s; cin >> s;
    ll n = s.size();
    auto dp = vec2d(26, 26, 0ll);
    vector<ll> cnt(26);
    for(int i = 0; i < n; i++){
        cnt[s[i]-'a']++;
    }
    ll ans = *max_element(cnt.begin(), cnt.end());
    for(int i = 0; i < n; i++){
        int k = s[i]-'a';
        cnt[k]--; 
        for(int j = 0; j < 26; j++){
            dp[k][j] += cnt[j];
        }
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            chmax(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}