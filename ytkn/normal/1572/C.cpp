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
    vector<int> a(n);
    vector<vector<int>> indices(n);
    for(int i = 0; i < n; i++){
        cin >> a[i]; a[i]--;
        indices[a[i]].push_back(i);
    }
    auto dp = vec2d(n+1, n+1, 0);
    for(int len = 2; len <= n; len++){
        for(int l = 0; l+len <= n; l++){
            int r = l+len;
            if(a[l] == a[r-1]){
                chmax(dp[l][r], dp[l+1][r-1]+1);
            }
            for(int c: indices[a[l]]){
                if(c <= l) continue;
                if(c >= r-1) continue;
                chmax(dp[l][r], dp[l][c+1]+dp[c][r]);
            }
            chmax(dp[l][r], dp[l+1][r]);
        }
    }
    cout << n-1-dp[0][n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}