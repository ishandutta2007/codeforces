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
#define eps 1e-9
using namespace std;
int N, K;
long long L[1005], R[1005], C[1005];
double dp[1005][1005];
long long num(long long i){
    if(i < 10){
        if(i >= 1)return 1;
        else return 0;
    }
    long long ans = 0, cur = 1;
    while(i / cur >= 10){
        ans += cur;
        cur *= 10;
    }
    if(i / cur > 1)ans += cur;
    else ans += i - cur + 1;
    return ans;
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        cin >> L[i] >> R[i];
        C[i] = num(R[i]) - num(L[i] - 1);
    }
    scanf("%d", &K);
    for(int z = 0; z <= N; z++)
        if(z * 100 >= K * N)
            dp[N][z] = 1;
    for(int i = N - 1; i >= 0; i--)
    for(int z = 0; z <= N; z++)
        dp[i][z] = (dp[i + 1][z] * (R[i] - L[i] + 1 - C[i]) + (z + 1 <= N?dp[i + 1][z + 1]:0) * C[i])
                / (R[i] - L[i] + 1);
    printf("%.15f\n", dp[0][0]);
    return 0;
}