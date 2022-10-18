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

const int shift = 10005;
const int MAXK = 20025;

int N, K, a[105], b[105], dp[20025];

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)scanf("%d", &a[i]);
    for(int i = 0; i < N; i++)scanf("%d", &b[i]);
    
    for(int j = 0; j < 20025; j++)dp[j] = -1 << 20;
    dp[shift] = 0;
        
    for(int i = 0; i < N; i++){
        int ci = a[i] - K * b[i];
        
        if(ci >= 0){
            for(int j = MAXK - 1; j >= ci; j--)
                dp[j] = max(dp[j], dp[j - ci] + a[i]);
        }else{
            for(int j = 0; j - ci < MAXK; j++)
                dp[j] = max(dp[j], dp[j - ci] + a[i]);
        }
    }
    
    if(dp[shift] <= 0)printf("-1\n");
    else printf("%d\n", dp[shift]);
    
    return 0;
}