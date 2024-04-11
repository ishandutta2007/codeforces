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
int n, a[100005], ind[100005][30];
bool f[2000005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int b = 0; b < 25; b++){
        ind[n][b] = n;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] & (1 << b)){
                ind[i][b] = i;
            }else ind[i][b] = ind[i + 1][b];
        }
    }
    for(int st = 0; st < n; st++){
        if(a[st] == 0)f[0] = true;
        
        int cur = 0;
        while(true){
            int k = n;
            for(int b = 0; b < 25; b++)
                if(!(cur & (1 << b))){
                    k = min(k, ind[st][b]);
                }
            if(k == n)break;
            
            cur |= a[k];
            f[cur] = true;
        }
    }
    int ans = 0;
    for(int i = 0; i < 2000005; i++)
        if(f[i])ans++;
    printf("%d\n", ans);
    return 0;
}