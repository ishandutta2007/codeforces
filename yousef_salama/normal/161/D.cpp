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
#define MAXN 50005
#define MAXK 505
using namespace std;

int n, k, ai, bi, C[MAXN][MAXK], father[MAXN];
vector <int> g[MAXN];

void init(int i, int parent = -1){
    father[i] = parent;
    
    C[i][0] = 1;
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u == parent)continue;
        
        init(u, i);
        for(int x = 0; x < k; x++)
            C[i][x + 1] += C[u][x];
    }
}
int main(){
    scanf("%d %d", &n, &k);
    for(int edges = n - 1; edges > 0; edges--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    init(0);
    
    long long res = 0;
    for(int i = 0; i < n; i++){
        res += C[i][k];
        
        long long sum = 0;
        for(int j = 0; j < g[i].size(); j++){
            int u = g[i][j];
            if(u == father[i])continue;
            
            for(int x = 1; x <= k - 1; x++)
                sum += C[u][x - 1] * (C[i][k - x] - C[u][k - x - 1]);
        }
        res += sum / 2;
    }
    printf("%I64d\n", res);
    return 0;
}