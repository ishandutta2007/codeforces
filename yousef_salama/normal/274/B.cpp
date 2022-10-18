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

int n, ai, bi, v[100005];
vector <int> g[100005];

pair <long long, long long> solve(int i, int parent = -1){
    pair <long long, long long> res;
    
    if(v[i] >= 0)res = make_pair(v[i], 0);
    else res = make_pair(0, -v[i]);
    
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u == parent)continue;
        
        pair <long long, long long> cur = solve(u, i);
        
        if(res.first >= cur.first && res.second >= cur.second)continue;
        
        if(res.first < cur.first){
            res.first = cur.first;
            res.second = res.first - v[i];
        }
        if(res.second < cur.second){
            res.second = cur.second;
            res.first = res.second + v[i];
        }
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for(int edges = 0; edges < n - 1; edges++){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    
    pair <long long, long long> res = solve(0);
    
    printf("%I64d\n", res.first + res.second);
    return 0;
}