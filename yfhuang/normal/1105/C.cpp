#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, l, r;
int c[3];
const long long mod = 1e9 + 7;
long long dp[200005][3];
int main(){
    cin >> n >> l >> r;
    c[0] = r / 3 - (l - 1) / 3;
    c[1] = (r + 2) / 3 - (l + 1) / 3;
    c[2] = (r + 1) / 3 - l / 3;
    dp[0][0] = 1;
    dp[0][1] = dp[0][2] = 0;
    for(int i = 1;i <= n;i++){
        dp[i][0] = (dp[i - 1][0] * c[0] + dp[i - 1][1] * c[2] + dp[i - 1][2] * c[1]) % mod; 
        dp[i][1] = (dp[i - 1][0] * c[1] + dp[i - 1][2] * c[2] + dp[i - 1][1] * c[0]) % mod;
        dp[i][2] = (dp[i - 1][0] * c[2] + dp[i - 1][1] * c[1] + dp[i - 1][2] * c[0]) % mod;
    }
    cout << dp[n][0] << endl;
    return 0;
}