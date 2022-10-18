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
int n, ai[MAXN], ri[MAXN], li[MAXN], xi[MAXN];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &ai[i]);
    
    li[0] = -1;
    for(int i = 1; i < n; i++){
        li[i] = i - 1;
        while((li[i] >= 0) && (ai[i] <= ai[li[i]]))
            li[i] = li[li[i]];
    }
    ri[n - 1] = n;
    for(int i = n - 1; i >= 0; i--){
        ri[i] = i + 1;
        while((ri[i] < n) && (ai[i] <= ai[ri[i]]))
            ri[i] = ri[ri[i]];
    }
    
    for(int i = 0; i < n; i++){
        int d = ri[i] - li[i] - 1;
        xi[d] = max(xi[d], ai[i]);
    }
    for(int i = n - 1; i >= 0; i--)
        xi[i] = max(xi[i], xi[i + 1]);

    for(int i = 1; i <= n; i++){
        if(i > 1)printf(" ");
        printf("%d", xi[i]);
    }
    printf("\n");
    
    return 0;
}