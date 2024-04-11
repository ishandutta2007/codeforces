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

int n, m, si[5005], dp[5005][5005];
double xi;

int solve(int i, int j){
    if(dp[i][j] != -1)return dp[i][j];
    if(i == n)return 0;    
    
    int res = 1 << 30;
    //sebo ya wa7sh
    if(si[i] >= j)res = min(res, solve(i + 1, si[i]));
    //ermy ya wa7sh
    res = min(res, 1 + solve(i + 1, j));
    
    return dp[i][j] = res;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        cin >> si[i] >> xi;
    
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, 0));
    return 0;
}