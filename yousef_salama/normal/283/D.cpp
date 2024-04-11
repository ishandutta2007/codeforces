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

int n;
long long a[5005];
int dp[5005];

bool cool(long long x, long long y){
    if(y % 2 != 0){
        return x % y == 0;
    }else{
        return (x % y) == (y / 2);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    a[n] = 1;
    
    int ans = 1 << 30;
    
    dp[n] = 0; 
    for(int i = n - 1; i >= 0; i--){
        dp[i] = 1 << 30;
        for(int j = i + 1; j <= n; j++){
            if(cool(a[i], a[j]))dp[i] = min(dp[i], dp[j] + (j - i - 1));
            if(a[j] % 2 == 0)a[j] /= 2;
        }
        ans = min(ans, dp[i] + i);
    }
    printf("%d\n", ans);
    
    return 0;
}