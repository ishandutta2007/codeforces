#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=1000010;
typedef long long ll;
ll n,head[N],tot,f[N],cnt[N],sum[N],leaf[N];
struct Edge{
    ll to,nxt;
}e[N<<1];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

void dfs(int x){
    int son=0;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        dfs(y);son++;
    }
    if(!son) leaf[x]=1;
    sum[x]=cnt[x];
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        sum[x]+=sum[y];
        son++;leaf[x]+=leaf[y];
        f[x]=max(f[x],f[y]);
    }
    f[x]=max(f[x],(sum[x]+leaf[x]-1)/leaf[x]);
}

signed main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int x;scanf("%d",&x);
        addedge(x,i+1);
    }
    for(int i=1;i<=n;i++) scanf("%lld",&cnt[i]);
    dfs(1);
    cout<<f[1]<<endl;
    return 0;
}