//In the name of Allah

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n, nT, m, k, ai, bi;
vector <int> G[100005], bridgeless[100005], bridges[100005], T[100005];

int nlabel, label[100005], L[100005], H[100005], D[100005];
void dfs(int i, int par){
    label[i] = nlabel++;
    
    D[i] = 1, L[i] = label[i], H[i] = label[i];
    for(int j = 0; j < G[i].size(); j++){
        int u = G[i][j];
        
        if(u == par)continue;
        if(label[u] != -1){
            bridgeless[i].push_back(u);
            L[i] = min(L[i], label[u]);
            H[i] = max(H[i], label[u]);
            
            continue;
        }
        
        dfs(u, i);
        
        D[i] += D[u];
        L[i] = min(L[i], L[u]);
        H[i] = max(H[i], H[u]);
        
        if((L[u] == label[u]) && (H[u] < label[u] + D[u])){
            bridges[i].push_back(u);
            bridges[u].push_back(i);
            
            continue;
        }
        
        bridgeless[i].push_back(u);
        bridgeless[u].push_back(i);
    }
}

int C[100005];
vector <int> comps[100005];
void dfs2(int i, int c){
    C[i] = c;
    comps[c].push_back(i);
    
    for(int j = 0; j < bridgeless[i].size(); j++){
        int u = bridgeless[i][j];
        if(C[u] != -1)continue;
        
        dfs2(u, c);
    }
}

int rroot[100005], root_sum[100005], p[20][100005], depth[100005];
void dfs_tree(int i, int par, int root){
    rroot[i] = root;
    p[0][i] = par;
    
    root_sum[i] += comps[i].size() > 1;
    for(int j = 0; j < T[i].size(); j++){
        int u = T[i][j];
        if(u == par)continue;
        
        depth[u] = depth[i] + 1;
        
        root_sum[u] += root_sum[i];
        dfs_tree(u, i, root);
    }
}

int lca(int i, int j){
    while(depth[i] < depth[j]){
        for(int d = 19; d >= 0; d--)
            if((p[d][j] != -1) && (depth[p[d][j]] >= depth[i]))j = p[d][j];
    }
    while(depth[j] < depth[i]){
        for(int d = 19; d >= 0; d--)
            if((p[d][i] != -1) && (depth[p[d][i]] >= depth[j]))i = p[d][i];
    }
    
    if(i == j)return i;
    
    for(int d = 19; d >= 0; d--){
        if((p[d][i] != -1) && (p[d][i] != p[d][j])){
            i = p[d][i];
            j = p[d][j];
        }
    }
    return p[0][i];
}

int dist_2(int i, int j){
    if(rroot[i] != rroot[j])return -1;
    
    int l = lca(i, j);
    
    int r = root_sum[i] + root_sum[j] - (comps[l].size() > 1);
    if(p[0][l] != -1)r -= 2 * root_sum[p[0][l]];
    
    return r;
}

int nC, pow2[100005];
int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        G[ai].push_back(bi);
        G[bi].push_back(ai);
    }
    
    memset(label, -1, sizeof label);
    for(int i = 0; i < n; i++)if(label[i] == -1)
        dfs(i, -1);
    
    memset(C, -1, sizeof C);
    for(int i = 0; i < n; i++)if(C[i] == -1)
        dfs2(i, nC++);
        
    /*for(int i = 0; i < n; i++){
        cout << (i + 1) << ':';
        for(int j = 0; j < bridgeless[i].size(); j++)
            cout << (bridgeless[i][j] + 1) << ' ';
        cout << endl;
    }*/
    
    for(int i = 0; i < nC; i++){
        for(int j = 0; j < comps[i].size(); j++){
            int u = comps[i][j];
            for(int l = 0; l < bridges[u].size(); l++){
                int v = bridges[u][l];
                T[i].push_back(C[v]);
            }
        }
        
        /*cout << i << ',' << comps[i].size() << ':';
        for(int j = 0; j < T[i].size(); j++)
            cout << T[i][j] << ' ';
        cout << endl;*/
    }
    
    memset(rroot, -1, sizeof rroot);
    for(int i = 0; i < nC; i++)if(rroot[i] == -1){
        depth[i] = 0;
        dfs_tree(i, -1, i);
    }
    
    for(int j = 1; j < 20; j++)
    for(int i = 0; i < nC; i++){
        if(p[j - 1][i] == -1)p[j][i] = -1;
        else p[j][i] = p[j - 1][p[j - 1][i]];
    }
    
    pow2[0] = 1;
    for(int i = 1; i <= n; i++)
        pow2[i] = (2 * pow2[i - 1]) % MOD;
    
    
    scanf("%d", &k);
    while(k--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        int r = dist_2(C[ai], C[bi]);
        if(r == -1)printf("0\n");
        else printf("%d\n", pow2[r]);
    }
    
    return 0;
}