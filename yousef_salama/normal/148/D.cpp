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
int w, b;
double dp[1005][1005][2];
double dfs(int wi, int bi, int turn){
    if(wi == 0){
        if(turn == 1)return 1.0;
        else return 0;
    }
    if(dp[wi][bi][turn] == dp[wi][bi][turn])return dp[wi][bi][turn];
    double ans = wi * 1.0 / (wi + bi);
    if(turn == 0){
        if(bi - 1 >= 0)ans += (bi * 1.0 / (wi + bi)) * (1 - dfs(wi, bi - 1, 1));
    }
    else{
        double s1 = 0, s2 = 0;
        if(wi - 1 >= 0 && bi - 1 >= 0)s1 = (wi * 1.0 / (wi + bi - 1)) * dfs(wi - 1, bi - 1, 0);
        if(bi - 2 >= 0)s2 = ((bi - 1) * 1.0 / (wi + bi - 1)) * dfs(wi, bi - 2, 0);
        ans += (bi * 1.0 / (wi + bi)) * (1 - (s1 + s2));
    }
    return dp[wi][bi][turn] = ans;
}
int main(){
    scanf("%d %d", &w, &b);
    memset(dp, -1, sizeof dp);
    printf("%.9f\n", dfs(w, b, 0));
    return 0;
}