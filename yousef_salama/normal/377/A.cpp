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

int n, m, k, cnt, nempty;
char g[505][505];

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

bool vis[505][505];
void dfs(int i, int j){
    vis[i][j] = true;
    cnt++;

    if(cnt == nempty - k)return;

    for(int d = 0; d < 4; d++){
        int ni = i + di[d], nj = j + dj[d];
        if(0 <= ni && ni < n && 0 <= nj && nj < m){
            if(!vis[ni][nj] && g[ni][nj] == '.')dfs(ni, nj);
            if(cnt == nempty - k)return;
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    nempty = 0;
    for(int i = 0; i < n; i++){
        scanf("%s", g[i]);
        for(int j = 0; j < m; j++)nempty += g[i][j] == '.';
    }
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(g[i][j] == '.'){
            dfs(i, j);
            goto print;
        }
    print:
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(!vis[i][j] && g[i][j] == '.')g[i][j] = 'X';
        printf("%s\n", g[i]);
    }
    
    return 0;
}