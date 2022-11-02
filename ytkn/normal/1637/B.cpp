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

int mex(vector<int> &v){
    set<int> st;
    for(int x: v) st.insert(x);
    for(int i = 0; ; i++){
        if(st.count(i) == 0){
            return i;
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto u = vec2d(n+1, n+1, 0);
    for(int l = 0; l < n; l++){
        vector<int> v;
        for(int r = l+1; r <= n; r++){
            v.push_back(a[r-1]);

            u[l][r] = mex(v);
        }
    }
    auto dp = vec2d(n+1, n+1, 0);
    ll ans = 0;
    for(int l = 0; l < n; l++){
        for(int r = l+1; r <= n; r++){
            for(int c = l; c < r; c++){
                chmax(dp[l][r], dp[l][c]+u[c][r]+1);
            }
            ans += dp[l][r];
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