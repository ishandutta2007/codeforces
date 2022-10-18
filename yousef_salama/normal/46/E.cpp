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
using namespace std;
long long dp[1505][1505], sum[1505], ST[1505][20];
int val[1505][1505], N, M;
void SparseTable(){
    for(int i = 0; i <= M; i++)
        ST[i][0] = sum[i];
    for(int j = 1; (1 << j) <= M + 1; j++)
    for(int i = 0; i + (1 << j) - 1 <= M; i++)
        ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}
long long RMQ(int i, int j){
    int k = (int)log2(j - i + 1);
    return max(ST[i][k], ST[j - (1 << k) + 1][k]);
}
int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &val[i][j]);
    sum[0] = 0;
    for(int idx = N - 1; idx >= 0; idx--){
        for(int i = 1; i <= M; i++)
            sum[i] = sum[i - 1] + val[idx][i - 1];
        for(int i = 1; i <= M; i++)
            sum[i] += dp[idx + 1][i];
        SparseTable();
        for(int pre = 0; pre <= M; pre++){
            if(idx&1)dp[idx][pre] = RMQ(1, pre - 1);
            else dp[idx][pre] = RMQ(max(pre + 1, (idx == N - 1?1:2)), M);
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}