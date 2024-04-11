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
int t, m;
long long fib[105], n, dp[105][2];
int main(){
    fib[1] = 1, fib[2] = 2;
    for(m = 3; fib[m - 1] < (1LL << 60); m++)
        fib[m] = fib[m - 1] + fib[m - 2];
    
    scanf("%d", &t);
    while(t--){
        scanf("%I64d", &n);
        
        vector <int> v;
        for(int i = m - 1; i >= 1; i--){
            if(n >= fib[i]){
                n -= fib[i];
                v.push_back(i);
            }
        }
        v.push_back(0);
        reverse(v.begin(), v.end());
        
        dp[0][0] = 1;
        dp[0][1] = 0;
        for(int i = 1; i < v.size(); i++){
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] * ((v[i] - v[i - 1] - 1) / 2)
                    + dp[i - 1][1] * ((v[i] - v[i - 1]) / 2);
        }
        printf("%I64d\n", dp[v.size() - 1][0] + dp[v.size() - 1][1]);
    }
    return 0;
}