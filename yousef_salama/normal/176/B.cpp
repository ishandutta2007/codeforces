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
char a[2010], b[1005];
int k, n, m;
long long dp[100005][2];
int main(){
    scanf("%s %s %d", &a, &b, &k);
    n = strlen(a);
    m = strlen(b);

    for(int i = 0; i < n; i++)
        a[i + n] = a[i];

    dp[0][true] = 1;
    dp[0][false] = 0;
    for(int i = 1; i <= k; i++){
        dp[i][true] = (dp[i - 1][false] * (n - 1)) % MOD;
        dp[i][false] = (dp[i - 1][true] + dp[i - 1][false] * (n - 2)) % MOD;
    }

    long long ans = 0;
    for(int i = 0; i < n; i++){
        bool flag = false;
        for(int j = 0; j < m; j++)
            if(a[j + i] != b[j])flag = true;
        if(!flag)ans = (ans + dp[k][i == 0]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}