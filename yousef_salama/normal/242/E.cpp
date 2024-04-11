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
int n, a[100005], m, ti, li, ri, xi;
long long sum[4 * 100005], Xor[4 * 100005], cnt[4 * 100005][30];
void refresh(int i, int L, int R){
    for(int k = 20; k >= 0; k--)
        if(Xor[i] & (1 << k)){
            sum[i] -= cnt[i][k] * (1LL << k);
            sum[i] += (-cnt[i][k] + (R - L + 1)) * (1LL << k);
            
            cnt[i][k] = -cnt[i][k] + (R - L + 1); 
        }
    if(2 * i < 4 * 100005)Xor[2 * i] ^= Xor[i];
    if(2 * i + 1 < 4 * 100005)Xor[2 * i + 1] ^= Xor[i];
    
    Xor[i] = 0;
}
long long get_sum(int i, int L, int R, int Left, int Right){
    refresh(i, L, R);
    
    if(Left <= L && R <= Right)return sum[i];
    if(R < Left || Right < L)return 0;
    
    int mid = (L + R) / 2;
    return get_sum(2 * i, L, mid, Left, Right) + get_sum(2 * i + 1, mid + 1, R, Left, Right);
}
void update(int i, int L, int R, int Left, int Right, int x){
    refresh(i, L, R);
    if(Left <= L && R <= Right){
        Xor[i] ^= x;
        refresh(i, L, R);
        
        return;
    }
    if(R < Left || Right < L)return;
    
    int mid = (L + R) / 2;
    update(2 * i, L, mid, Left, Right, x);
    update(2 * i + 1, mid + 1, R, Left, Right, x);
    
    sum[i] = sum[2 * i] + sum[2 * i + 1];
    for(int k = 20; k >= 0; k--)
        cnt[i][k] = cnt[2 * i][k] + cnt[2 * i + 1][k];
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        update(1, 0, n - 1, i, i, a[i]);
    }
    scanf("%d", &m);
    while(m--){
        scanf("%d", &ti);
        if(ti == 1){
            scanf("%d %d", &li, &ri);
            li--, ri--;
            
            printf("%I64d\n", get_sum(1, 0, n - 1, li, ri));
        }else{
            scanf("%d %d %d", &li, &ri, &xi);
            li--, ri--;
            
            update(1, 0, n - 1, li, ri, xi);
        }
    }
    return 0;
}