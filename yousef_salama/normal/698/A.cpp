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
#include <unordered_map>

using namespace std;

int n, a[105], dp[105][3];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for(int i = n; i >= 0; i--)
    for(int j = 0; j <= 2; j++){
        if(i == n)dp[i][j] = 0;
        else{
            dp[i][j] = 1 + dp[i + 1][0];
            if(a[i] & (1 << 0)){
                if(j != 1)dp[i][j] = min(dp[i][j], dp[i + 1][1]);
            }
            if(a[i] & (1 << 1)){
                if(j != 2)dp[i][j] = min(dp[i][j], dp[i + 1][2]);
            }
        }
    }
    printf("%d\n", dp[0][0]);
    
    return 0;
}