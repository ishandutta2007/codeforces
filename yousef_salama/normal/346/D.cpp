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

int n, m, ui, vi, source, dest, out_degree[1000005], d[1000005];
vector <int> ginv[1000005];

bool vis[1000005];

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        out_degree[ui]++;
        ginv[vi].push_back(ui);
    }
    scanf("%d %d", &source, &dest);
    source--, dest--;
    
    deque <int> q;
    memset(d, -1, sizeof d);
    
    d[dest] = 0;
    q.push_back(dest);
    
    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        
        if(vis[u])continue;
        vis[u] = true;
        
        for(int j = 0; j < ginv[u].size(); j++){
            int v = ginv[u][j];
            
            out_degree[v]--;
            if(out_degree[v] == 0){
                if(d[v] == -1 || d[u] < d[v]){
                    d[v] = d[u];
                    q.push_front(v);
                }
            }else{
                if(d[v] == -1){
                    d[v] = d[u] + 1;
                    q.push_back(v);
                }
            }
        }
    }
    
    printf("%d\n", d[source]);
    
    return 0;
}