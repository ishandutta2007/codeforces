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

#define MAXN 80005

int n, ui, vi;
unsigned long long C[MAXN];
vector <int> g[MAXN], a[MAXN];

void precalc(int i, int parent = -1){
    C[i] = 1;
    
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u == parent)continue;
        
        a[i].push_back(u);
        
        precalc(u, i);
        C[i] += C[u];
    }
}

unsigned long long solve(int i){
    unsigned long long x = C[i] * C[i];
    
    for(int j = 0; j < a[i].size(); j++){
        int u = a[i][j];
        x -= C[u] * C[u];
    }
    x--;
    x /= 2;
    
    return x * x + 2 * x * (n - C[i]) * C[i];
}

int main(){
    scanf("%d", &n);
    
    for(int e = 0; e < n - 1; e++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    
    precalc(0);
    
    unsigned long long res = (long long)n * (n - 1) / 2;
    res = res * res;
    
    for(int i = 0; i < n; i++)
        res -= solve(i);
    
    printf("%I64d\n", res);
    return 0;
}