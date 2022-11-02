#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
char f[2000][2000];
ll dp[2][2001][2001]; //0 -> 1:
int cnt[2][2001][2001]; //0 -> 1:

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> f[i][j];
        }
    }
    if(n == 1 && m == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = n-1; i >=0; i--){
        for(int j = m-1; j >= 0; j--){
            if(i == n-1) {
                if(f[i][j] == 'R') cnt[0][i][j] = 1;
                else cnt[0][i][j] = 0;
            }else{
                if(f[i][j] == 'R') cnt[0][i][j] = cnt[0][i+1][j]+1;
                else cnt[0][i][j] = cnt[0][i+1][j];
            }
            if(j == m-1){
                if(f[i][j] == 'R') cnt[1][i][j] = 1;
                else cnt[1][i][j] = 0;
            }else{
                if(f[i][j] == 'R') cnt[1][i][j] = cnt[1][i][j+1]+1;
                else cnt[1][i][j] = cnt[1][i][j+1];
            }
        }
    }
    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j != 0  && !(i == 0 && j == 1)) {
                dp[0][i][j] += dp[0][i][j-1];
                dp[0][i][j] %= MOD;
            }
            dp[1][i+1][j] += dp[0][i][j];
            dp[1][i+1][j] %= MOD;
            int c = cnt[0][i+1][j];
            dp[1][n-c][j] -= dp[0][i][j];
            dp[1][n-c][j] %= MOD;
            dp[1][n-c][j] += MOD;
            dp[1][n-c][j] %= MOD;
            if(i != 0 && !(i == 1 && j == 0)) {
                dp[1][i][j] += dp[1][i-1][j];
                dp[1][i][j] %= MOD;
            }
            dp[0][i][j+1] += dp[1][i][j];
            dp[0][i][j+1] %= MOD;
            c = cnt[1][i][j+1];
            dp[0][i][m-c] -= dp[1][i][j];
            dp[0][i][m-c] %= MOD;
            dp[0][i][m-c] += MOD;
            dp[0][i][m-c] %= MOD;
        }
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << dp[0][i][j]+dp[1][i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << (dp[0][n-1][m-1]+dp[1][n-1][m-1])%MOD << endl;
}