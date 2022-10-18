#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int MOD = 1000000007;

int n, q, pi;
vector <int> G[MAXN];

int cntime, L[MAXN], R[MAXN], depth[MAXN];
void dfs(int i){
    L[i] = R[i] = cntime++;
    for(int u : G[i]){
        depth[u] = depth[i] + 1;
        dfs(u);
        
        R[i] = R[u];
    }
}

int type, v, x, k;

long long tree[2][MAXN];
void add(int idx, int i, long long x){
    i++;
    x = (x % MOD + MOD) % MOD;
    
    while(i < MAXN){
        tree[idx][i] = (tree[idx][i] + x) % MOD;
        i += i & (-i);
    }
}
long long sum(int idx, int i){
    i++;
    
    long long r = 0;
    while(i > 0){
        r = (r + tree[idx][i]) % MOD;
        i -= i & (-i);
    }
    return r;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        scanf("%d", &pi);
        pi--;
        
        G[pi].push_back(i);
    }
    
    cntime = 0;
    depth[0] = 0;
    dfs(0);
    
    scanf("%d", &q);
    while(q--){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d %d %d", &v, &x, &k);
            v--;
            
            add(0, L[v], x);
            add(0, R[v] + 1, -x);
            
            add(1, L[v], -k);
            add(1, R[v] + 1, k);
            
            add(0, L[v], 1LL * k * depth[v]);
            add(0, R[v] + 1, -1LL * k * depth[v]);
        }else{
            scanf("%d", &v);
            v--;
            
            printf("%I64d\n", (sum(0, L[v]) + sum(1, L[v]) * depth[v]) % MOD);
        }
    }
    return 0;
}