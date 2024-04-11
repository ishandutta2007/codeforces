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

const int MAXN = 1000005;

char s[MAXN];
int n, m, L, R;
int sum[MAXN];

struct segment_tree{
    int tree[4 * MAXN];
    
    void reset(){
        memset(tree, 0, sizeof tree);
    }
    
    int find_min(int i, int L, int R, int p, int q){
        if(p <= L && R <= q)return tree[i];
        if(R < p || q < L)return 1 << 30;
        
        int mid = (L + R) >> 1;
        return min(find_min(2 * i, L, mid, p, q), find_min(2 * i + 1, mid + 1, R, p, q));
    }
    int find_min(int p, int q){
        return find_min(1, 0, MAXN - 1, p, q);
    }
    
    void change(int i, int L, int R, int k, int v){
        if(k < L || R < k)return;
        if(L == R){
            tree[i] = v;
            return;
        }
        
        int mid = (L + R) >> 1;
        change(2 * i, L, mid, k, v);
        change(2 * i + 1, mid + 1, R, k, v);
        
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    void change(int k, int v){
        change(1, 0, MAXN - 1, k, v);
    }
} tree;

int main(){
    scanf("%s", s);
    n = strlen(s);
    
    tree.reset();
    for(int i = 0; i < n; i++){
        if(s[i] == '(')sum[i] = 1;
        else sum[i] = -1;
        
        if(i > 0)sum[i] += sum[i - 1];
        tree.change(i, sum[i]);
    }
    
    
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &L, &R);
        L--, R--;
        
        int a = L > 0 ? sum[L - 1] : 0;
        int b = sum[R];
        
        int M = tree.find_min(L, R);
        int X = max(0, - (M - a));
        int Y = b - a + X;
        
        printf("%d\n", (R - L + 1) - (X + Y));
    }
    
    return 0;
}