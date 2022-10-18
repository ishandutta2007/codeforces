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
#define MOD 1000000007
using namespace std;
int n, m;
int a[105][105], dp[105][10005], lev[105][105], L[105], R[105];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i][0]);
        for(int j = 1; j <= a[i][0]; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i = 0; i < n; i++){
        L[0] = a[i][1];
        for(int j = 2; j <= a[i][0]; j++)
            L[j - 1] = L[j - 2] + a[i][j];
        R[a[i][0] - 1] = a[i][a[i][0]];
        for(int j = a[i][0] - 1; j > 0; j--)
            R[j - 1] = R[j] + a[i][j];
        for(int l = 0; l <= a[i][0]; l++)
        for(int r = 0; r <= a[i][0]; r++)
            if(l + r <= a[i][0]){
                lev[i][l + r] = max(lev[i][l + r], (l > 0?L[l - 1]:0) + (r > 0?R[a[i][0] - r]:0));
            }
    }
    for(int i = 1; i <= n; i++)
    for(int j = 0; j <= m; j++)
        for(int cur = 0; cur <= min(j, a[i - 1][0]); cur++)
            dp[i][j] = max(dp[i][j], dp[i - 1][j - cur] + lev[i - 1][cur]);
    printf("%d\n", dp[n][m]);
    return 0;
}