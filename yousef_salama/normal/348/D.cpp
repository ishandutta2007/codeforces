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

const int MOD = 1000000007;

int n, m;
char s[3005][3005];
int dp[3005][3005];

void calc(int ti, int tj){
    for(int i = n - 1; i >= 0; i--)
    for(int j = m - 1; j >= 0; j--){
        if(s[i][j] == '#')dp[i][j] = 0;
        else{
            if(i == ti && j == tj)dp[i][j] = 1;
            else{
                dp[i][j] = 0;
                if(i + 1 < n){
                    dp[i][j] += dp[i + 1][j];
                    dp[i][j] %= MOD;
                }
                if(j + 1 < m){
                    dp[i][j] += dp[i][j + 1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);
    
    calc(n - 1, m - 2);
    long long c1 = dp[1][0];
    calc(n - 2, m - 1);
    long long c2 = dp[0][1];
    calc(n - 1, m - 2);
    long long c3 = dp[0][1];
    calc(n - 2, m - 1);
    long long c4 = dp[1][0];
    
    long long res = (c1 * c2 - c3 * c4) % MOD;
    res += MOD;
    res %= MOD;
    
    printf("%d\n", res);
    
    return 0;
}