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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;

#define MOD 1000000007

int n, k;
long long comb[1005][1005], C[1005][1005][2][2], dp[1005];

int main(){
    scanf("%d %d", &n, &k);
    
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++){
        if(j == 0)comb[i][j] = 1;
        else if(i == 0)comb[i][j] = 0;
        else comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
    }
    
    C[0][0][0][0] = 1;
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++)
    for(int p1 = 0; p1 <= 1; p1++)
    for(int p2 = 0; p2 <= 1; p2++){
        long long t = C[i][j][p1][p2];
        
        C[i + 1][j][0][p1] += t;
        C[i + 1][j][0][p1] %= MOD;
        
        if(p2 == 0 && i > 0){
            C[i + 1][j + 1][0][p1] += t;
            C[i + 1][j + 1][0][p1] %= MOD;
        }

        if(i < n - 1){
            C[i + 1][j + 1][1][p1] += t;
            C[i + 1][j + 1][1][p1] %= MOD;
        }
    }
    
    for(int i = 0; i <= n; i++){
        for(int p1 = 0; p1 <= 1; p1++)
        for(int p2 = 0; p2 <= 1; p2++){
            dp[i] += C[n][i][p1][p2];
            dp[i] %= MOD;
        }
        
        for(int j = 1; j <= (n - i); j++){
            dp[i] *= j;
            dp[i] %= MOD;
        }
    }
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j <= n; j++){
            dp[i] -= (dp[j] * comb[j][i]) % MOD;
            dp[i] += MOD;
            dp[i] %= MOD;
        }
    }
    
    printf("%d\n", dp[k]);
    return 0;
}