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
int dp[1001][55][55];
int s_nx[55][26];
int t_nx[55][26];

void calc(string s, int nx[][26]){
    for(int i = 0; i <= s.size(); i++){
        for(int l = 0; l < 26; l++){
            string t = s.substr(0, i);
            t += ('a'+l);
            auto ok = [&](int x) -> bool{ // t[x:]sprefix
                for(int i = x; i < t.size(); i++){
                    int s_idx = i-x;
                    if(s_idx >= s.size()) return false;
                    if(s[s_idx] != t[i]) return false;
                }
                return true;
            };
            int max_len = 0;
            for(int x = 0; x < t.size(); x++){
                if(ok(x)) {
                    max_len = t.size()-x;
                    break;
                }
            }
            // cout << t << ": " << max_len << endl;
            nx[i][l] = max_len;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string c; cin >> c;
    string s, t; cin >> s >> t;
    calc(s, s_nx);
    calc(t, t_nx);
    for(int i = 0; i <= c.size(); i++){
        for(int j = 0; j <= s.size(); j++){
            for(int k = 0; k <= t.size(); k++){
                dp[i][j][k] = -inf;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j <= s.size(); j++){
            for(int k = 0; k <= t.size(); k++){
                int from = 0, to = 26;
                if(c[i] != '*'){
                    from = c[i]-'a';
                    to = from+1;
                }
                for(int l = from; l < to; l++){
                    int jj = s_nx[j][l];
                    int kk = t_nx[k][l];
                    int val_nx = dp[i][j][k];
                    if(jj == s.size()) {
                        val_nx++;
                    }
                    if(kk == t.size()) val_nx--;
                    chmax(dp[i+1][jj][kk], val_nx);
                }
            }
        }
    }
    int ans = -inf;
    for(int j = 0; j <= s.size(); j++){
        for(int k = 0; k <= t.size(); k++){
            chmax(ans, dp[c.size()][j][k]);
        }
    }
    cout << ans << endl;
}