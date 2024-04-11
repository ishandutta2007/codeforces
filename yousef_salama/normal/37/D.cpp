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
int M, N, x[105], y[105], C[1005][1005], dp[105][1005];
long long calc(int i, int rem, int rem2){
    if(i == M)
        return rem == 0;
    if(dp[i][rem] != -1)
        return dp[i][rem];

    long long ans = 0;
    for(int j = 0; j <= y[i] && j <= rem; j++)
        ans = (ans + calc(i + 1, rem - j + x[i + 1], rem2 - x[i]) * C[rem][j]) % MOD;

    return dp[i][rem] = (ans * C[rem2][x[i]]) % MOD;
}
int main(){
    cin >> M;

    N = 0;
    for(int i = 0; i < M; i++){
        cin >> x[i];
        N += x[i];
    }

    for(int i = 0; i < M; i++)
        cin >> y[i];

    for(int n = 0; n < 1005; n++)
    for(int r = 0; r < 1005; r++){
        if(r == 0)C[n][r] = 1;
        else if(n == 0)C[n][r] = 0;
        else C[n][r] = (C[n - 1][r - 1] + C[n - 1][r]) % MOD;
    }
    
    memset(dp, -1, sizeof dp);
    cout << calc(0, x[0], N) << endl;
    return 0;
}