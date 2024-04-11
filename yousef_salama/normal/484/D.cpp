//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

const int MAXN = 1000005;

int n, a[MAXN];
long long dp[MAXN][3];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    dp[0][0] = 0;
    dp[0][1] = dp[0][2] = -1LL << 60;
    
    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] + a[i - 1], dp[i - 1][2] - a[i - 1]));
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - a[i - 1]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + a[i - 1]);
    }
    printf("%I64d\n", dp[n][0]);
    
    return 0;
}