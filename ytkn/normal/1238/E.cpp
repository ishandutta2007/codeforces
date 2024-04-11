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
    string s; cin >> s;
    auto cnt = vec2d(m, m, 0);
    for(int i = 0; i < n-1; i++){
        cnt[s[i]-'a'][s[i+1]-'a']++;
    }
    auto moves = vec2d(m, 1<<m, 0);
    vector<int> msb(1<<m);
    for(int s = 1; s < (1<<m); s++){
        for(int i = m-1; i >= 0; i--){
            if(s&(1<<i)){
                msb[s] = i;
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int s = 1; s < (1<<m); s++){
            if(s&(1<<i)) continue;
            int t = s-(1<<msb[s]);
            moves[i][s] = moves[i][t]+cnt[i][msb[s]]+cnt[msb[s]][i];
        }
    }
    vector<int> outer_moves(1<<m);
    int all_bits = (1<<m)-1;
    for(int s = 1; s+1 < (1<<m); s++){
        int ms = msb[s];
        int rem = all_bits-s;
        int t = s-(1<<ms);
        outer_moves[s] = outer_moves[t] - moves[ms][t] + moves[ms][rem];
    }
    
    vector<int> dp(1<<m, inf);
    dp[0] = 0;
    for(int s = 1; s < (1<<m); s++){
        for(int i = 0; i < m; i++){
            if(s&(1<<i)) {
                chmin(dp[s], dp[s-(1<<i)]+outer_moves[s]);
            }
        }
    }
    cout << dp.back() << endl;
}