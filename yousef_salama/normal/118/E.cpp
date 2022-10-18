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

int n, m, ai, bi;
vector <int> g[100005];

bool bridge;
int intime[100005], ctime;
vector < pair <int, int> > ans;

int dfs(int u, int parent = -1){
    intime[u] = ctime++;
    int lowtime = intime[u];
    
    for(int j = 0; j < g[u].size(); j++){
        int v = g[u][j];
        if(v == parent)continue;
        
        if(intime[v] == -1){
            lowtime = min(lowtime, dfs(v, u));
            ans.push_back(make_pair(u + 1, v + 1));
        }else{
            if(intime[v] < intime[u])
                ans.push_back(make_pair(u + 1, v + 1));
            lowtime = min(lowtime, intime[v]);
        }
    }
    
    if(u > 0 && lowtime == intime[u])bridge = true;
    return lowtime;
}

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    
    memset(intime, -1, sizeof intime);
    
    ctime = 0;
    dfs(0);
    
    if(bridge)printf("0\n");
    else{
        for(int i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
    return 0;
}