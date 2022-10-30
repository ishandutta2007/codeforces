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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto dp = vec2d(n+1, n+1, -1);
    for(int i = 0; i < n; i++) dp[i][i+1] = a[i];
    for(int len = 2; len <= n; len++){
        for(int l = 0; l+len <= n; l++){
            int r = l+len;
            for(int c = l+1; c < r; c++){
                if(dp[l][c] == -1) continue;
                if(dp[l][c] == dp[c][r]) dp[l][r] = dp[l][c]+1;    
            }
        }
    }
    vector<int> dist(n+1, 2*n);
    dist[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(dp[i][j] == -1) continue;
            chmin(dist[j], dist[i]+1);
        }
    }
    cout << dist[n] << endl;
}