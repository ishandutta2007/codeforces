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

int n, dp[100005], p[100005], pi[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
        pi[p[i]] = i;
    }

    int res = 1;

    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        if((p[i] > 1) && pi[p[i] - 1] < i)dp[i] = 1 + dp[pi[p[i] - 1]];
    
        res = max(res, dp[i]);
    }
    printf("%d\n", n - res);
    
    return 0;
}