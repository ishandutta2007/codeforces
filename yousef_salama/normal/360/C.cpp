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
#define MOD 1000000007
using namespace std;

int n, k;
long long dp[2005][2005][2];
char s[2005];

int main(){
    scanf("%d %d %s", &n, &k, s);
    
    for(int i = 0; i <= n; i++)
    for(int rk = 0; rk <= k; rk++)
    for(int c = 0; c <= 1; c++){
        if(i == 0){
            if(rk == 0)dp[i][rk][c] = 1;
            else dp[i][rk][c] = 0;
        
            continue;
        }
        
        dp[i][rk][c] = 0;
        
        if(c == 0){
            // =
            dp[i][rk][c] += dp[i - 1][rk][0];
            dp[i][rk][c] %= MOD;
        }
        
        // -
        dp[i][rk][c] += dp[i - 1][rk][0] * (s[i - 1] - 'a');
        dp[i][rk][c] %= MOD;
        
        // +
        for(int j = i - 1; j >= 0; j--){
            if((n - i + 1) * (i - j) > rk)break;
            
            dp[i][rk][c] += dp[j][rk - (n - i + 1) * (i - j)][1] * (26 - (s[i - 1] - 'a') - 1);
            dp[i][rk][c] %= MOD;
        }
    }
    
    printf("%d\n", dp[n][k][0]);
    return 0;
}