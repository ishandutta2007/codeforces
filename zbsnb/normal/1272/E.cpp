#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
#define int long long

struct nod{
    int u,v,nxt;
}e[800010];
int head[200010],cnt;
void add(int u,int v){
    e[++cnt]={u,v,head[u]};
    head[u]=cnt;
}
int ans[200010];
int a[200010];
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(i-a[i]>=1){
            add(i-a[i],i);
            // add(i,i-a[i]);
        }
        if(i+a[i]<=n){
            add(i+a[i],i);
            // add(i,i+a[i]);
        }
    }

    for(int i=1;i<=n;i++)ans[i]=-1;
    queue<pair<int,pair<int,int> > > q;
    for(int i=1;i<=n;i++){
        if(i-a[i]>=1&&(a[i]+a[i-a[i]])%2==1){
            q.push({i,{1,i-a[i]}});
            // cout<<i<<i-a[i]<<endl;
        }
        if(i+a[i]<=n&&(a[i]+a[i+a[i]])%2==1){
            q.push({i,{1,i+a[i]}});
            // cout<<i<<i+a[i]<<endl;
        }
    }
    while(!q.empty()){
        auto v=q.front();q.pop();
        int u=v.first,d=v.second.first,fa=v.second.second;
        // cout<<"now"<<u<<" "<<d<<" "<<fa<<endl;
        if(ans[u]!=-1)continue;
        ans[u]=d;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(fa==v)continue;
            q.push({v,{d+1,u}});
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}