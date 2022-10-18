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

int n, k, xi, a[1005][5];

int dp[1005];
int solve(int i){
    if(dp[i] != -1)return dp[i];
    
    int ret = 1;
    for(int j = 1; j <= n; j++){
        bool ok = true;
        for(int x = 0; x < k; x++)
            if(a[j][x] <= a[i][x])ok = false;

        if(ok)ret = max(ret, 1 + solve(j));
    }
    return dp[i] = ret;
}
int main(){
    scanf("%d %d", &n, &k);
    
    for(int j = 0; j < k; j++)
    for(int i = 0; i < n; i++){
        scanf("%d", &xi);
        a[xi][j] = i;
    }
    
    memset(dp, -1, sizeof dp);

    int m = 0;
    for(int i = 1; i <= n; i++)
        m = max(m, solve(i));
    printf("%d\n", m);

    return 0;
}