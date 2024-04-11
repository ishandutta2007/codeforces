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
#include <complex>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

#define MOD 1000000007

int n, m;
char s[100005];

long long dp[2005][2005], dp2[2005][2005];

int main(){
    scanf("%d %d %s", &n, &m, s);
    
    int diff = n - m;
    for(int rem = 0; rem <= diff; rem++)
    for(int d = 0; d <= diff; d++){
        if(rem == 0){
            dp[rem][d] = 1;
            dp2[rem][d] = (d == 0);
        }else{
            dp[rem][d] = 0;
            if(d - 1 >= 0)dp[rem][d] = (dp[rem][d] + dp[rem - 1][d - 1]) % MOD;
            if(d + 1 <= diff)dp[rem][d] = (dp[rem][d] + dp[rem - 1][d + 1]) % MOD;
            
            dp2[rem][d] = 0;
            if(d - 1 >= 0)dp2[rem][d] = (dp2[rem][d] + dp2[rem - 1][d - 1]) % MOD;
            if(d + 1 <= diff)dp2[rem][d] = (dp2[rem][d] + dp2[rem - 1][d + 1]) % MOD;
        }
    }
    
    int sum = 0, mn = 1 << 30;
    for(int i = 0; i < m; i++){
        if(s[i] == '(')sum += 1;
        if(s[i] == ')')sum -= 1;
        
        mn = min(mn, sum);
    }
    
    long long r = 0;
    for(int r1 = 0; r1 <= diff; r1++)
    for(int d1 = 0; d1 <= diff; d1++){
        if(d1 + mn < 0)continue;
        if(d1 + sum <= diff)r = (r + dp2[r1][d1] * dp2[diff - r1][d1 + sum]) % MOD;
    }
    printf("%I64d\n", r);
    
    return 0;
}