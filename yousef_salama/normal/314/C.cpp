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

int t[1000005];
int sum(int i){
    i++;
    
    int ret = 0;
    while(i > 0){
        ret += t[i];
        ret %= MOD;
        
        i -= i & (-i);
    }
    return ret;
}

void add(int i, int v){
    i++;
    
    while(i < 1000005){
        t[i] += v;
        t[i] %= MOD;
        
        i += i & (-i);
    }
}

int n, a[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for(int i = 0; i < n; i++){
        int x = a[i];
        
        int cur = (sum(x) - sum(x - 1) + MOD) % MOD;
        int nxt = (x + (long long)x * sum(x)) % MOD;
        
        add(x, (nxt - cur + MOD) % MOD);
    }
    printf("%d\n", sum(1000002));
    return 0;
}