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
int n, p, t, a, b, d, c[1005], tank[1005], tap[1005], diam[1005], g[1005][1005];
int rec(int i){
    for(int j = 0; j < n; j++)
        if(g[i][j])return min(g[i][j], rec(j));
    tap[t] = i + 1;
    return 1 << 30;
}
int main(){
    scanf("%d %d", &n, &p);
    for(int i = 0; i < p; i++){
        scanf("%d %d %d", &a, &b, &d);
        g[a - 1][b - 1] = d;
        c[b - 1]++;
    }
    for(int i = 0; i < n; i++)
        if(c[i] == 0){
            tank[t] = i + 1;
            diam[t] = rec(i);
            if(diam[t] != 1 << 30)t++;
        }
    printf("%d\n", t);
    for(int i = 0; i < t; i++)
        printf("%d %d %d\n", tank[i], tap[i], diam[i]);
    return 0;
}