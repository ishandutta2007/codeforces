#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
double dp[55][55][55], P[55][55][55];
int n, m, a[55];
double Prob(int i, int j, int cur){
    if(i == 0)
        return cur == 0;
    if(P[i][j][cur] == P[i][j][cur])
        return P[i][j][cur];
    return P[i][j][cur] = (1.0 / j) * (cur == 0?0:Prob(i - 1, j, cur - 1)) +
            (1.0 * (j - 1) / j) * Prob(i - 1, j, cur);
}
double calc(int i, int j, int Max){
    if(j == m)
        return Max;
    if(dp[i][j][Max] == dp[i][j][Max])return dp[i][j][Max];
    double ans = 0;
    for(int cur = 0; cur <= n - i; cur++)
        ans += Prob(n - i, m - j, cur) * calc(i + cur, j + 1, max(Max, (cur + a[j] - 1) / a[j]));
    return dp[i][j][Max] = ans;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    memset(P, -1, sizeof P);
    memset(dp, -1, sizeof dp);
    printf("%.20f\n", calc(0, 0, 0));
    return 0;
}