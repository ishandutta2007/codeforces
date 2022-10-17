#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const long long mod = 1e9 + 7, MAXN = 705;
char s[MAXN];
int len, p[MAXN], t[MAXN];
long long dp[MAXN][MAXN][4][4], ans;
void dfs(int l, int r) {
    if(l + 1 == r) {
        dp[l][r][0][1] = 1;
        dp[l][r][1][0] = 1;
        dp[l][r][2][0] = 1;
        dp[l][r][0][2] = 1;
        return ;
    }
    if(p[r] == l) {
        dfs(l + 1, r - 1);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != 1) dp[l][r][1][0] = (dp[l][r][1][0] + dp[l+1][r-1][i][j]) % mod;
                if(j != 1) dp[l][r][0][1] = (dp[l][r][0][1] + dp[l+1][r-1][i][j]) % mod;
                if(i != 2) dp[l][r][2][0] = (dp[l][r][2][0] + dp[l+1][r-1][i][j]) % mod;
                if(j != 2) dp[l][r][0][2] = (dp[l][r][0][2] + dp[l+1][r-1][i][j]) % mod;
            }
        }
    }
    else {
        int x = p[l];
        dfs(l, x);
        dfs(x + 1, r);
        for(int i = 0; i < 3; i++) 
            for(int j = 0; j < 3; j++) 
                for(int u = 0; u < 3; u++) 
                    for(int v = 0; v < 3; v++) 
                        if(!(u == 1 && v == 1 || u == 2 && v == 2))
                            dp[l][r][i][j] = (dp[l][r][i][j] + (dp[l][x][i][u] * dp[x + 1][r][v][j]) % mod) % mod;
    }
}
int main() {
    scanf("%s", s + 1);
    len = strlen(s + 1);
    for(int i = 1, k = 0; i <= len; i++) {
        if(s[i] == '(') t[k++] = i;
        else {
            p[i] = t[k - 1];
            p[t[--k]] = i;
        }
    }
    dfs(1, len);
    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 3; j++) 
            ans = (ans + dp[1][len][i][j]) % mod;
    printf("%lld\n", ans);
    return 0;
}