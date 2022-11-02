#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 105;

long long dp[2][maxn][maxn][maxn];
long long ans[maxn][maxn];
int n;
char s[maxn];
int a[maxn];
int main(){
    cin >> n;
    scanf("%s", s + 1);
    for(int i = 1;i <= n;i++){
        scanf("%d", a + i);
    }
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < maxn;j++){
            for(int k = 0;k < maxn;k++){
                if(k == j - 1)
                    ans[j][k] = 0;
                else
                    ans[j][k] = -1e18;
                for(int l = 0;l < maxn;l++){
                    dp[i][j][k][l] = -1e18;
                }
            }
        }
    }
    for(int i = 1;i < maxn;i++){
        dp[0][i][i - 1][0] = 0;
        dp[1][i][i - 1][0] = 0;
    }
    for(int len = 1;len <= n;len++){
        for(int i = 1;i + len - 1 <= n;i++){
            int l = i, r = i + len - 1;
            for(int k = 1;k <= len;k++){
                for(int ii = l;ii <= r;ii++){
                    int digit = s[ii] - '0';
                    dp[digit][l][r][k] = max(dp[digit][l][r][k], ans[l][ii - 1] + dp[digit][ii + 1][r][k - 1]);
                }
                ans[l][r] = max(ans[l][r], dp[0][l][r][k] + a[k]);
                ans[l][r] = max(ans[l][r], dp[1][l][r][k] + a[k]);
            }
            dp[0][l][r][0] = ans[l][r];
            dp[1][l][r][0] = ans[l][r];
        }
    }
    cout << ans[1][n] << endl;
    return 0;
}