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

int to_idx(char c){
    if(c == 'h') return 0;
    if(c == 'a') return 1;
    if(c == 'r') return 2;
    if(c == 'd') return 3;
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto dp = vec2d(n+1, 4, inf);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        int idx = to_idx(s[i]);
        for(int j = 0; j < 4; j++){
            if(idx == -1){
                chmin(dp[i+1][j], dp[i][j]);
            }
            if(j == idx){
                if(j != 3) chmin(dp[i+1][j+1], dp[i][j]);
                chmin(dp[i+1][j], dp[i][j]+a[i]);
            }else{
                chmin(dp[i+1][j], dp[i][j]);
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}