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
using namespace std;
int n, color[5005], cycle[3];
char g[5005][5005];

void DFS(int u, int parent){
    color[u] = 1;
    for(int v = 0; v < n; v++){
        if(g[u][v] == '1'){
            if(color[v] == 2)continue;
            
            if(color[v] == 0){
                DFS(v, u);
            }else{
                //BackEdge
                if(parent != -1 && g[v][parent] == '1'){
                    cycle[0] = parent, cycle[1] = u, cycle[2] = v;
                }
            }
        }
    }
    color[u] = 2;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", &g[i]);
    
    memset(color, 0, sizeof color);
    cycle[0] = -1;
    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            DFS(i, -1);
            if(cycle[0] != -1){
                printf("%d %d %d\n", cycle[0] + 1, cycle[1] + 1, cycle[2] + 1);
                break;
            }
        }
    }
    if(cycle[0] == -1)printf("-1\n");
    return 0;
}