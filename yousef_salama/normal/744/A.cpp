#include <bits/stdc++.h>
using namespace std;

int n, m, k, ui, vi, ci;
bool gov[1005];
vector <int> G[1005];

bool vis[1005];
pair <int, int> dfs(int i){
    vis[i] = true;
    
    pair <int, int> r = {1, gov[i]};
    for(int j : G[i]){
        if(vis[j])continue;
        
        pair <int, int> q = dfs(j);
        r = {r.first + q.first, r.second | q.second};
    }
    return r;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    
    for(int i = 0; i < k; i++){
        scanf("%d", &ci);
        ci--;
        
        gov[ci] = true;
    }
    
    for(int e = 0; e < m; e++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        G[ui].push_back(vi);
        G[vi].push_back(ui);
    }
    
    long long C = 0;
    vector <long long> Cs;
    
    for(int i = 0; i < n; i++)if(!vis[i]){
        pair <int, int> r = dfs(i);
        if(r.second == 0){
            C += r.first;
        }else{
            Cs.push_back(r.first);        
        }
    }
    
    sort(Cs.rbegin(), Cs.rend());
    long long m_ = (C + Cs.front()) * (C + Cs.front() - 1) / 2;
    for(int i = 1; i < Cs.size(); i++)
        m_ += Cs[i] * (Cs[i] - 1) / 2;
    printf("%I64d\n", m_ - m);
    
    return 0;
}