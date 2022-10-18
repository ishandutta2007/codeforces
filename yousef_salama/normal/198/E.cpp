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

const int MAXN = 250005;


struct gripper{
    int x, y, m, p;
    long long dist, r;
    
    gripper(){};
    gripper(long long a){
        dist = a;
    }
    
} grips[MAXN];

void calc_dist(int i){
    grips[i].dist = (long long)(grips[i].x - grips[0].x) * (grips[i].x - grips[0].x)
            + (long long)(grips[i].y - grips[0].y) * (grips[i].y - grips[0].y);
}

bool operator <(gripper a, gripper b){
    return a.dist < b.dist;
}

int n, ri;
int tree[4 * MAXN];
void change(int k, int v, int i = 1, int l = 0, int r = n - 1){
    if(k < l || r < k)return;
    if(l == r){
        tree[i] = v;
        return;
    }
    
    int mid = (l + r) >> 1;
    change(k, v, 2 * i, l, mid);
    change(k, v, 2 * i + 1, mid + 1, r);
    
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}
int find_first(int v, int i = 1, int l = 0, int r = n - 1){
    if(l == r){
        if(tree[i] > v)return -1;
        return l;
    }
    
    int mid = (l + r) >> 1;
    if(tree[2 * i] <= v)return find_first(v, 2 * i, l, mid);
    else return find_first(v, 2 * i + 1, mid + 1, r);
}

int ngrips;
void dfs(int i){
    change(i, INT_MAX);
    
    int en = upper_bound(grips, grips + n, gripper((long long)grips[i].r * grips[i].r))
                - grips;
    int j = find_first(grips[i].p);
    
    while(j != -1 && j < en){
        ngrips++;
        dfs(j);
        
        j = find_first(grips[i].p);
    }
}
int main(){
    scanf("%d %d %d %d %d", &grips[0].x, &grips[0].y, &grips[0].p, &grips[0].r, &n);
    grips[0].m = INT_MAX;
    grips[0].dist = 0;
    n++;
    
    for(int i = 1; i < n; i++){
        scanf("%d %d %d %d %d", &grips[i].x, &grips[i].y, &grips[i].m, &grips[i].p, &ri);
        
        grips[i].r = ri;
        calc_dist(i);
    }
    
    
    sort(grips, grips + n);
    for(int i = 0; i < n; i++)
        change(i, grips[i].m);
    
    ngrips = 0;
    dfs(0);
    
    printf("%d\n", ngrips);
    return 0;
}