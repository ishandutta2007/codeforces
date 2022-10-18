#include <bits/stdc++.h>
using namespace std;
int r[200001];
int n;
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
void unite(int u, int v){
    u=root(u);
    v=root(v);
    if(u==v) return;
    if(r[u]>r[v]) swap(u, v);
    r[u]+=r[v];
    r[v]=u;
}
void solve(){
    cin>>n;
    for(int i=1; i<=n; i++) r[i]=-1;
    for(int i=1, a; i<=n; i++){
        cin>>a;
        unite(i, a);
    }
    for(int i=1; i<=n; i++) cout<<-r[root(i)]<<" \n"[i==n];
}
int main(){
    int q;
    cin>>q;
    while(q--) solve();
}