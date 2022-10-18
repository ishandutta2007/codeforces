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

int n, a[200005], g[400005], d[400005], cycle[400005], f[400005];
bool vis[400005];

long long sum[400005];

long long find_sum(int i){
    if(sum[i] != -1)return sum[i];
    
    if(0 <= g[i] && g[i] < 2 * n){
        return sum[i] = a[i / 2] + find_sum(g[i]);
    }else return sum[i] = a[i / 2];
}

bool find(int i){
    if(f[i] != -1)return f[i];
    
    if(i == 1)return f[i] = true;
    if(0 <= g[i] && g[i] < 2 * n){
        return f[i] = find(g[i]);
    }else return f[i] = false;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
        scanf("%d", &a[i]);
    
    
    g[0] = 0;
    g[1] = -1;
    
    for(int i = 1; i < n; i++){
        g[2 * i] = 2 * (i + a[i]) + 1;
        g[2 * i + 1] = 2 * (i - a[i]);
    }

    memset(sum, -1, sizeof sum);
    memset(f, -1, sizeof f);
    memset(cycle, -1, sizeof cycle);
    
    for(int i = 0; i < 2 * n; i++){
        if(!vis[i]){
            int j = i;
            
            bool iscycle = false;
            while(0 <= j && j < 2 * n){
                if(vis[j]){
                    if(cycle[j] == -1){
                        iscycle = true;
                    }else if(cycle[j] == 0){
                        iscycle = false;
                    }else{
                        iscycle = true;
                    }
                    break;
                }
                vis[j] = true;
                j = g[j];
            }
            
            j = i;
            while(0 <= j && j < 2 * n){
                if(cycle[j] != -1)break;
                cycle[j] = iscycle;
                
                j = g[j];
            }
        }
    }
    
    
    for(int i = 1; i < n; i++){
        if(cycle[2 * i + 1])printf("-1\n");
        else printf("%I64d\n", find_sum(2 * i + 1) + i * (find(2 * i + 1) + 1));
    }
    return 0;
}