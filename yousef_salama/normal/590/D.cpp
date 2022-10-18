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

int n, k, s, q[155], dp[2][155][12005], max_s;
int main(){
    scanf("%d %d %d", &n, &k, &s);
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    s += k * (k - 1) / 2;
    
    max_s = 0;
    for(int i = n - k; i < n; i++)
        max_s += i;
    
    if(s >= max_s){
        sort(q, q + n);
        
        int res = 0;
        for(int i = 0; i < k; i++)
            res += q[i];
        printf("%d\n", res);
    }else{
        for(int i = n; i >= 0; i--)
        for(int j = 0; j <= k; j++)
        for(int cur_s = 0; cur_s <= s; cur_s++){
            if(i == n){
                if(j == 0)dp[i & 1][j][cur_s] = 0;
                else dp[i & 1][j][cur_s] = 1 << 30;
            }else{
                dp[i & 1][j][cur_s] = dp[(i + 1) & 1][j][cur_s];
                if((j > 0) && (cur_s - i >= 0))
                   dp[i & 1][j][cur_s] = min(dp[i & 1][j][cur_s], dp[(i + 1) & 1][j - 1][cur_s - i] + q[i]);
            }
        }
        printf("%d\n", dp[0][k][s]);
    }
    
    return 0;
}