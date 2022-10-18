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

int n, m, D[100005], ai[100005], bi[100005];
vector <int> G[100005];
bool ers[100005];

bool vis[100005];
void dfs(int u, int p = -1){
    vis[u] = true;

    int pi = -1;
    for(int j = 0; j < G[u].size(); j++){
        int v = ai[G[u][j]] ^ bi[G[u][j]] ^ u;

        if(!vis[v])dfs(v, u);
        else if(v == p)pi = G[u][j];
    }

    bool x = false;
    if((D[u] % 2) != 0){
        ers[pi] = true;
        x = true;

        D[p]--;
        D[u]--;
    }
    
    int a = 0, b = 0;
    while(a < G[u].size()){
        while((a < G[u].size()) && (ers[G[u][a]]))a++;

        b = a + 1;
        while((b < G[u].size()) && (ers[G[u][b]]))b++;

        if(b < G[u].size()){
            int va = ai[G[u][a]] ^ bi[G[u][a]] ^ u;
            int vb = ai[G[u][b]] ^ bi[G[u][b]] ^ u;
            printf("%d %d %d\n", va + 1, u + 1, vb + 1);

            ers[G[u][a]] = true;
            D[ai[G[u][a]]]--, D[bi[G[u][a]]]--;
            
            ers[G[u][b]] = true;
            D[ai[G[u][b]]]--, D[bi[G[u][b]]]--;
        }
        a++;
    }

    if(x){
        ers[pi] = false;
        D[p]++, D[u]++;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    if((m % 2) != 0){
        printf("No solution\n");
        return 0;
    }

    for(int i = 0; i < m; i++){
        scanf("%d %d", &ai[i], &bi[i]);
        ai[i]--, bi[i]--;

        G[ai[i]].push_back(i);
        G[bi[i]].push_back(i);

        D[ai[i]]++, D[bi[i]]++;
    }
    dfs(0);
    
    return 0;
}