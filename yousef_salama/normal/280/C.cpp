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

int n, ai, bi;
vector <int> g[100005];

double solve(int i, int parent = -1, int depth = 1){
    double ret = 1.0 / depth;
    
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u == parent)continue;
        
        ret += solve(u, i, depth + 1);
    }
    
    return ret;
}
int main(){
    scanf("%d", &n);
    for(int e = 0; e < n - 1; e++){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    
    printf("%.20f\n", solve(0));
    return 0;
}