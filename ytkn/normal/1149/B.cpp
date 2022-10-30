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
const int N = 250;

int dp[255][255][255];
int nx[100001][26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    string s; cin >> s;
   
    for(int i = 0; i < 26; i++){
        nx[n][i] = inf;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 26; j++) nx[i][j] = nx[i+1][j];
        nx[i][s[i]-'a'] = i+1;
    }
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k <= N; k++){
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    vector<string> t(3);
    auto del = [&](int idx){
        int il = idx == 0 ? t[idx].size() : 0;
        int jl = idx == 1 ? t[idx].size() : 0;
        int kl = idx == 2 ? t[idx].size() : 0;
        for(int i = il; i <= t[0].size(); i++){
            for(int j = jl; j <= t[1].size(); j++){
                for(int k = kl; k <= t[2].size(); k++){
                    dp[i][j][k] = inf;
                }
            }
        }
        t[idx].pop_back();
    };
    auto add = [&](int idx, char c){
        int il = idx == 0 ? t[idx].size() : 0;
        int jl = idx == 1 ? t[idx].size() : 0;
        int kl = idx == 2 ? t[idx].size() : 0;
        t[idx] += c;
        for(int i = il; i <= t[0].size(); i++){
            for(int j = jl; j <= t[1].size(); j++){
                for(int k = kl; k <= t[2].size(); k++){
                    if(i > 0 && dp[i-1][j][k] < n){
                        int next_pos = nx[dp[i-1][j][k]][t[0][i-1]-'a'];
                        if(next_pos <= n) chmin(dp[i][j][k], next_pos);
                    }
                    if(j > 0 && dp[i][j-1][k] < n){
                        int next_pos = nx[dp[i][j-1][k]][t[1][j-1]-'a'];
                        if(next_pos <= n) chmin(dp[i][j][k], next_pos);
                    }
                    if(k > 0 && dp[i][j][k-1] < n){
                        int next_pos = nx[dp[i][j][k-1]][t[2][k-1]-'a'];
                        if(next_pos <= n) chmin(dp[i][j][k], next_pos);
                    }
                }
            }
        }
    };
    while(q--){
        char tp; cin >> tp;
        if(tp == '+'){
            int i; char c; cin >> i >> c; i--;
            add(i, c);
        }else{
            int i; cin >> i; i--;
            del(i);
        }
        if(dp[t[0].size()][t[1].size()][t[2].size()] <= n){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}