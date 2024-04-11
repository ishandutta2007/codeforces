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
#include <cstring>
#include <sstream>
using namespace std;
int n, p, limit, w[300005];
long long x, dp[300005], ans[300005];
struct state{
    int a, b, i;
};
bool operator <(state a, state b){
    return a.b < b.b;
}
state q[300005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    scanf("%d", &p);
    for(int i = 0; i < p; i++){
        scanf("%d %d", &q[i].a, &q[i].b);
        q[i].i = i;
    }
    
    sort(q, q + p);
    for(int i = 0; i < p; i++){
        if(q[i].b <= 600){
            if(i > 0 && q[i].b == q[i - 1].b)ans[q[i].i] = dp[q[i].a - 1];
            else{
                for(int j = n - 1; j >= 0; j--)
                    dp[j] = (j + q[i].b < n ? dp[j + q[i].b] : 0) + w[j];
                ans[q[i].i] = dp[q[i].a - 1];
            }
        }else{
            x = 0;
            for(int j = q[i].a - 1; j < n; j += q[i].b)
                x += w[j];
            ans[q[i].i] = x;
        }
    }
    
    for(int i = 0; i < p; i++)
        printf("%I64d\n", ans[i]);
    return 0;
}