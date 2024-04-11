#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int MAXM = 1000005;

int n, m, ui, vi, X[MAXN], label[MAXM], labelX[MAXN];
vector <int> G[MAXN], GC[MAXM], C[MAXM];

int sz, r;
map <int, int> trie[MAXM];

void init(){
    r = 0;
    sz = 1;
}

void add(int i){
    int cur = r;
    for(int j = 0; j < G[i].size(); j++){
        if(trie[cur].count(G[i][j])){
            cur = trie[cur][G[i][j]];
        }else{
            trie[cur][G[i][j]] = sz++;
            cur = trie[cur][G[i][j]];
        }
    }
}
int search(int i){
    int cur = r;
    for(int j = 0; j < G[i].size(); j++){
        if(trie[cur].count(G[i][j])){
            cur = trie[cur][G[i][j]];
        }else return -1;
    }
    return cur;
}

bool vis[MAXM];
bool check(int i, int prev = -1){
    vis[i] = true;
    for(int j : GC[i]){
        if(j == prev)continue;
        if(vis[j])return false;
        
        check(j, i);
    }
    return true;
}
void set_label(int i, int &L, int prev = -1){
    vis[i] = true;
    label[i] = L;
    
    for(int j : GC[i]){
        if(j == prev)continue;
        set_label(j, ++L, i);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int e = 0; e < m; e++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
    
        G[ui].push_back(vi);
        G[vi].push_back(ui);
    }
    
    for(int i = 0; i < n; i++){
        G[i].push_back(i);
        
        sort(G[i].begin(), G[i].end());
        G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
        
        int k = search(i);
        if(k == -1){
            add(i);
            X[i] = sz - 1;
        }else X[i] = k;
    }
    
    for(int i = 0; i < n; i++){
        for(int j : G[i]){
            if(X[i] != X[j]){
                GC[X[i]].push_back(X[j]);
                GC[X[j]].push_back(X[i]);
            }
        }
        C[X[i]].push_back(i);
    }
    
    for(int i = 0; i < sz; i++){
        sort(GC[i].begin(), GC[i].end());
        GC[i].resize(unique(GC[i].begin(), GC[i].end()) - GC[i].begin());
    }
    
    bool ok = true;
    for(int i = 0; i < sz; i++)if(GC[i].size() >= 3)
        ok = false;
    
    for(int i = 0; i < sz; i++)if(GC[i].size() == 1){
        if(vis[i])continue;
        if(check(i))continue;
        
        ok = false;
    }
    
    for(int i = 0; i < sz; i++)if(!C[i].empty() && !vis[i]){
        if(GC[i].size() == 0)continue;
        ok = false;
    }
    if(ok){
        memset(vis, false, sizeof vis);
        
        int L = 1;
        for(int i = 0; i < sz; i++)if(GC[i].size() == 1){
            if(vis[i])continue;
            set_label(i, L);
            
            L++;
        }
        
        for(int i = 0; i < sz; i++)
            if(!C[i].empty() && (GC[i].size() == 0))set_label(i, L);
        
        for(int i = 0; i < sz; i++)
        for(int j : C[i])
            labelX[j] = label[i];
        
        printf("YES\n");
        for(int i = 0; i < n; i++){
            if(i > 0)printf(" ");
            printf("%d", labelX[i]);
        }
        printf("\n");
    }else printf("NO\n");
    
    return 0;
}