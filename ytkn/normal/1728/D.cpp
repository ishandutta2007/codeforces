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

const int WIN = 0;
const int DRAW = 1;
const int LOSE = 2;

void solve(){
    string s; cin >> s;
    int n = s.size();
    auto dp = vec2d(n+1, n+1, DRAW);
    for(int len = 2; len <= n; len++){
        for(int l = 0; l+len <= n; l++){
            int r = l+len;
            bool can_win = false;
            auto nx = [&](int a, int b){
                int l1 = -1, r1 = -1;
                if(a == l && b == l+1){
                    l1 = l+2;
                    r1 = r;
                }else if(a == l && b == r-1){
                    l1 = l+1;
                    r1 = r-1;
                }else if(a == r-1 && b == l){
                    l1 = l+1;
                    r1 = r-1;
                }else{
                    assert(a == r-1 && b == r-2);
                    l1 = l;
                    r1 = r-2;
                }
                if(dp[l1][r1] == DRAW){
                    if(s[a] < s[b]) return WIN;
                    if(s[a] > s[b]) return LOSE;
                    if(s[a] == s[b]) return DRAW;
                }else{
                    return dp[l1][r1];
                }
            };
            dp[l][r] = min(
                max(nx(l, r-1), nx(l, l+1)),
                max(nx(r-1, r-2), nx(r-1, l))
            );
        }
    }
    if(dp[0][n] == WIN) cout << "Alice" << endl;
    else if(dp[0][n] == LOSE) cout << "Bob" << endl;
    else cout << "Draw" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}