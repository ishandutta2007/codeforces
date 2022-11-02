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

int dp[200005][2][4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<string> s(2);
    for(int i = 0; i < 2; i++) {
        cin >> s[i];
        s[i] = s[i]+'0';
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 2; j++){
            for(int t = 0; t < 4; t++){
                dp[i][j][t] = inf;
            }
        }
    }
    int cnt = 0;
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < n; i++){
            if(s[j][i] == '1') cnt++;
        }
    }
    dp[0][0][3] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            for(int t = 0; t < 4; t++){
                bool x = (t&(1<<(j^1))) > 0 && s[j^1][i] == '1';
                bool y = s[j][i+1] == '1';
                if(x && y){
                    // 
                    chmin(dp[i+1][j][3], dp[i][j][t]+1);
                    // 
                    int t_nx = 3-(1<<j);
                    chmin(dp[i+1][j^1][t_nx], dp[i][j][t]+1);
                }else if(x){
                    // 
                    chmin(dp[i+1][j][3], dp[i][j][t]+1);
                    // 
                    chmin(dp[i+1][j^1][3], dp[i][j][t]);
                }else{
                    // 
                    chmin(dp[i+1][j][3], dp[i][j][t]);
                }
            }            
        }
    }
    // cout << dp[3][0][3] << endl;
    // for(int j = 0; j < 2; j++){
    //     for(int i = 0; i <= n; i++){
    //         cout << dp[i][j][3] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << cnt-min(dp[n][0][3], dp[n][1][3]) << endl;
}