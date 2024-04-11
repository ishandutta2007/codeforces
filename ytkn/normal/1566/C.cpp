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

const int INF = 1e9;

int mex(int s){
    if(s == 0) return 0;
    if(s == 1) return 1; // 0
    if(s == 2) return 0; // 1
    if(s == 3) return 2;
}

void solve(){
    int n; cin >> n;
    auto a = vec2d(n, 2, 0);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            a[j][i] = c-'0';
        }
    }
    auto dp = vec2d(n+1, 4, -INF);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        int t = 0;
        t |= 1<<a[i][0];
        t |= 1<<a[i][1];
        for(int s = 0; s < 4; s++){
            chmax(dp[i+1][s|t], dp[i][s]);
            chmax(dp[i+1][0], dp[i][s]+mex(s|t));
        }
    }
    cout << dp[n][0] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}