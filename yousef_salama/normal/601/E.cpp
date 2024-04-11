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

#define MOD 1000000007
#define P 10000019

int n, k, q, ti[30005], vi, wi, xi, v[15005], w[15005], st[15005], en[15005];
vector <int> tree[4 * 30005];
int dp[30][1005];
void add(int i, int L, int R, int p, int q, int y){
    if((q < L) || (R < p))return;
    if((p <= L) && (R <= q)){
        tree[i].push_back(y);
        return;    
    }

    int mid = (L + R) / 2;
    add(2 * i, L, mid, p, q, y);
    add(2 * i + 1, mid + 1, R, p, q, y);
}
void solve(int i, int L, int R, int d){
    for(int j = 0; j < tree[i].size(); j++)
    for(int z = k; z >= 0; z--)if(z >= w[tree[i][j]])
        dp[d][z] = max(dp[d][z], dp[d][z - w[tree[i][j]]] + v[tree[i][j]]);

    if(L == R){
        if(ti[L] == 3){
            long long r = 0, p = 1;
            for(int j = 1; j <= k; j++){
                r += dp[d][j] * p;
                r %= MOD;
                
                p *= P;
                p %= MOD;
            }
            printf("%I64d\n", r);
        }
        return;
    }

    int mid = (L + R) / 2;

    for(int z = 0; z <= k; z++)dp[d + 1][z] = dp[d][z];
    solve(2 * i, L, mid, d + 1);

    for(int z = 0; z <= k; z++)dp[d + 1][z] = dp[d][z];
    solve(2 * i + 1, mid + 1, R, d + 1);
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &v[i], &w[i]);

    scanf("%d", &q);
    for(int i = 0; i < n; i++){
        st[i] = 0;
        en[i] = q - 1;
    }

    for(int i = 0; i < q; i++){
        scanf("%d", &ti[i]);
        
        if(ti[i] == 1){
            scanf("%d %d", &vi, &wi);
            v[n] = vi, w[n] = wi;
            st[n] = i;
            en[n] = q - 1;
            n++;
        }else if(ti[i] == 2){
            scanf("%d", &xi);
            en[xi - 1] = i;
        }else continue;
    }
    
    for(int i = 0; i < n; i++)add(1, 0, q - 1, st[i], en[i], i);
    solve(1, 0, q - 1, 0);

    return 0;
}