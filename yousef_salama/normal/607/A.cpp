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

int n, dp[100005];
pair <int, int> v[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    sort(v, v + n);

    int res = 0;
    for(int i = 0; i < n; i++){
        int j = lower_bound(v, v + n, make_pair(v[i].first - v[i].second, 0)) - v;
        
        dp[i] = 1 + ((j > 0) ? dp[j - 1] : 0);
        res = max(res, dp[i]);
    }
    printf("%d\n", n - res);

    return 0;
}