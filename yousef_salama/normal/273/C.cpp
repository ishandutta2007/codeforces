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
#define MOD 1000000007
using namespace std;

const int MAXN = 300005;

int n, m, ai, bi, party[MAXN], enm_party[MAXN];
vector <int> g[MAXN];

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    
    queue <int> q;
    
    for(int i = 0; i < n; i++){
        party[i] = 0;
        enm_party[i] = g[i].size();
        
        if(enm_party[i] >= 2)q.push(i);
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        if(enm_party[u] < 2)continue;
        
        party[u] ^= 1;
        enm_party[u] = g[u].size() - enm_party[u];
        
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            
            if(party[u] == party[v]){
                enm_party[v]++;
                if(enm_party[v] >= 2)q.push(v);
            }else{
                enm_party[v]--;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        printf("%d", party[i]);
    printf("\n");
    
    
    return 0;
}