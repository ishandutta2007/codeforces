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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> cnt(m+1);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        cnt[a]++;
    }
    auto dp = vec3d(2, 5, 5, -inf);
    dp[0][0][0] = 0;
    for(int i = 0; i < m; i++){
        int pre = i%2;
        int cur = pre^1;
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                dp[cur][j][k] = -inf;
            }
        }
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                if(dp[pre][j][k] < 0) continue;
                for(int l = 0; l <= k; l++){
                    if(k-l > cnt[i+1]) continue;
                    if(k-l > j) continue;
                    int rem = cnt[i+1]-(k-l);
                    int nx = rem%3;
                    chmax(dp[cur][l][nx], dp[pre][j][k]+rem/3+k-l);
                    if(rem >= 3){
                        chmax(dp[cur][l][min(nx+3, 4)], dp[pre][j][k]+rem/3-1+k-l);
                    }
                    if(rem >= 6){
                        chmax(dp[cur][l][min(nx+6, 4)], dp[pre][j][k]+rem/3-2+k-l);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            chmax(ans, dp[m%2][i][j]);
        }
    }
    cout << ans << endl;
}