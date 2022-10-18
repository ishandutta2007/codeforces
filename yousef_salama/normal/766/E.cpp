#include <bits/stdc++.h>
using namespace std;

int n, a[100005], ui, vi;
vector <int> G[100005];

long long r = 0;
vector < pair <int, int> > dfs(int i, int par = -1){
     vector < pair <int, int> > v(31, {0, 0});
     for(int b = 0; b <= 30; b++){
         if(a[i] & (1 << b))v[b].second++;
         else v[b].first++;
     }
     
     r += a[i];
     for(auto j : G[i]){
         if(j == par)continue;
         
         vector < pair <int, int> > w = dfs(j, i);
         for(int b = 0; b <= 30; b++){
             r += (long long)v[b].first * w[b].second * (1LL << b);
             r += (long long)v[b].second * w[b].first * (1LL << b);
         
            if(a[i] & (1 << b)){
                v[b].first += w[b].second;
                v[b].second += w[b].first;
            }else{
                v[b].first += w[b].first;
                v[b].second += w[b].second;
            }
         }
     }

     return v;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    for(int e = 0; e < (n - 1); e++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        G[ui].push_back(vi);
        G[vi].push_back(ui);
    }
    
    dfs(0);
    printf("%I64d\n", r);
    
    return 0;
}