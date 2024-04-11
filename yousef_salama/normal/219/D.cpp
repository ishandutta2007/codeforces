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
int n, si, ti, ans[200005];
vector <int> g[200005], dir[200005];
int dfs(int i, int parent){
    int ret = 0;
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u != parent){
            ret += dfs(u, i) + !dir[i][j];
        }
    }
    return ret;
}
void dfs2(int i, int parent){
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u != parent){
            if(dir[i][j]){
                ans[u] = ans[i] + 1;
            }else{
                ans[u] = ans[i] - 1;
            }
            dfs2(u, i);
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < (n - 1); i++){
        scanf("%d %d", &si, &ti);

        g[si - 1].push_back(ti - 1);
        dir[si - 1].push_back(true);

        g[ti - 1].push_back(si - 1);
        dir[ti - 1].push_back(false);
    }
    ans[0] = dfs(0, -1);
    dfs2(0, -1);
 
    int M = *min_element(ans, ans + n);
    printf("%d\n", M);
    bool first = true;
    for(int i = 0; i < n; i++){
        if(ans[i] == M){
            if(!first)printf(" ");
            first = false;

            printf("%d", i + 1);
        }
    }
    printf("\n");
    return 0;
}