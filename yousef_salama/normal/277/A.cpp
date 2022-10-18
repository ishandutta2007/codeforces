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
using namespace std;

int n, m, k[105], a[105][105];
bool visited[105], know[105][105];

void dfs(int i){
    visited[i] = true;

    for(int j = 0; j < n; j++)if(!visited[j]){
        bool ok = false;
        for(int l = 0; l < k[j]; l++){
            if(know[i][a[j][l]]){
                ok = true;
                break;
            }
        }
        
        if(ok)dfs(j);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &k[i]);
        for(int j = 0; j < k[i]; j++){
            scanf("%d", &a[i][j]);
            a[i][j]--;
            
            know[i][a[i][j]] = true;
        }
    }
    
    int comp = 0;
    for(int i = 0; i < n; i++)if(!visited[i]){
        comp++;
        dfs(i);
    }
    
    bool ok = false;
    for(int i = 0; i < n; i++)
        if(k[i] > 0)ok = true;
    
    if(ok)printf("%d\n", comp - 1);
    else{
        if(n == 1)printf("0\n");
        else printf("%d\n", comp);
    }
    return 0;
}