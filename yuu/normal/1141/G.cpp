#include <bits/stdc++.h>
using namespace std;
vector <pair <int, int>> g[200001];
int ans[200001];
int n, k, r;
bool done[200001];
void dfs(int u, int c=-1){
    done[u]=1;
    if(g[u].size()>r){
        for(auto v: g[u]) if(!done[v.first]) dfs(v.first, 1); else ans[v.second]=c; 
    }
    else{
        int nc=1;
        for(auto v: g[u]) if(!done[v.first]){
            if(nc==c) nc++;
            dfs(v.first, nc);
            nc++;
        }
        else ans[v.second]=c;
    }
}
int main(){
    cin>>n>>k;
    for(int i=1, u, v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(make_pair(v, i));
        g[v].push_back(make_pair(u, i));
    }
    {
        int low=1, high=n, mid;
        while(low<=high){
            mid=(low+high)/2;
            int cnt=0;
            for(int i=1; i<=n; i++) cnt+=g[i].size()>mid;
            if(cnt<=k){
                r=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
    }
    dfs(1);
    cout<<r<<'\n';
    for(int i=1; i<n; i++) cout<<ans[i]<<" \n"[i+1==n];
}