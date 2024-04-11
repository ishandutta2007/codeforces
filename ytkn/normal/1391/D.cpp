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

int solve(vector<string> s){
    int n = s.size(), m = s[0].size();
    auto ok = vec2d(1<<n, 1<<n, true);
    auto v = vec2d(2, n, 0);
    vector<int> popcount(1<<n);
    for(int s = 0; s < (1<<n); s++){
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) popcount[s]++;
        }
    }
    for(int s = 0; s < (1<<n); s++){
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) {
                v[0][i] = 1;
            }else{
                v[0][i] = 0;
            }
        }
        for(int t = 0; t < (1<<n); t++){
            for(int i = 0; i < n; i++){
                if(t&(1<<i)) {
                    v[1][i] = 1;
                }else{
                    v[1][i] = 0;
                }
            }
            for(int i = 0; i+1 < n; i++){
                int cnt = v[0][i]+v[1][i]+v[0][i+1]+v[1][i+1];
                if(cnt%2 == 0) ok[s][t] = false;
            }
        }
    }
    auto dp = vec2d(m, 1<<n, inf);
    int x = 0;
    for(int j = 0; j < n; j++){
        if(s[j][0] == '1') x += (1<<j);
    }
    for(int i = 0; i < (1<<n); i++){
        dp[0][i] = popcount[x^i];
    }
    for(int i = 1; i < m; i++){
        int x = 0;
        for(int j = 0; j < n; j++){
            if(s[j][i] == '1') x += (1<<j);
        }
        for(int j = 0; j < (1<<n); j++){
            for(int k = 0; k < (1<<n); k++){
                if(!ok[j][k]) continue;
                chmin(dp[i][k], dp[i-1][j]+popcount[x^k]);
            }
        }
    }
    return *min_element(dp[m-1].begin(), dp[m-1].end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    if(min(n, m) >= 4){
        cout << -1 << endl;
        return 0;
    }
    if(n > m){
        vector<string> t(m, string(n, '0'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                t[j][i] = s[i][j];
            }
        }
        cout << solve(t) << endl;
    }else{
        cout << solve(s) << endl;
    }
}