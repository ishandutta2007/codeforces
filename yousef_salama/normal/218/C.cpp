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
#include <cstring>
#include <sstream>
using namespace std;
int n, x[105], y[105];
bool v[105], G[105][105];
void dfs(int i){
    v[i] = true;
    for(int j = 0; j < n; j++)
        if(G[i][j] && !v[j])dfs(j);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &x[i], &y[i]);

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        if(x[i] == x[j] || y[i] == y[j])G[i][j] = true;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(!v[i]){
            cnt++;
            dfs(i);
        }
    printf("%d\n", cnt - 1);
    return 0;
}