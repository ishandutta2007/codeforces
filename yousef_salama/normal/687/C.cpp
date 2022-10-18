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

int n, k, c[505];
bool dp[505][505][505];

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);
        
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= k; j++)
    for(int l = 0; l <= k; l++){
        if(l > j){
            dp[i][j][l] = false;
            continue;
        }
        
        if(i == 0){
            if((j == 0) && (l == 0))dp[i][j][l] = true;
            else dp[i][j][l] = false;
        }else{
            dp[i][j][l] = dp[i - 1][j][l];
            if(c[i - 1] <= j){
                dp[i][j][l] |= dp[i - 1][j - c[i - 1]][l];
                if(c[i - 1] <= l)dp[i][j][l] |= dp[i - 1][j - c[i - 1]][l - c[i - 1]];
            }
        }
    }
    
    vector <int> r;
    for(int l = 0; l <= k; l++)
        if(dp[n][k][l])r.push_back(l);
        
    printf("%d\n", r.size());
    for(int i = 0; i < r.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", r[i]);
    }
    printf("\n");
    
    return 0;
}