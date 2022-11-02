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

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    vector<int> n(4);
    for(int i = 0; i < 4; i++) cin >> n[i];
    vector<vector<ll>> costs(4);
    for(int i = 0; i < 4; i++){
        costs[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++) cin >> costs[i][j];
    }
    vector<vector<ll>> dp(4);
    for(int i = 0; i < 4; i++){
        dp[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++){
            dp[i][j] = inf;
        }
    }
    for(int j = 0; j < n[0]; j++) dp[0][j] = costs[0][j];
    for(int i = 0; i < 3; i++){
        int m; cin >> m;
        vector<vector<int>> bad(n[i+1]);
        for(int j = 0; j < m; j++){
            int x, y; cin >> x >> y; x--; y--;
            bad[y].push_back(x);
        }
        multiset<ll> st;
        for(int j = 0; j < n[i]; j++) st.insert(dp[i][j]);
        for(int j = 0; j < n[i+1]; j++){
            for(int x: bad[j]){
                st.erase(st.find(dp[i][x]));
            }
            if(!st.empty()){
                ll x = *st.begin();
                chmin(dp[i+1][j], x+costs[i+1][j]);
            }
            for(int x: bad[j]){
                st.insert(dp[i][x]);
            }
        }
    }
    ll ans = *min_element(dp[3].begin(), dp[3].end());
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}