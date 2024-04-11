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
int n, m, k, a[405][405], x[405], y[405], s[405], c[30];
char g[405][405];
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        scanf("%s", g[i]);
        
        for(int j = 0; j < m; j++){
            a[i][j] = g[i][j] == 'a';
            if(i)a[i][j] += a[i - 1][j];
        }
    }
    long long ans = 0;
    for(int p1 = 0; p1 < n; p1++)
    for(int p2 = p1 + 1; p2 < n; p2++){
        for(int i = 0; i < m; i++){
            x[i] = g[p1][i] - 'a';
            y[i] = g[p2][i] - 'a';
            
            s[i] = a[p2][i];
            if(p1)s[i] -= a[p1 - 1][i];
        }
        memset(c, 0, sizeof c);
        
        int j = 0, sum = 0;
        for(int i = 0; i < m; i++){
            sum += s[i];
            if(x[i] == y[i])c[x[i]]++;
            
            while(j <= i && sum > k){
                sum -= s[j];
                if(x[j] == y[j])c[x[j]]--;
                
                j++;
            }
            
            if(i >= j && x[i] == y[i])ans += c[x[i]] - 1;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}