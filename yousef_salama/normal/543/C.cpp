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

int n, m, a[25][25], mx[25][30], total[25][30], cm[25][30], dp[1 << 20];
char c[25][25];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
       scanf("%s", c[i]);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
       scanf("%d", &a[i][j]);
       mx[i][j] = 0; 
    }

    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            mx[j][c[i][j] - 'a'] = max(mx[j][c[i][j] - 'a'], a[i][j]);
            total[j][c[i][j] - 'a'] += a[i][j];
            cm[j][c[i][j] - 'a'] |= (1 << i);
        }
    }

    for(int mask = 0; mask < (1 << n); mask++){
        if(mask != ((1 << n) - 1))dp[mask] = 1 << 30;
        else dp[mask] = 0;
    }
    for(int mask = (1 << n) - 1; mask >= 0; mask--){
        int ji = (~mask) & -(~mask), j = 0;
        while(ji > 1)ji /= 2, j++;
        
        if(j >= n)continue;        
 
        for(int i = m - 1; i >= 0; i--){
            dp[mask] = min(dp[mask], dp[mask | (1 << j)] + a[j][i]);
            dp[mask] = min(dp[mask], total[i][c[j][i] - 'a'] - mx[i][c[j][i] - 'a'] + dp[mask | cm[i][c[j][i] - 'a']]);
        }
    }
    printf("%d\n", dp[0]);

    return 0;
}