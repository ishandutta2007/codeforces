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

const int MAXN = 200005;

int n, ui, vi, L[MAXN];
vector <int> g[MAXN];

int leafs(int u){
    if(g[u].size() == 0)return L[u] = 1;
    
    int res = 0;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        res += leafs(v);
    }
    return L[u] = res;
}
int solve_min(int u);
int solve_max(int u);
int solve2_min(int u);
int solve2_max(int u);

int solve_min(int u){
    if(g[u].size() == 0)return 1;
    
    int res = 0;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        res += solve_max(v) - 1;
    }
    return res + 1;
}
int solve_max(int u){
    if(g[u].size() == 0)return 1;
    
    int res = 0;        
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        res = max(res, L[u] - L[v] + solve_min(v));
        //if(u == 0)cout << (v + 1) << ' ' << L[u] << ' ' << L[v] << ' ' << (L[u] - L[v] + solve_min(v)) << endl;
    }
    return res;
}

int solve2_min(int u){
    if(g[u].size() == 0)return 1;
    
    int res = 1 << 30;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        res = min(res, solve2_max(v));
    }
    return res;
}
int solve2_max(int u){
    if(g[u].size() == 0)return 1;
    
    int res = 0;        
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        res += L[v] - solve2_min(v);
        //if(u == 0)cout << (v + 1) << ' ' << L[u] << ' ' << L[v] << ' ' << (L[u] - L[v] + solve_min(v)) << endl;
    }
    return L[u] - res;
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < (n - 1); i++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        g[ui].push_back(vi);
    }
    leafs(0);
    printf("%d %d\n", solve_max(0), solve2_max(0));
    
    
    return 0;
}