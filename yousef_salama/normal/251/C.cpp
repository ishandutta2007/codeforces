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
long long a, b, dp[400005], dp2[400005];
int k, LCM, ax, bx;
int main(){
    scanf("%I64d %I64d %d", &a, &b, &k);
    swap(a, b);
    
    LCM = 1;
    for(int i = 2; i <= k; i++)
        LCM = LCM * i / __gcd(LCM, i);
    ax = a % LCM, bx = b % LCM;
    
    memset(dp, 63, sizeof dp);
    dp[ax] = 0;
    for(int i = ax + 1; i < LCM; i++){
        dp[i] = dp[i - 1] + 1;
        for(int j = 2; j <= k; j++)
            if(i % j)dp[i] = min(dp[i], dp[i - (i % j)] + 1);
    }
    
    if(a / LCM == b / LCM){
        printf("%I64d\n", dp[bx]);
    }else{
        dp2[0] = 0;
        for(int i = 1; i < LCM; i++){
            dp2[i] = dp2[i - 1] + 1;
            for(int j = 2; j <= k; j++)
                if(i % j)dp2[i] = min(dp2[i], dp2[i - (i % j)] + 1);
        }

        printf("%I64d\n", (dp2[bx] + 1) + (dp2[LCM - 1] + 1) * (b / LCM - a / LCM - 1) + dp[LCM - 1]);
    }
    return 0;
}