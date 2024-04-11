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
int n, r, ai[1000005], bi[100005], m, type, id, a, b, chain[100005], ind[100005];
vector <int> g[100005], tree[100005];
void dfs(int i, int prev){
    if(chain[i] != -1)
        tree[chain[i]].push_back(0);
    
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u != prev){
            if(i == r)chain[u] = j;
            else chain[u] = chain[i];
            
            ind[u] = ind[i] + 1;
            dfs(u, i);
        }
    }
}
void add(int t, int i, int v){
    while(i < tree[t].size()){
        tree[t][i] += v;
        i += i & (-i);
    }
}
int sum(int t, int i){
    int ret = 0;
    while(i > 0){
        ret += tree[t][i];
        i -= i & (-i);
    }
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int e = 0; e < n - 1; e++){
        scanf("%d %d", &ai[e], &bi[e]);
        ai[e]--, bi[e]--;
        
        g[ai[e]].push_back(bi[e]);
        g[bi[e]].push_back(ai[e]);
    }
    for(int i = 0; i < n; i++)
        if(g[i].size() > 2)r = i;
    
    for(int i = 0; i < n; i++)tree[i].push_back(0);
    chain[r] = -1;
    dfs(r, -1);
    
    scanf("%d", &m);
    while(m--){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d", &id);
            id--;
            
            a = ai[id], b = bi[id];
            if(ind[a] > ind[b])swap(a, b);
            
            add(chain[b], ind[b], -1);
        }else if(type == 2){
            scanf("%d", &id);
            id--;
            
            a = ai[id], b = bi[id];
            if(ind[a] > ind[b])swap(a, b);
            
            add(chain[b], ind[b], 1);
        }else{
            int ui, vi;
            scanf("%d %d", &ui, &vi);
            
            ui--, vi--;
            if(ui == r){
                if(sum(chain[vi], ind[vi]) == 0)printf("%d\n", ind[vi]);
                else printf("-1\n");
            }else if(vi == r){
                if(sum(chain[ui], ind[ui]) == 0)printf("%d\n", ind[ui]);
                else printf("-1\n");
            }else if(chain[ui] != chain[vi]){
                if(sum(chain[ui], ind[ui]) == 0 && sum(chain[vi], ind[vi]) == 0)
                    printf("%d\n", ind[vi] + ind[ui]);
                else printf("-1\n");
            }else{
                if(ind[vi] > ind[ui]){
                    if(sum(chain[vi], ind[vi]) - sum(chain[ui], ind[ui]) == 0)
                        printf("%d\n", ind[vi] - ind[ui]);
                    else printf("-1\n");
                }else{
                    if(sum(chain[ui], ind[ui]) - sum(chain[vi], ind[vi]) == 0)
                        printf("%d\n", ind[ui] - ind[vi]);
                    else printf("-1\n");
                }
            }
        }
    }
    return 0;
}