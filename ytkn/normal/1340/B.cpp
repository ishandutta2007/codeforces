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

vector<string> v = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int calc(string s, int x){
    int ans = 0;
    for(int i = 0; i < 7; i++){
        if(s[i] == '1' && v[x][i] == '0') return -1;
        if(s[i] == '0' && v[x][i] == '1') ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, K; cin >> n >> K;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    auto count = vec2d(n, 10, -1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            count[i][j] = calc(s[i], j);
        }
    }
    auto ok = vec2d(n+1, K+1, false);
    ok[n][0] = true;
    for(int i = n-1; i >= 0; i--){
        for(int k = 0; k <= K; k++){
            if(!ok[i+1][k]) continue;
            for(int j = 0; j < 10; j++){
                if(count[i][j] == -1) continue;
                if(k+count[i][j] <= K) ok[i][k+count[i][j]] = true;
            }
        }
    }
    auto dp = vec2d(n+1, K+1, false);
    dp[0][0] = true;
    string ans;
    for(int i = 0; i < n; i++){
        int nx = -1;
        for(int k = 0; k <= K; k++){
            if(!dp[i][k]) continue;
            for(int j = 0; j < 10; j++){
                if(count[i][j] == -1) continue;
                int rem = K-(k+count[i][j]);
                if(rem >= 0 && ok[i+1][rem]) {
                    chmax(nx, j); 
                }
            }
        }
        if(nx == -1){
            cout << -1 << endl;
            return 0;
        }
        ans += '0'+nx;
        for(int k = 0; k <= K; k++){
            if(!dp[i][k]) continue;
            assert(count[i][nx] != -1);
            int rem = K-(k+count[i][nx]);
            if(rem >= 0 && ok[i+1][rem]) dp[i+1][k+count[i][nx]] = true;; 
        }
    }
    cout << ans << endl;
}