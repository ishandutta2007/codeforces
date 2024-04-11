#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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
using T = tuple<int, int, int>;

int dp[1005][1005][2][2];
const int N_MAX = 500;
const int INF = 1e9;

void init(){
    for(int i = 0; i <= 2*N_MAX; i++){
        for(int j = 0; j <= 2*N_MAX; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    dp[i][j][k][l] = INF;
                }
            }
        }
    }

    dp[0][0][0][0] = 0;
    for(int a = 0; a <= N_MAX; a++){
        for(int b = 0; b <= N_MAX; b++){
            if(a+b > N_MAX) continue;
            for(int c = 0; c < 2; c++){
                bool p = (b == 0);
                for(int rev = 1; rev >= 0; rev--){
                    if(p && rev) continue;
                    if(rev == 0 && !p){ // rev
                        chmin(dp[a][b][c][0], -dp[a][b][c][1]);
                    }
                    if(a > 0){
                        chmin(dp[a][b][c][rev], -dp[a-1][b+1][c][0]+1);
                    }
                    if(b > 0){
                        chmin(dp[a][b][c][rev], -dp[a][b-1][c][0]+1);
                    }
                    if(c > 0){
                        chmin(dp[a][b][c][rev], -dp[a][b][c-1][0]+1);
                    }
                }
                // cout << dp[a][b][c][0] << endl;
                // if(a <= 5 && b <= 5) cout << a << ' ' << b << ' ' << c << ' ' << dp[a][b][c][0] << ' ' << dp[a][b][c][1] << endl;
            }
        }
    }
}

T calc(string s){
    int n = s.size();
    int a = 0, b = 0;
    int c = 0;
    if(n%2 == 1){
        int m = (n-1)/2;
        if(s[m] == '0') c = 1;
    }
    for(int i = 0; i < n; i++){
        int j = (n-1)-i;
        if(j <= i) break;
        if(s[i] == '0' && s[j] == '0') a++;
        if(s[i] != s[j]) b++;
    }
    return T(a, b, c);
}

string solve(string s){
    auto [a, b, c] = calc(s);
    if(dp[a][b][c][0] > 0){
        return "BOB";
    }else if(dp[a][b][c][0] == 0){
        return "DRAW";
    }else{
        return "ALICE";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--){
        int n; cin>> n;
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}