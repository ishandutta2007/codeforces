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
#define MOD 1000000007
using namespace std;

struct segment_tree{
    int size, tree[4 * 500005], flag[4 * 500005];
    void reset(int csize){
        size = csize;
        memset(tree, -1, sizeof tree);
        memset(flag, -1, sizeof flag);
    }
    void refresh(int i, int L, int R){
        if(flag[i] != -1){
            tree[i] = flag[i];
            
            if(2 * i < 4 * 500005)flag[2 * i] = flag[i];
            if(2 * i + 1 < 4 * 500005)flag[2 * i + 1] = flag[i];
            
            flag[i] = -1;
        }
    }
    void update(int i, int L, int R, int p, int q, int v){
        refresh(i, L, R);
        if(R < p || q < L)return;
        if(p <= L && R <= q){
            flag[i] = v;
            refresh(i, L, R);
            
            return;
        }
        
        int mid = (L + R) >> 1;
        update(2 * i, L, mid, p, q, v);
        update(2 * i + 1, mid + 1, R, p, q, v);
        
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    void update(int i, int j, int v){
        update(1, 0, size - 1, i, j, v);
    }
    
    int find_max(int i, int L, int R, int p, int q){
        refresh(i, L, R);
        
        if(R < p || q < L)return -1;
        if(p <= L && R <= q)return tree[i];
        
        int mid = (L + R) >> 1;
        return max(find_max(2 * i, L, mid, p, q), find_max(2 * i + 1, mid + 1, R, p, q));
    }
    int find_max(int i, int j){
        return find_max(1, 0, size - 1, i, j);
    }
};

int n, ai, bi, q, ci, vi, st[500005], en[500005], ctime;
vector <int> g[500005];
segment_tree Fill, Empty;

void dfs(int u, int parent = -1){
    st[u] = ctime++;
    for(int j = 0; j < g[u].size(); j++){
        int v = g[u][j];
        if(v == parent)continue;
        
        dfs(v, u);
    }
    en[u] = ctime - 1;
}
int main(){
    scanf("%d", &n);
    for(int e = 0; e < n - 1; e++){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;

        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    
    ctime = 0;
    dfs(0);
    
    Fill.reset(n);
    Empty.reset(n);
    
    scanf("%d", &q);
    for(int t = 0; t < q; t++){
        scanf("%d %d", &ci, &vi);
        vi--;
        
        if(ci == 1)Fill.update(st[vi], en[vi], t);
        if(ci == 2)Empty.update(st[vi], st[vi], t);
        if(ci == 3){
            int fill_t = Fill.find_max(st[vi], st[vi]);
            int empty_t = Empty.find_max(st[vi], en[vi]);
            
            if(fill_t > empty_t)printf("1\n");
            else printf("0\n");
        }
    }
    
    return 0;
}