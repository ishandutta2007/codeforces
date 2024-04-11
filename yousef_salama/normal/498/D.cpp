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

int tree[4 * 100005][65];
void update(int i, int L, int R, int x, int y){
    if((x < L) || (R < x))return;
    if(L == R){
        for(int t = 0; t < 60; t++){
            if(((t % y) == 0))tree[i][t] = 2;
            else tree[i][t] = 1;
        }
        return;
    }
        
    int mid = (L + R) / 2;
    update(2 * i, L, mid, x, y);
    update(2 * i + 1, mid + 1, R, x, y);
    
    for(int t = 0; t < 60; t++)
        tree[i][t] = tree[2 * i][t] + tree[2 * i + 1][(t + tree[2 * i][t]) % 60];
}

int c_d, d[50][65];

int query(int i, int L, int R, int x, int y){
    if((y < L) || (R < x))return -1;
    if((x <= L) && (R <= y)){
        int r = c_d++;
        for(int t = 0; t < 60; t++)d[r][t] = tree[i][t];
        return r;
    }
    
    int mid = (L + R) / 2;
    int r_L = query(2 * i, L, mid, x, y);
    int r_R = query(2 * i + 1, mid + 1, R, x, y);

    if(r_L == -1)return r_R;
    if(r_R == -1)return r_L;

    for(int t = 0; t < 60; t++)
        d[r_L][t] += d[r_R][(t + d[r_L][t]) % 60];
    return r_L;
}

int n, a[100005], q, xi, yi;
char ci;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        update(1, 0, n - 1, i, a[i]);
    }

    scanf("%d", &q);
    while(q--){
        scanf(" %c", &ci);
        if(ci == 'A'){
            scanf("%d %d", &xi, &yi);
            xi--, yi--;

            c_d = 0;
            int r = query(1, 0, n - 1, xi, yi - 1);
            printf("%d\n", d[r][0]);
        }
        if(ci == 'C'){
            scanf("%d %d", &xi, &yi);
            xi--;

            update(1, 0, n - 1, xi, yi);
        }
    }
    return 0;
}