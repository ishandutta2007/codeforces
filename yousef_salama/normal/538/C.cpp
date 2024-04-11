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

const int MAXN = 100005;

int n, m, d[MAXN], h[MAXN];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
        scanf("%d %d", &d[i], &h[i]);
    
    bool ok = true;
    for(int i = 1; i < m; i++)
        if(abs(h[i] - h[i - 1]) > (d[i] - d[i - 1]))ok = false;
    if(!ok){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    
    int x = 0;
    for(int i = 0; i < m; i++){
        x = max(x, h[i]);
        
        if(i == 0)x = max(x, h[i] + d[i] - 1);
        if(i == (m - 1))x = max(x, h[i] + (n - d[i]));
        
        int diff = d[i] - d[i - 1], A = h[i - 1], B = h[i];
        x = max(x, (diff + A + B) / 2);
    }
    printf("%d\n", x);
    
    return 0;
}