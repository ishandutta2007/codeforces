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
int n, b[4005], next[4005][4005], dp[4005][4005];
int calc(int i, int j){
    if(dp[i][j] != -1)return dp[i][j];
    
    if(j == n - 1 || next[i][j + 1] == n)return dp[i][j] = 0;
    else return dp[i][j] = 1 + calc(j, next[i][j + 1]);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            if(b[j] == b[i])next[i][j] = j;
            else{
                if(j == n - 1)next[i][j] = n;
                else next[i][j] = next[i][j + 1];
            }
        }
    }
    
    memset(dp, -1, sizeof dp);
    
    int ans = 1;
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++){
        ans = max(ans, calc(i, j) + 2);
    }
    printf("%d\n", ans);
    return 0;
}