#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 55;

int dp[maxn][maxn][maxn][maxn];

char s[maxn][maxn];
int n;

int f(int l, int u, int r, int d){
    if(dp[l][u][r][d] != -1)
        return dp[l][u][r][d];
    if(l == r and u == d)
        return dp[l][u][r][d] = (s[l][u] == '#');
    int ret = max(r - l + 1, d - u + 1);
    for(int i = l;i < r;i++){
        ret = min(ret, f(l, u, i, d) + f(i + 1, u, r, d));
    }
    for(int i = u;i < d;i++){
        ret = min(ret, f(l, u, r, i) + f(l, i + 1, r, d));
    }
    return dp[l][u][r][d] = ret;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%s", s[i] + 1);
    } 
    memset(dp, -1, sizeof(dp));
    printf("%d\n", f(1, 1, n, n));
    return 0;
}