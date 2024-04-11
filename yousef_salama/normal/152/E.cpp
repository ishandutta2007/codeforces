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

int n, m, k, a[105][105], tot;
int xi, yi, imp[10];

int dist[205][205], mdist[205][205];
int dp[1 << 7][205], parent[1 << 7][205];
bool paved[205];

void paveroad(int u, int v){
    if(dist[u][v] == 0)return;
    
    paved[mdist[u][v]] = true;
    paveroad(u, mdist[u][v]);
    paveroad(mdist[u][v], v);
}
void pavegarden(int mask, int u){
    if((mask & (mask - 1)) == 0){
        paveroad(imp[parent[mask][u]], u);
    }else{
       if(parent[mask][u] > tot){
           int submask = parent[mask][u] - tot;
           pavegarden(submask, u);
           pavegarden(mask ^ submask, u);
       }else{
           int v = parent[mask][u];
           paved[v] = true;
           paveroad(u, v);
           pavegarden(mask, v);
       }
    }
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);
    
    
    int sum_important = 0;
    for(int i = 0; i < k; i++){
        scanf("%d %d", &xi, &yi);
        xi--, yi--;
        
        imp[i] = xi * m + yi;
        sum_important += a[xi][yi];
        a[xi][yi] = 0;
    }
    
    memset(dist, 63, sizeof dist);
    
    tot = n * m;
    for(int u = 0; u < tot; u++)
    for(int v = 0; v < tot; v++)
        if(abs(u % m - v % m) + abs(u / m - v / m) <= 1)dist[u][v] = 0;
    
    for(int i = 0; i < tot; i++)
    for(int u = 0; u < tot; u++)
    for(int v = 0; v < tot; v++){
        int ndist = dist[u][i] + a[i / m][i % m] + dist[i][v];
        if(ndist < dist[u][v]){
            dist[u][v] = ndist;
            mdist[u][v] = i;
        }
    }
    
    memset(dp, 63, sizeof dp);
    
    for(int mask = 1; mask < (1 << k); mask++){
        if((mask & (mask - 1)) == 0){
            int i = 0;
            while(i < k && ((mask & (1 << i)) == 0))i++;
            
            for(int u = 0; u < tot; u++){
                dp[mask][u] = dist[u][imp[i]]; 
                parent[mask][u] = i;
            }
        }else{
            for(int submask = mask - 1; submask > 0; submask = (submask - 1) & mask)
            for(int u = 0; u < tot; u++){
                if(dp[mask][u] > dp[submask][u] + dp[mask ^ submask][u]){
                    dp[mask][u] = dp[submask][u] + dp[mask ^ submask][u];
                    parent[mask][u] = tot + submask;
                }
            }
            
            for(int u = 0; u < tot; u++)
            for(int v = 0; v < tot; v++){
                if(dp[mask][u] > dp[mask][v] + a[v / m][v % m] + dist[u][v]){
                    dp[mask][u] = dp[mask][v] + a[v / m][v % m] + dist[u][v];
                    parent[mask][u] = v;
                }
            }
        }
    }

    int best = 1 << 30, bestu;
    for(int u = 0; u < tot; u++){
        if(best > dp[(1 << k) - 1][u] + a[u / m][u % m]){
            best = dp[(1 << k) - 1][u] + a[u / m][u % m];
            bestu = u;
        }
    }
    
    pavegarden((1 << k) - 1, bestu);
    
    paved[bestu] = true;
    for(int i = 0; i < k; i++)
        paved[imp[i]] = true;
    
    printf("%d\n", best + sum_important);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(paved[i * m + j])printf("X");
            else printf(".");
        }
        printf("\n");
    }
    
    return 0;
}