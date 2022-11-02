
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int> > e[1000010];
struct node{
    int u;
    int f1;
    int f2;
    ll val;
    bool operator<(const node &x) const {
        return val>x.val;
    }
};
ll ans[1000010][2][2];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }
    priority_queue<node> q;
    q.push({1,0,0,0});
    for(int i=1;i<=n;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
                ans[i][j][k]=1e18;
    while(!q.empty()){
        auto tmp=q.top();q.pop();
        int u=tmp.u;ll val=tmp.val;
        int f1=tmp.f1,f2=tmp.f2;
        // cout<<u<<" "<<f1<<" "<<f2<<" "<<val<<endl;
        if(ans[u][f1][f2]<=val) continue;
        ans[u][f1][f2]=val;
        for(auto &it:e[u])
            for(int j=f1;j<=1;j++)
                for(int k=f2;k<=1;k++){
                    int v=it.first,w=it.second;
                    node tmp={v,j,k,val+w};
                    if(f1==0&&j==1) tmp.val-=w;
                    if(f2==0&&k==1) tmp.val+=w;
                    q.push(tmp);
                }
    }
    for(int i=2;i<=n;i++) cout<<ans[i][1][1]<<" ";
    cout<<endl;
}