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
#include <unordered_map>
using namespace std;

int n, m;
char s[55][55];

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

bool vis[55][55];
int calc(int i, int j){
    vis[i][j] = true;

    int r = 1;
    for(int d = 0; d < 4; d++){
        int i_ = i + di[d], j_ = j + dj[d];
        
        if((i_ < 0) || (i_ >= n))continue;
        if((j_ < 0) || (j_ >= m))continue;

        if(s[i_][j_] == '.')continue;

        if(!vis[i_][j_])r += calc(i_, j_);
    }
    return r;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", &s[i]);

    int c = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        c += s[i][j] == '#';

    if(c <= 1)printf("-1\n");
    else{
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)if(s[i][j] == '#'){
            s[i][j] = '.';
            
            bool found = false;
            for(int x = 0; x < n; x++)
            for(int y = 0; y < m; y++)if(s[x][y] == '#'){
                memset(vis, false, sizeof vis);
                if(calc(x, y) < (c - 1))found = true;
                
                goto end; 
            }
            
            end: 
            
            if(found){
                //cout << i << ' ' << j << endl;
                
                printf("1\n");
                return 0;
            }
            s[i][j] = '#';
        }
        if(c >= 3)printf("2\n");
        else printf("-1\n");
    }

    return 0;
}