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
#define MOD 1000000007
using namespace std;

int n, x, c1, c2;
long long t1[1000005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        
        if(x == 1)c1++;
        else c2++;
    }
    
    t1[0] = t1[1] = 1;
    for(int i = 2; i <= c1; i++){
        t1[i] = t1[i - 1] + t1[i - 2] * (i - 1);
        t1[i] %= MOD;
    }
    
    long long ans = t1[c1];
    for(int i = c1 + 1; i <= (c1 + c2); i++){
        ans *= i;
        ans %= MOD;
    }

    printf("%I64d\n", ans);
    
    return 0;
}