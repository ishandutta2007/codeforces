#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

char s[MAXN], x[MAXN];
int N;

int sz, root, sink, G[2 * MAXN][26], suflink[2 * MAXN], depth[2 * MAXN],
                    dp[2 * MAXN], term[2 * MAXN], vis[2 * MAXN];

int new_node(int d){
    memset(G[sz], -1, sizeof G[sz]);
    depth[sz] = d;
    suflink[sz] = -1;
    return sz++;
}

void insert(int c){
    int p = new_node(depth[sink] + 1), cur = sink;
    while((cur != -1) && (G[cur][c] == -1)){
        G[cur][c] = p;
        cur = suflink[cur];
    }
    
    if(cur == -1){
        suflink[p] = root;
    }else{
        int q = G[cur][c];
        if(depth[q] == depth[cur] + 1){
            suflink[p] = q;
        }else{
            int r = new_node(depth[cur] + 1);
            memcpy(G[r], G[q], sizeof(G[r]));
            
            suflink[r] = suflink[q];
            suflink[q] = r;
            suflink[p] = r;
            
            
            while((cur != -1) && (G[cur][c] == q)){
                G[cur][c] = r;
                cur = suflink[cur];
            }
        }
    }
    sink = p;
}
int dfs(int cur){
    if(dp[cur] != -1)return dp[cur];
    
    int r = term[cur];
    for(int c = 0; c < 26; c++)
        if(G[cur][c] != -1)r += dfs(G[cur][c]);
    return dp[cur] = r;
}

int main(){
    scanf("%s", s);
    
    sink = root = new_node(0);
    for(int i = 0; s[i]; i++)
        insert(s[i] - 'a');
        
    int cur = sink;
    while(cur != -1){
        term[cur] = 1;
        cur = suflink[cur];
    }
        
    memset(dp, -1, sizeof dp);
    memset(vis, -1, sizeof vis);    
    
    scanf("%d", &N);
    for(int j = 0; j < N; j++){
        scanf("%s", x);
        int M = strlen(x);
        
        int cur = root, L = 0;
        long long r = 0;
        for(int i = 0; i < 2 * M - 1; i++){
            if(G[cur][x[i % M] - 'a'] == -1){
                while((cur != -1) && (G[cur][x[i % M] - 'a'] == -1))
                    cur = suflink[cur];
                
                if(cur == -1)cur = root, L = 0;
                else{ 
                    L = depth[cur];
                    cur = G[cur][x[i % M] - 'a'];
                    
                    L++;
                }
            }else{
                cur = G[cur][x[i % M] - 'a'];
                L++;
            }
            
            while((suflink[cur] != -1) && (depth[suflink[cur]] >= M)){
                cur = suflink[cur];
                L = depth[cur];
            }
            if((L >= M) && (vis[cur] != j)){
                r += dfs(cur);
                vis[cur] = j;
            }
        }
        printf("%I64d\n", r);
    }
    return 0;
}