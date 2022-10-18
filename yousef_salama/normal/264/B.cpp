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

int n, a[100005], dp[100005], divisors[100005];
vector <int> v[100005];
void update(int i){
    for(int j = 0; j < v[a[i]].size(); j++)
        divisors[v[a[i]][j]] = max(divisors[v[a[i]][j]], dp[i]);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    
    for(int x = 1; x < 100005; x++){
        for(int d = 2; d * d <= x; d++)if(x % d == 0){
            v[x].push_back(d);
            if(x / d != d)v[x].push_back(x / d);
        }
        v[x].push_back(x);
    }
    
    dp[0] = 1;
    update(0);
    
    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < v[a[i]].size(); j++)
            dp[i] = max(dp[i], 1 + divisors[v[a[i]][j]]);

        update(i);
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}