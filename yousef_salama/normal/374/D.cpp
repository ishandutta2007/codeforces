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

int n, m, a[1 << 20], b[1 << 20];
int dp[1 << 20], C[1 << 20], chits[1 << 20];

char ans[1 << 20];

int main(){
    scanf("%d %d", &n, &m);
    
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < m; i++){
        scanf("%d", &a[i]);
        dp[a[i]] = 1;
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    
    C[0] = 0;
    for(int i = 1; i <= n; i++)
        C[i] = C[i - 1] + (dp[i] != -1);
    
    for(int i = 1; i <= n; i++){
        if(dp[i] != -1)continue;
        if(C[i] > 0)dp[i] = dp[i - C[i]] + 1;
    }
    
    chits[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        chits[i] = chits[i + 1];
        if(b[i] == -1)chits[i]++;
    }
    
    int X = 0, Y = 0;
    for(int i = 0; i < n; i++){
        if(b[i] == -1)X -= upper_bound(a, a + m, X) - a;
        else{
            X++;
            if(dp[X] == -1 || dp[X] > chits[i])ans[Y++] = b[i] + '0';
        }
    }
    
    if(Y == 0)printf("Poor stack!\n");
    else{
        ans[Y] = '\0';
        printf("%s\n", ans);
    }
    
    return 0;
}