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

int n, k, p[3005], dp[3005][3005];
bool akeed[3005], yenfa3[3005];
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
    
    for(int i = n - 1; i >= 0; i--){
        akeed[i] = akeed[i + 1] || (p[i] == 100);
        yenfa3[i] = yenfa3[i + 1] || (p[i] > 0);
    }
    
    memset(dp, 63, sizeof dp);
    
    int INF = dp[0][0];
    
    dp[0][n] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(dp[i][j] == INF)continue;
            
            if(dp[i][j] + 1 <= k){
                if(yenfa3[i] && (p[j] != 100))dp[i][n] = min(dp[i][n], dp[i][j] + 1);
                if((p[j] > 0) && !akeed[i])dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                if(yenfa3[i] && (p[j] > 0))dp[i + 1][n] |= min(dp[i + 1][n], dp[i][j] + 1);
            }
        }
        
        if(i < n - 1){
            if(dp[i][n] == INF)continue;

            if(dp[i][n] + 1 <= k){
                if(yenfa3[i + 1] && (p[i] != 100))dp[i + 1][n] = min(dp[i + 1][n], dp[i][n] + 1);
                if((p[i] > 0) && !akeed[i + 1])dp[i + 2][i] = min(dp[i + 2][i], dp[i][n] + 1);
                if(yenfa3[i + 1] && (p[i] > 0))dp[i + 2][n] = min(dp[i + 2][n], dp[i][n] + 1);
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++){
        res += (dp[i][j] != INF);
//        if(dp[i][j]){
//            if(j != n)printf("%d", j);
//            for(int k = i; k < n; k++)
//                printf(" %d", k);
//            printf("\n");
//        }
    }
    
    printf("%d\n", res);
    return 0;
}