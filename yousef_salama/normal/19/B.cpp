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
#include <string.h>
using namespace std;
int N, t[2005], c[2005];
long long dp[2005][2005];
long long dfs(int i, int ti){
    if(ti <= 0)return 0;
    if(i == N)return 1LL << 50;
    if(dp[i][ti] != -1)return dp[i][ti];
    return dp[i][ti] = min(dfs(i + 1, ti), dfs(i + 1, ti - t[i]) + c[i]);
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &t[i], &c[i]);
        t[i]++;
    }
    memset(dp, -1, sizeof dp);
    cout << dfs(0, N) << endl;
    return 0;
}