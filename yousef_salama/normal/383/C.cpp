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

const int MAXN = 200005;

struct BIT{
    int tree[MAXN];
    
    void reset(){
        memset(tree, 0, sizeof tree);
    }
    void add(int i, int v){
        i++;
        
        while(i < MAXN){
            tree[i] += v;
            i += i & (-i);
        }
    }
    int sum(int i){
        i++;
        
        int ret = 0;
        while(i > 0){
            ret += tree[i];
            i -= i & (-i);
        }
        return ret;
    }
} b_even, b_odd;

int n, m, a[MAXN], ui, vi;
vector <int> g[MAXN];

int ctime, in_time[MAXN], out_time[MAXN], depth[MAXN];
void dfs(int i, int parent = -1, int d = 0){
    in_time[i] = ++ctime;
    depth[i] = d;
    
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u == parent)continue;
        
        dfs(u, i, d + 1);
    }
    
    out_time[i] = ctime;
}

int operation, x, val;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int e = 0; e < n - 1; e++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    
    ctime = 0;
    dfs(0);
    

    b_even.reset();
    b_odd.reset();
    
    while(m--){
        scanf("%d", &operation);
        if(operation == 1){
            scanf("%d %d", &x, &val);
            x--;
            
            if(depth[x] % 2 == 0){
                b_even.add(in_time[x], val);
                b_even.add(out_time[x] + 1, -val);
            }else{
                b_odd.add(in_time[x], val);
                b_odd.add(out_time[x] + 1, -val);
            }
        }else{
            scanf("%d", &x);
            x--;
            
            int res = a[x];
            if(depth[x] % 2 == 0){
                res += b_even.sum(in_time[x]);
                res -= b_odd.sum(in_time[x]);
            }else{
                res += b_odd.sum(in_time[x]);
                res -= b_even.sum(in_time[x]);
            }
            printf("%d\n", res);
        }
    }
    
    
    return 0;
}