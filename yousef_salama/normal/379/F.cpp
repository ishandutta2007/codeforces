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

const int MAXN = 500005;
const int MAXL = 30;

int p2[2 * MAXN][MAXL], depth[2 * MAXN], sz;
int dist(int u, int v){
    if(depth[u] < depth[v])swap(u, v);
    int su = u, sv = v;

    int d = depth[u] - depth[v];
    for(int p = 0; p < MAXL; p++)
        if((d & (1 << p)) != 0)u = p2[u][p];
    
    for(int p = MAXL - 1; p >= 0; p--)
        if(p2[u][p] != -1 && p2[v][p] != -1){
            int nu = p2[u][p], nv = p2[v][p];
            if(nu != nv)u = nu, v = nv;
        }
    if(u != v)u = p2[u][0];
    
    return depth[su] + depth[sv] - 2 * depth[u];
}

int s_diameter, e_diameter, diameter;
void update(int v){
    int u = sz++;
    depth[u] = depth[v] + 1;
    
    p2[u][0] = v;
    for(int p = 1; p < MAXL; p++){
        int cp = p2[u][p - 1];
        
        if(cp == -1)p2[u][p] = -1;
        else p2[u][p] = p2[cp][p - 1];
    }
    
    if(dist(u, s_diameter) > diameter){
        diameter = dist(u, s_diameter);
        e_diameter = u;
    }
    if(dist(u, e_diameter) > diameter){
        diameter = dist(u, e_diameter);
        s_diameter = u;
    }
}

int q, vi;
int main(){
    memset(p2, -1, sizeof p2);
    
    scanf("%d", &q);
    s_diameter = 0, e_diameter = 0, diameter = 0;
    
    sz = 1;
    for(int i = 0; i < 3; i++)update(0);
    
    while(q--){
        scanf("%d", &vi);
        vi--;
        
        update(vi);
        update(vi);
        printf("%d\n", diameter);
    }
    
    return 0;
}