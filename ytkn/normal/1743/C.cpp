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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto dp = vec2d(n, 2, 0);
    if(s[0] == '0'){
        dp[0][0] = 0;
    }else{
        dp[0][1] = a[0];
    }
    for(int i = 1; i < n; i++){
        if(s[i] == '0'){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        }else{
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    if(j == 1 && k == 0) continue;
                    int added = k == 1 ? a[i] : a[i-1];
                    chmax(dp[i][k], dp[i-1][j]+added);
                }
            }
        }
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}