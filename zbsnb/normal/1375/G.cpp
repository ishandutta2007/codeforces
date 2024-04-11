#include<bits/stdc++.h>
using namespace std;
vector<int> e[1000010];
int col[1000010];
void dfs(int u,int c){
    if(col[u])return;
    col[u]=c;
    for(auto &v:e[u]){
        dfs(v,3-c);
    }
}
int main(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1,1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(col[i]==1)cnt++;
    }
    cout<<(min(cnt,n-cnt)-1)<<endl;
}