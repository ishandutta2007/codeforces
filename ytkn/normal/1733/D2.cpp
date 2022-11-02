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
const int N = 5005;

ll dp[N][N][2];

void solve(){
    int n; ll x, y; cin >> n >> x >> y;
    chmin(x, 2*y);
    string a, b; cin >> a >> b;
    bool ok = true;
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) {
            ok = !ok;
            v.push_back(i);
        }
    }
    if(!ok){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k < 2; k++){
                if(k == 1){
                    // 
                    if(a[i] != b[i]){
                        chmin(dp[i+1][j][0], dp[i][j][k]+x);
                    }else{
                        chmin(dp[i+1][j][1], dp[i][j][k]+x);
                    }
                }
                int inc = k;
                // 
                if(j > 0){
                    if(a[i] != b[i]){
                        chmin(dp[i+1][j+inc-1][0], dp[i][j][k]+y);
                    }else{
                        chmin(dp[i+1][j+inc-1][1], dp[i][j][k]+y);
                    }   
                }
                // 
                if(a[i] == b[i]){
                    chmin(dp[i+1][j+inc][0], dp[i][j][k]);
                }else{
                    chmin(dp[i+1][j+inc][1], dp[i][j][k]);
                }
            }
        }
    }
    cout << dp[n][0][0] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}