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

int n, k, l, b[10005], x[15], a[105];
int cn, c[25], dist[25][10005], dp[1 << 20];

int main(){
    scanf("%d %d %d", &n, &k, &l);
    n += 2;
    
    for(int i = 0; i < k; i++){
        scanf("%d", &x[i]);
        b[x[i]] = 1;
    }
    for(int i = 0; i < l; i++)
        scanf("%d", &a[i]);

    memset(dist, 63, sizeof dist);
    
    cn = 0;
    for(int i = 0; i + 1 < n; i++)if(b[i] != b[i + 1]){
        c[cn++] = i;
        int s = cn - 1;

        queue <int> q;

        dist[s][i] = 0;
        q.push(i);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int x = 0; x < l; x++)
            for(int d = -1; d <= 1; d++)if(d != 0){
                int v = u + a[x] * d;
                if(v >= 0 && v < n - 1){
                    if(dist[s][u] + 1 < dist[s][v]){
                        dist[s][v] = dist[s][u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    
    memset(dp, 63, sizeof dp);
    for(int mask = 0; mask < (1 << cn); mask++){
        if(mask == 0)dp[mask] = 0;
        else{
            for(int i = 0; i < cn; i++)if(mask & (1 << i)){
                for(int j = i + 1; j < cn; j++)if(mask & (1 << j))
                    dp[mask] = min(dp[mask], dp[mask ^ (1 << i) ^ (1 << j)] + dist[i][c[j]]);
                break;
            }
        }
    }
    
    if(dp[(1 << cn) - 1] > 10000000)printf("-1\n");
    else printf("%d\n", dp[(1 << cn) - 1]);
    
    return 0;
}