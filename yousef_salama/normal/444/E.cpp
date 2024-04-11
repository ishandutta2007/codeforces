#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

int n, ai, bi, ci, X[MAXN];
vector < pair <int, int> > G[MAXN];

bool vis[MAXN];
int dfs(int i, int v){
    vis[i] = true;
    
    int r = 1 + X[i];
    for(pair <int, int> u : G[i]){
        if(vis[u.first])continue;
        if(u.second >= v)continue;
        
        r += dfs(u.first, v);
    }
    return r;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < (n - 1); i++){
        scanf("%d %d %d", &ai, &bi, &ci);
        ai--, bi--;
        
        G[ai].push_back({bi, ci});
        G[bi].push_back({ai, ci});
    }
    
    int s = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &X[i]);
        s += X[i];
    }    

    int L = 0, R = 10005;
    while(L < R){
        int mid = (L + R + 1) / 2;
        
        bool ok = true;
        
        memset(vis, false, sizeof vis);
        for(int i = 0; i < n; i++)if(!vis[i]){
            int r = s - dfs(i, mid);
            if(r < 0)ok = false;
        }
        
        if(ok)L = mid;
        else R = mid - 1;
    }
    printf("%d\n", L);
    
    return 0;
}