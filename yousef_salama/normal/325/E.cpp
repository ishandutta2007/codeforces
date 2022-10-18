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

int n, next[100005];
bool vis[100005];

void dfs(int u){
    vis[u] = true;

    int ui = (u + n / 2) % n;
    if(vis[ui]){
        if(next[ui] == ((2 * u) % n))next[u] = (2 * u + 1) % n;
        else next[u] = (2 * u) % n;
        
        if(!vis[next[u]])dfs(next[u]);
    }else{
        next[u] = (2 * u) % n;
        if(next[u] != u)dfs(next[u]);
        
        if(vis[ui])return;
        
        next[u] = (2 * u + 1) % n;
        if(next[u] != u)dfs(next[u]);
    }
}
int main(){
    scanf("%d", &n);
    if(n % 2 != 0){
        printf("-1\n");
        return 0;
    }
    
    memset(vis, 0, sizeof vis);
    dfs(0);
    
    int k = 0;
    do{
        printf("%d ", k);
        k = next[k];
    }while(k != 0);
    printf("0\n");
    
    return 0;
}