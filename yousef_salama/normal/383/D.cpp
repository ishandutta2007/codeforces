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

int n, a[1005];

const int shift = 5005;
const int MOD = 1000000007;

int res, dp_left[2][10010], dp_right[2][10010];
long long totalL[10010], totalR[10010];

void solve(int L, int R){
    if(L == R)return;
    
    int mid = (L + R) >> 1;
    solve(L, mid);
    solve(mid + 1, R);
    
    for(int i = 0; i < 10010; i++)
        dp_left[(mid & 1) ^ 1][i] = 0;
    dp_left[(mid & 1) ^ 1][shift] = 1;
    
    memset(totalL, 0, sizeof totalL);
    for(int i = mid; i >= L; i--){
        for(int x = 0; x < 10010; x++){
            dp_left[i & 1][x] = 0;
            if(x >= a[i])dp_left[i & 1][x] += dp_left[(i & 1) ^ 1][x - a[i]];
            if(x + a[i] < 10010)dp_left[i & 1][x] += dp_left[(i & 1) ^ 1][x + a[i]];
            
            if(dp_left[i & 1][x] > MOD)dp_left[i & 1][x] -= MOD;
            
            totalL[x] += dp_left[i & 1][x];
            if(totalL[x] > MOD)totalL[x] -= MOD;
        }
    }
    
    for(int i = 0; i < 10010; i++)
        dp_right[((mid + 1) & 1) ^ 1][i] = 0;
    dp_right[((mid + 1) & 1) ^ 1][shift] = 1;
    
    memset(totalR, 0, sizeof totalR);
    for(int i = mid + 1; i <= R; i++){
        for(int x = 0; x < 10010; x++){
            dp_right[i & 1][x] = 0;
            if(x >= a[i])dp_right[i & 1][x] += dp_right[(i & 1) ^ 1][x - a[i]];
            if(x + a[i] < 10010)dp_right[i & 1][x] += dp_right[(i & 1) ^ 1][x + a[i]];
            
            if(dp_right[i & 1][x] > MOD)dp_right[i & 1][x] -= MOD;
            
            totalR[x] += dp_right[i & 1][x];
            if(totalR[x] > MOD)totalR[x] -= MOD;
        }
    }
    
    for(int x = 0; x < 10010; x++){
        int y = -(x - shift) + shift;
        
        int cur = (totalL[x] * totalR[y]) % MOD;
        res = (res + cur) % MOD;
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    res = 0;
    solve(0, n - 1);
    
    printf("%d\n", res);
    
    return 0;
}