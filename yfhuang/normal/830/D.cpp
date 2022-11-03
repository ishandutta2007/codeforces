#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 505;
LL dp[maxn][maxn];
LL C[maxn][maxn];
void upd(LL &a,LL b){a = a + b; }
int main() {
    int n;
    while(cin >> n){
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1;i <= n;i++){
            for(int l = 0;l <= n;l++){
                for(int r = 0;r <= n;r++){
                    LL temp = dp[i - 1][l] * dp[i - 1][r] % mod;
                    if(l + r <= n) upd(dp[i][l + r],temp);
                    if(l + r + 1 <= n) upd(dp[i][l + r + 1],temp);
                    if(l > 0 && l + r <= n) upd(dp[i][l + r],temp * 2 * l);
                    if(r > 0 && l + r <= n) upd(dp[i][l + r],temp * 2 * r);
                    if(l + r > 0 && l + r - 1 <= n) upd(dp[i][l + r - 1],temp * (l + r) * (l + r - 1));
                }
            }
            for(int j = 0;j <= n;j++) dp[i][j] %= mod;
        }
        cout << dp[n][1] << endl;
    }
    return 0;
}