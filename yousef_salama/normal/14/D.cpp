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
int n, a[205], b[205];
bool comp[205], g[205][205];
void dfs(int i, int parent){
    comp[i] = true;
    for(int u = 0; u < n; u++)
        if(g[i][u] && (u != parent)){
            dfs(u, i);
        }
}
int calc(int i, int parent, int XOR){
    int ret = 0;
    for(int u = 0; u < n; u++)
        if(g[i][u] && (u != parent) && (comp[u] ^ XOR))
            ret = max(ret, calc(u, i, XOR) + 1);
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < (n - 1); i++){
        scanf("%d %d", &a[i], &b[i]);
        a[i]--, b[i]--;
        g[a[i]][b[i]] = g[b[i]][a[i]] = true;
    }
    int ans = 0;
    for(int i = 0; i < (n - 1); i++){
        memset(comp, 0, sizeof comp);
        dfs(a[i], b[i]);
        int max1 = 0, max2 = 0;
        for(int j = 0; j < n; j++)
            if(comp[j])max1 = max(max1, calc(j, -1, 0));
        for(int j = 0; j < n; j++)
            if(!comp[j])max2 = max(max2, calc(j, -1, 1));
        ans = max(ans, max1 * max2);
    }
    printf("%d\n", ans);
    return 0;
}