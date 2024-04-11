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
int n, m, a[105][105], sr[105], sc[105], r[105], c[105];
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        scanf("%d", &a[i][j]);
        
        sr[i] += a[i][j];
        sc[j] += a[i][j];
    }
    
    while(true){
        bool ok = false;
        for(int i = 0; i < n; i++)if(sr[i] < 0){
            r[i]++;
            for(int j = 0; j < m; j++){
                sr[i] -= a[i][j];
                sc[j] -= a[i][j];
                
                a[i][j] = -a[i][j];
                
                sr[i] += a[i][j];
                sc[j] += a[i][j];
            }
            ok = true;
            break;
        }
        if(ok)continue;
        
        for(int j = 0; j < m; j++)if(sc[j] < 0){
            c[j]++;
            for(int i = 0; i < n; i++){
                sr[i] -= a[i][j];
                sc[j] -= a[i][j];
                
                a[i][j] = -a[i][j];
                
                sr[i] += a[i][j];
                sc[j] += a[i][j];
            }
            ok = true;
            break;
        }
        if(ok)continue;
        
        break;
    }
    int cntR = 0, cntC = 0;
    for(int i = 0; i < n; i++)
        if(r[i] & 1)cntR++;
    printf("%d", cntR);
    for(int i = 0; i < n; i++)
        if(r[i] & 1)printf(" %d", i + 1);
    printf("\n");
    
    for(int j = 0; j < m; j++)
        if(c[j] & 1)cntC++;
    printf("%d", cntC);
    for(int j = 0; j < m; j++)
        if(c[j] & 1)printf(" %d", j + 1);
    printf("\n");
    return 0;
}