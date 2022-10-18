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
int n, m, h, t, ai, bi, d[100005];
bool taken[100005], x[100005], prin[100005];
vector <int> g[100005];
int main(){
    scanf("%d %d %d %d", &n, &m, &h, &t);
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
        
        d[ai]++;
        d[bi]++;
    }
    bool found = false;
    for(int u = 0; u < n; u++)if(d[u] > h){
        for(int k = 0; k < g[u].size(); k++){
            taken[g[u][k]] = true;
        }
        for(int j = 0; j < g[u].size(); j++){
            int v = g[u][j];
            
            bool ok = false;
            if(d[v] > 500)ok = true;
            else{
                int intr = 0;
                for(int k = 0; k < g[v].size(); k++){
                    if(g[v][k] != u && taken[g[v][k]]){
                        x[g[v][k]] = true;
                        intr++;
                    }
                }

                d[u]--;
                d[v]--;

                if(h <= d[u] - intr){
                    if(t <= d[v]){
                        ok = true;
                    }
                }else{
                    if(t <= d[v] - intr){
                        if(h <= d[u]){
                            ok = true;
                        }
                    }else{
                        if(intr >= (h - (d[u] - intr)) + (t - (d[v] - intr)))
                            ok = true;
                    }
                }
            }
            if(ok){
                for(int k = 0; k < g[u].size(); k++){
                    if(g[u][k] != v)taken[g[u][k]] = true;
                }
                for(int k = 0; k < g[v].size(); k++){
                    if(g[v][k] != u && taken[g[v][k]]){
                        x[g[v][k]] = true;
                    }
                }
                
                printf("YES\n");
                printf("%d %d\n", u + 1, v + 1);
                
                int cnt = 0;
                for(int k = 0; k < g[u].size() && cnt < h; k++)
                    if(g[u][k] != v && !x[g[u][k]]){
                        printf("%d ", g[u][k] + 1);
                        prin[g[u][k]] = true;
                        
                        cnt++;
                    }
                for(int k = 0; k < g[u].size() && cnt < h; k++){
                    if(g[u][k] != v && x[g[u][k]]){
                        printf("%d ", g[u][k] + 1);
                        prin[g[u][k]] = true;
                        
                        cnt++;
                    }
                }
                printf("\n");
                
                cnt = 0;
                for(int k = 0; cnt < t; k++){
                    if(g[v][k] != u && !prin[g[v][k]]){
                        printf("%d ", g[v][k] + 1);
                        
                        cnt++;
                    }
                }
                printf("\n");
                
                found = true;
                break;
            }
            for(int k = 0; k < g[v].size(); k++){
                if(g[v][k] != u && taken[g[v][k]]){
                    x[g[v][k]] = false;
                }
            }
            
            
            d[u]++;
            d[v]++;
        }
        for(int k = 0; k < g[u].size(); k++){
            taken[g[u][k]] = false;
        }
        if(found)break;
    }
    if(!found)printf("NO\n");
    return 0;
}