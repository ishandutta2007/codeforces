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

ll dp[101][101][101];

vector<ll> f(vector<ll> a){
    int n = a.size()-1;
    vector<ll> b = a;
    for(int sum = 2; sum <= n; sum++){
        for(int x = 1; x < sum; x++){
            int y = sum-x;
            chmax(b[sum], b[x]+b[y]);
        }
    }
    return b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    // a = f(a);
    for(int len = 1; len <= n; len++){
        for(int l = 0; l+len <= n; l++){
            int r = l+len;
            for(int x = 0; x <= l; x++){
                // 
                chmax(dp[x][l][r], dp[0][l+1][r]+a[x+1]);
                // 
                for(int c = l+1; c < r; c++){
                    if(s[c] == s[l]){
                        chmax(dp[x][l][r], dp[x+1][c][r]+dp[0][l+1][c]);
                    }
                }
            }
        }
    }
    cout << dp[0][0][n] << endl;
}