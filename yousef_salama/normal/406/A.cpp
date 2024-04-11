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
#define MOD 1000000007
using namespace std;

int n, a[1005][1005], q, opr, xi;
int row_sum[1005], col_sum[1005], total_row_add, total_col_add;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        scanf("%d", &a[i][j]);

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)if(i != j){
        row_sum[i] = (row_sum[i] + a[i][j]) % 2;
        col_sum[j] = (col_sum[j] + a[i][j]) % 2;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        if(i == j)ans = (ans + a[i][j] * a[i][j]) % 2;
        else ans = (ans + a[i][j] * a[j][i]) % 2;
    }
    
    scanf("%d", &q);
    while(q--){
        scanf("%d", &opr);
        
        if(opr == 1){
            scanf("%d", &xi);
            xi--;
            
            ans ^= 1;
            row_sum[xi] += n - 1;
            row_sum[xi] %= 2;
            
            ans = (ans + 2 * (col_sum[xi] + total_col_add)) % 2;
            
            col_sum[xi] = (col_sum[xi] + 1) % 2;
            total_col_add = (total_col_add + 1) % 2;
        }else if(opr == 2){
            scanf("%d", &xi);
            xi--;
            
            ans ^= 1;
            col_sum[xi] += n - 1;
            col_sum[xi] %= 2;
            
            ans = (ans + 2 * (row_sum[xi] + total_row_add)) % 2;
            
            row_sum[xi] = (row_sum[xi] + 1) % 2;
            total_row_add = (total_row_add + 1) % 2;
        }else{
            printf("%d", ans);
        }
    }
    printf("\n");
    
    return 0;
}