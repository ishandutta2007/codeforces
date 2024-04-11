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
#define MOD 1000000007
using namespace std;

int n, q, ti, a[305], bi, ci, next[305], prev[305];
long long t;

bool vis[305];
bool findcycle(int i){
    vis[i] = true;
    if(next[i] == -1)return false;
    if(vis[next[i]])return true;
    return findcycle(next[i]);
}
bool cycle(){
    for(int i = 0; i < n; i++)if(!vis[i]){
        memset(vis, 0, sizeof vis);
        if(findcycle(i))return true;
    }
    return false;
}

void modifypath(int i, int v){
    a[i] += v;
    if(next[i] == -1)return;
    
    t -= a[i];
    modifypath(next[i], a[i]);
}
void modify(){
    for(int i = 0; i < n; i++)if(prev[i] == -1)
        modifypath(i, 0);
}

int dp[100005];
int main(){
    scanf("%d %d %d", &n, &q, &ti);
    t = ti;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    memset(next, -1, sizeof next);
    memset(prev, -1, sizeof prev);
    while(q--){
        scanf("%d %d", &bi, &ci);
        bi--, ci--;
        next[bi] = ci;
        prev[ci] = bi;
    }
    
    if(cycle()){
        printf("0\n");
        return 0;
    }
    modify();
    if(t < 0){
        printf("0\n");
        return 0;
    }
    
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    for(int j = a[i]; j <= t; j++)
        dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
    printf("%d\n", dp[t]);
    
    return 0;
}