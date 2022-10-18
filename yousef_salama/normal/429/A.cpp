#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, ui, vi, a[MAXN], b;
vector <int> G[MAXN];

vector <int> v;
void solve(int i, int p = -1, int f0 = 0, int f1 = 0){
    if(a[i] ^ f0 != 0){
        f0 ^= 1;
        v.push_back(i + 1);
    }
    
    for(int u : G[i]){
        if(u == p)continue;
        solve(u, i, f1, f0);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        G[ui].push_back(vi);
        G[vi].push_back(ui);
    }
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    for(int i = 0; i < n; i++){
        scanf("%d", &b);
        a[i] ^= b;
    }
    
    solve(0);
    
    printf("%d\n", v.size());
    for(int u : v)
        printf("%d\n", u);
    
    return 0;
}