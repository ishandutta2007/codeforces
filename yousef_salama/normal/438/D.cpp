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

const int MAXN = 100005;

int a[MAXN], tree_max[4 * MAXN];
long long tree_sum[4 * MAXN];

struct segment_tree{
    void update(int i, int L, int R, int u){
        if(u < L || R < u)return;
        if(L == R){
            tree_sum[i] = a[L];
            tree_max[i] = L;
            
            return;
        }
        
        int mid = (L + R) / 2;
        update(2 * i, L, mid, u);
        update(2 * i + 1, mid + 1, R, u);
        
        tree_sum[i] = tree_sum[2 * i] + tree_sum[2 * i + 1];
        
        if(a[tree_max[2 * i]] > a[tree_max[2 * i + 1]])tree_max[i] = tree_max[2 * i];
        else tree_max[i] = tree_max[2 * i + 1];
    }
    long long find_sum(int i, int L, int R, int u, int v){
        if(v < L || R < u)return 0;
        if(u <= L && R <= v)return tree_sum[i];
    
        int mid = (L + R) / 2;
        return find_sum(2 * i, L, mid, u, v) + find_sum(2 * i + 1, mid + 1, R, u, v);
    }
    int find_max(int i, int L, int R, int u, int v){
        if(v < L || R < u)return -1;
        if(u <= L && R <= v)return tree_max[i];
        
        int mid = (L + R) / 2;
        
        int m1 = find_max(2 * i, L, mid, u, v);
        int m2 = find_max(2 * i + 1, mid + 1, R, u, v);
    
        if(m1 == -1)return m2;
        if(m2 == -1)return m1;
        
        if(a[m1] > a[m2])return m1;
        else return m2;
    }
};

int n, m, ti, li, ri, ki, xi;
int main(){
    scanf("%d %d", &n, &m);
    
    segment_tree lm7_el_bsr;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        
        lm7_el_bsr.update(1, 0, n - 1, i);
    }
    while(m--){
        scanf("%d", &ti);
        if(ti == 1){
            scanf("%d %d", &li, &ri);
            li--, ri--;
            
            printf("%I64d\n", lm7_el_bsr.find_sum(1, 0, n - 1, li, ri));
        }
        if(ti == 2){
            scanf("%d %d %d", &li, &ri, &xi);
            li--, ri--;
            
            while(true){
                int y = lm7_el_bsr.find_max(1, 0, n - 1, li, ri);
                if(a[y] < xi)break;
                
                a[y] %= xi;
                lm7_el_bsr.update(1, 0, n - 1, y);
            }
        }
        if(ti == 3){
            scanf("%d %d", &ki, &xi);
            ki--;
            
            a[ki] = xi;
            lm7_el_bsr.update(1, 0, n - 1, ki);
        }
    }
    
    return 0;
}