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

int n, dp[100005][2][3];
char s[100005];
int main(){
    scanf("%d", &n);
    scanf("%s", s);

    for(int i = n; i >= 0; i--)
    for(int p = 0; p <= 1; p++)
    for(int r = 0; r <= 2; r++){
        if(i == n){
            dp[i][p][r] = 0;
        }else{
            dp[i][p][r] = dp[i + 1][p][r];
            if((s[i] - '0') != p)dp[i][p][r] = max(dp[i][p][r], 1 + dp[i + 1][p ^ 1][r]);
            else if(r > 0)dp[i][p][r] = max(dp[i][p][r], 1 + dp[i + 1][p][r - 1]);
        }
    }
    printf("%d\n", max(dp[0][0][2], dp[0][1][2]));
    
    return 0;
}