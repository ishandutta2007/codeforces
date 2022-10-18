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

int T, n, k;
char g[4][305];
bool vis[4][305];

bool dfs(int i, int j){
    if(j == (n - 1))return true;
    
    vis[i][j] = true;
    if(g[i][j + 1 + 2 * j] == '.'){
        for(int di = -1; di <= 1; di++){
            if((i + di >= 0) && (i + di < 3)){
                if(g[i + di][j + 1 + 2 * j] == '.'){
                    if(!vis[i + di][j + 1]){
                        if(g[i + di][j + 3 + 2 * j] == '.'){
                            if(dfs(i + di, j + 1))return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i < 3; i++)
            scanf("%s", g[i]);
        for(int i = 0; i < 3; i++)
        for(int j = n; j < 305; j++)
            g[i][j] = '.';
        
        int stI, stJ;
        for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            if(g[i][j] == 's')stI = i, stJ = j;
        
        memset(vis, 0, sizeof vis);
        if(dfs(stI, stJ))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}