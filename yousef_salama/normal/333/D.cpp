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

int n, m, a[1005][1005];
bool b[1005][1005], connected[1005][1005];

bool solve(int X){
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        b[i][j] = a[i][j] >= X;
    
    memset(connected, 0, sizeof connected);
    for(int j = 0; j < m; j++){
        vector <int> v;
        for(int i = 0; i < n; i++)
            if(b[i][j])v.push_back(i);
        
        for(int x = 0; x < v.size(); x++)
        for(int y = x + 1; y < v.size(); y++){
            if(connected[v[x]][v[y]])return true;
            connected[v[x]][v[y]] = true;
        }
    }
    
    return false;
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &a[i][j]);
    
    int L = 0, R = 1 << 30;
    while(L < R){
        int M = (L + R + 1) >> 1;
        
        if(solve(M))L = M;
        else R = M - 1;
    }
    printf("%d\n", L);
    
    return 0;
}