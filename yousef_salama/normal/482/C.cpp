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

int n, m;
char s[55][25];

long long x[1 << 20];
double dp[1 << 20];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);
    m = strlen(s[0]);
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)if(i != j){
        int mask = 0;
        for(int k = 0; k < m; k++)
            if(s[i][k] == s[j][k])mask |= (1 << k);
        x[mask] |= (1LL << i);
    }
    for(int mask = (1 << m) - 1; mask > 0; mask--)
    for(int k = 0; k < m; k++)if(mask & (1 << k))
        x[mask ^ (1 << k)] |= x[mask];
    
    dp[0] = 1.0;
    double total = 0.0;
    
    for(int mask = 0; mask < (1 << m); mask++){
        int cnt = 0;
        for(int k = 0; k < m; k++)if(!(mask & (1 << k)))cnt++;
        
        for(int k = 0; k < m; k++)if(!(mask & (1 << k))){
            dp[mask ^ (1 << k)] += dp[mask] / cnt;
            
            long long cmask = x[mask] ^ x[mask ^ (1 << k)]; int c = 0;
            while(cmask > 0)cmask -= cmask & (-cmask), c++;

            total += (dp[mask] / cnt) * (m - cnt + 1) * (1.0 * c / n);
        }
    }
    printf("%.015f\n", total);
    
    return 0;
}