#include<bits/stdc++.h>
using namespace std;
vector<int> e[1000010];
int cnt;
int col[1000010];
int vis[1000010];
void dfs(int u){
    if(vis[u]) return;
    vis[u]=1;
    cnt++;

    int flg=0;
    for(auto &v:e[u]){
        if(col[v]) flg=1;
    }
    if(flg==0) col[u]=1;

    for(auto &v:e[u]){
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        cnt=0;
        int n,m;cin>>n>>m;
        for(int i=1;i<=n;i++) e[i].clear(),col[i]=vis[i]=0;
        for(int i=1;i<=m;i++){
            int a,b;cin>>a>>b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        dfs(1);
        if(cnt==n){
            cout<<"YES"<<"\n";
            vector<int> ans;
            for(int i=1;i<=n;i++){
                if(col[i]) ans.push_back(i);
            }
            cout<<ans.size()<<"\n";
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" \n"[i+1==ans.size()];
            }
        }
        else cout<<"NO"<<"\n";
    }
}