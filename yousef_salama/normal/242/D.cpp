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
int n, m, ui, vi, k, a[100005], b[100005];
vector <int> g[100005];
bool pushed[100005];
int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    queue <int> q;
    for(int i = 0; i < n; i++)
        if(a[i] == 0)q.push(i);
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        pushed[v] = true;
        b[v]++;
        
        for(int j = 0; j < g[v].size(); j++){
            int u = g[v][j];
            
            b[u]++;
            if(b[u] == a[u])q.push(u);
        }
        
        k++;
    }
    printf("%d\n", k);
    
    for(int i = 0, first = 1; i < n; i++)if(pushed[i]){
        if(first)first = 0;
        else printf(" ");
        
        printf("%d", i + 1);
    }
    printf("\n");
    return 0;
}