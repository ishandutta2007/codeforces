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
#define bitcount(i) __builtin_popcount(i)
using namespace std;
int n, m, k, v1, v2;
long long a[1 << 10][1 << 10];
vector <int> g[15];
int main(){
    scanf("%d %d %d", &n, &m, &k);
    while(m--){
        scanf("%d %d", &v1, &v2);
        v1--, v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(int mask = 0; mask < (1 << n); mask++){
        if(bitcount(mask) < 2)continue;
        
        if(bitcount(mask) == 2){
            int v1 = -1, v2 = -1;
            for(int i = 0; i < n; i++)if(mask & (1 << i)){
                if(v1 == -1)v1 = i;
                else v2 = i;
            }
            
            for(int i = 0; i < g[v1].size(); i++){
                if(g[v1][i] == v2){
                    a[mask][mask] = 1;
                    break;
                }
            }
        }else{
            for(int sub = mask; sub > 0; sub = (sub - 1) & mask){
                for(int v1 = 0; v1 < n; v1++)if(sub & (1 << v1)){
                    for(int i = 0; i < g[v1].size(); i++){
                        int v2 = g[v1][i];
                        if(mask & (1 << v2)){
                            if(sub & (1 << v2))continue;

                            a[mask][sub] += a[mask ^ (1 << v1)][sub ^ (1 << v1)] + 
                                    a[mask ^ (1 << v1)][sub ^ (1 << v1) ^ (1 << v2)];
                        }
                    }
                    break;
                }
                //a[mask][sub] /= bitcount(sub);
            }
        }
    }
    long long ans = 0;
    for(int sub = (1 << n) - 1; sub > 0; sub = (sub - 1) & ((1 << n) - 1))if(bitcount(sub) == k)
        ans += a[(1 << n) - 1][sub];
    printf("%I64d\n", ans);
    return 0;
}