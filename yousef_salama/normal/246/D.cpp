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

int n, m, c[MAXN], ai, bi;
set <int> d[MAXN];

int maxcolor;
bool colorexist[MAXN];

int main(){
    scanf("%d %d", &n, &m);
    
    maxcolor = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
        c[i]--;
        
        colorexist[c[i]] = true;
        maxcolor = max(maxcolor, c[i]);
    }
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        if(c[ai] != c[bi]){
            d[c[ai]].insert(c[bi]);
            d[c[bi]].insert(c[ai]);
        }
    }

    int x = -1, y = -1;
    for(int color = 0; color <= maxcolor; color++)if(colorexist[color]){
        if(x == -1 || d[color].size() > y){
            x = color;
            y = d[color].size();
        }
    }
    printf("%d\n", x + 1);
    
    return 0;
}