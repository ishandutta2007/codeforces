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

int n, m, k, ui, vi, cedge, to_edge[400005], next_edge[400005], last_edge[400005];
int volunteers[100005], source, dest;
int dsu_parent[100005];
int que[100005], queSt, queEn, volunteer_source[100005], dist[100005];

int findr(int i){
    if(dsu_parent[i] == i)return i;
    else return dsu_parent[i] = findr(dsu_parent[i]);
}
void connect(int i, int j){
    dsu_parent[findr(i)] = findr(j);
}

bool check(int q){
    memset(volunteer_source, -1, sizeof volunteer_source);
    memset(dist, -1, sizeof dist);
    
    queSt = 0, queEn = 0;
    for(int i = 0; i < k; i++){
        dsu_parent[i] = i;
        
        volunteer_source[volunteers[i]] = i;
        dist[volunteers[i]] = 0;
        
        que[queEn++] = volunteers[i];
    }
    while(queSt != queEn){
        int v = que[queSt++];
        
        for(int i = last_edge[v]; i != -1; i = next_edge[i]){
            int u = to_edge[i];
            if(dist[u] == -1){
                dist[u] = dist[v] + 1;
                volunteer_source[u] = volunteer_source[v];
                
                que[queEn++] = u;
            }else if(dist[u] + dist[v] + 1 <= q)
                connect(volunteer_source[u], volunteer_source[v]);
        }
    }
    return findr(source) == findr(dest);
}

void add_edge(int v, int u){
    next_edge[cedge] = last_edge[v];
    to_edge[cedge] = u;
    last_edge[v] = cedge;
    cedge++;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &volunteers[i]);
        volunteers[i]--;
    }
    
    cedge = 0;
    memset(last_edge, -1, sizeof last_edge);
    
    while(m--){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        add_edge(ui, vi);
        add_edge(vi, ui);
    }
    
    scanf("%d %d", &source, &dest);
    source--, dest--;

    if(find(volunteers, volunteers + k, dest) == volunteers + k)
        volunteers[k++] = dest;
    
    source = find(volunteers, volunteers + k, source) - volunteers;
    dest = find(volunteers, volunteers + k, dest) - volunteers;
    
    if(!check(n)){
        printf("-1\n");
        return 0;
    }
    
    int L = 0, R = n;
    while(L < R){
        int mid = (L + R) / 2;
        if(check(mid))R = mid;
        else L = mid + 1;
    }
    printf("%d\n", L);
    return 0;
}