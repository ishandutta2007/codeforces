#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define int ll

int nxt[200010];
int pre[200010];
int vis[200010];
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
signed main(){
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)pre[i]=i,nxt[i]=i;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        pre[find(a)]=find(b);
        if(a>b)swap(a,b);
        nxt[a]=max(nxt[a],b);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++){
        vis[find(i)]=1;
        //cout<<i<<" "<<pre[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        ans+=vis[i];
    }
    //cout<<ans<<endl;
    int now=0;
    for(int i=1;i<=n;i++){
        now=max(now,nxt[i]);
        if(now==i){
            ans--;
        }
    }
    cout<<ans<<endl;
}