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

int n, c[505], dp[505][505];
int solve(int L, int R){
    if(L == R)return 1;
    if(L > R)return 0;
    if(dp[L][R] != -1)return dp[L][R];

    int res = 1 << 30;
    for(int k = L + 1; k <= R; k++)
        res = min(res, solve(L, k - 1) + solve(k, R));
    
    if(c[L] == c[R]){
        if((L + 1) == R)res = min(res, 1);
        else res = min(res, solve(L + 1, R - 1));
    }
    return dp[L][R] = res;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);

    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, n - 1));

    return 0;
}