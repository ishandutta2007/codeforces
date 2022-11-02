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
    vector<string> s(2);
    for(int i = 0; i < 2; i++) cin >> s[i];
    int l = n, r = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '*'){
                chmin(l, j);
                chmax(r, j);
            }
        }
    }
    auto dp = vec2d(n, 4, inf);
    int mm = 0;
    auto ok = [&](int i, int t){
        if(s[0][i] == '*'){
            if((t&1) == 0) return false;
        }
        if(s[1][i] == '*'){
            if((t&2) == 0) return false;
        }
        return true;
    };
    vector<int> p_cnt = {0, 1, 1, 2};
    for(int t = 0; t < 4; t++){
        if(ok(l, t)){
            dp[l][t] = p_cnt[t];
        }
    }
    for(int i = l+1; i <= r; i++){
        for(int t = 1; t <= 3; t++){
            for(int u = 1; u <= 3; u++){
                if((t&u) == 0) continue;
                if(!ok(i, u)) continue;
                chmin(dp[i][u], dp[i-1][t]+p_cnt[u]);
            }
        }
    }
    cout << (*min_element(dp[r].begin(), dp[r].end())) - 1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}