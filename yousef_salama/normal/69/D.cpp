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
#define oo 100000000000000LL
using namespace std;
int sx, sy, n, d, vec[22][2], dp[420][420][2][2][2];
int dfs(int x, int y, int s1, int s2, int t){
    if(x * x + y * y > d * d)return t;
    if(dp[x + 205][y + 205][s1][s2][t] != -1)return dp[x + 205][y + 205][s1][s2][t];
    int ans = t ^ 1;
    if(t == 0 && s1 > 0){
        if(dfs(y, x, s1 - 1, s2, t ^ 1) == t)
            ans = t;
    }else if(s2 > 0){
        if(dfs(y, x, s1, s2 - 1, t ^ 1) == t)
            ans = t;
    }
    for(int i = 0; i < n; i++)
        if(dfs(x + vec[i][0], y + vec[i][1], s1, s2, t ^ 1) == t)
            ans = t;
    return dp[x + 205][y + 205][s1][s2][t] = ans;
}
int main(){
    scanf("%d %d %d %d", &sx, &sy, &n, &d);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &vec[i][0], &vec[i][1]);
    memset(dp, -1, sizeof dp);
    int ans = dfs(sx, sy, 1, 1, 0);
    if(ans == 0)printf("Anton\n");
    else printf("Dasha\n");
    return 0;
}