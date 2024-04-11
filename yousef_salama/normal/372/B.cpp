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

int n, m, q, dp[45][45][45][45], sum[45][45];
char g[45][45];

bool good(int a, int b, int c, int d){
    int ret = 0;
    ret += sum[c][d];
    if(a > 0)ret -= sum[a - 1][d];
    if(b > 0)ret -= sum[c][b - 1];
    if(a > 0 && b > 0)ret += sum[a - 1][b - 1];
    
    return ret == 0;
}

int calc(int a, int b, int c, int d){
    if(dp[a][b][c][d] != -1)return dp[a][b][c][d];
    
    int ret = good(a, b, c, d);
    if(c > a)ret += calc(a, b, c - 1, d);
    if(d > b)ret += calc(a, b, c, d - 1);
    if(c > a && d > b)ret -= calc(a, b, c - 1, d - 1);
    
    return dp[a][b][c][d] = ret;
}

int main(){
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < n; i++)
        scanf("%s", g[i]);
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        sum[i][j] = (g[i][j] == '1');
        if(i > 0)sum[i][j] += sum[i - 1][j];
        if(j > 0)sum[i][j] += sum[i][j - 1];
        if(i > 0 && j > 0)sum[i][j] -= sum[i - 1][j - 1];
    }
    memset(dp, -1, sizeof dp);
    
    while(q--){
        int ai, bi, ci, di;
        scanf("%d %d %d %d", &ai, &bi, &ci, &di);
        ai--, bi--, ci--, di--;
        
        int res = 0;
        for(int i = ai; i <= ci; i++)
        for(int j = bi; j <= di; j++){
            res += calc(i, j, ci, di);
        }
        printf("%d\n", res);
    }
    
    return 0;
}