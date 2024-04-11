#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int r[200001];
map <int, vector <int>> M;
int odd=0;
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void unite(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return;
    if(r[u]%2) odd--;
    if(r[v]%2) odd--;
    if(r[u]>r[v]) swap(u, v);
    r[u]+=r[v];
    r[v]=u;
    if(r[u]%2) odd++;
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        M[a[i]].push_back(i);
    }
    int mx=*max_element(a+1, a+n+1);
    for(auto p: M){
        for(auto x: p.second){
            r[x]=-1;
            odd++;
            if((x>1)&&(a[x]>=a[x-1])) unite(x, x-1);
            if((x<n)&&(a[x]>a[x+1])) unite(x, x+1);
        }
        if(p.first==mx) break;
        if(odd){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}