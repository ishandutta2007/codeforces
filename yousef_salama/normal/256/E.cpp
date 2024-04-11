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
#define MAXN 80000
#define MOD 777777777
using namespace std;
int n, m, w[3][3], vi, ti, tree[4 * MAXN][3][3];

void update(int cur){
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++){
        tree[cur][i][j] = 0;
        for(int x = 0; x < 3; x++)
        for(int y = 0; y < 3; y++)
            if(w[x][y])tree[cur][i][j] = (tree[cur][i][j] + 
                    ((long long)tree[2 * cur][i][x]) * tree[2 * cur + 1][y][j]) % MOD;
    }
}
void init(int i, int L, int R){
    if(L == R){
        memset(tree[i], 0, sizeof tree[i]);
        for(int j = 0; j < 3; j++)
            tree[i][j][j] = 1;
    }else{
        int mid = (L + R) / 2;
        
        init(2 * i, L, mid);
        init(2 * i + 1, mid + 1, R);
        
        update(i);
    }
}
void change(int i, int L, int R, int ind, int val){
    if(ind < L || R < ind)return;
    if(L == R){
        if(val){
            memset(tree[i], 0, sizeof tree[i]);
            tree[i][val - 1][val - 1] = 1;
        }else{
            memset(tree[i], 0, sizeof tree[i]);
            for(int j = 0; j < 3; j++)
                tree[i][j][j] = 1;
        }
        return;
    }
    
    int mid = (L + R) / 2;
    change(2 * i, L, mid, ind, val);
    change(2 * i + 1, mid + 1, R, ind, val);
    
    update(i);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
        scanf("%d", &w[i][j]);
    init(1, 0, n - 1);
    
    while(m--){
        scanf("%d %d", &vi, &ti);
        vi--;
        
        change(1, 0, n - 1, vi, ti);
        
        int ans = 0;
        for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            ans = (ans + tree[1][i][j]) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}