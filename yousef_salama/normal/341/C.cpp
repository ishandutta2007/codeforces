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
#define MOD 1000000007
using namespace std;

int n, a[2005];
long long dp[2005][2005];

void calcdp(){
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= i; j++){
        if(i == 0){
            dp[i][j] = 1;
        }else if(j == i){
            dp[i][j] = (dp[i - 1][j - 1] * i) % MOD;
        }else{
            int p = n - i;
            if(p < j)continue;
            int k = p - j;
            
            dp[i][j] = 0;
            if(i - 1 >= j + 1)dp[i][j] = (dp[i][j] + dp[i - 1][j + 1] * (i - j - 1)) % MOD;
            if(p - k > 0)dp[i][j] = (dp[i][j] + dp[i - 1][j] * (p - k)) % MOD;
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int ti = 0, tj = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == -1)ti++;
        else if(a[a[i] - 1] == -1)tj++;
    }
    
    calcdp();
    printf("%d\n", (int)dp[ti][tj]);
    
    return 0;
}