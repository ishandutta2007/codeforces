#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int x[2010],y[2010];
struct nod{
    int u,v;
    ll w;
    bool operator<(const nod &x) const {
        return w<x.w;
    }
}e[3000010];
int pre[2010],c[2010],k[2010];
pair<int,int> q[2010];
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cin>>k[i];
    int m=0;
    for(int i=1;i<=n;i++){
        e[++m]={i,0,c[i]};
        for(int j=i+1;j<=n;j++){
          e[++m]={i,j,1ll*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j])};  
        }
    }
    sort(e+1,e+m+1);

    ll ans=0;int p=0;
    for(int i=1;i<=n;i++)pre[i]=i;
    for(int i=1;i<=m;i++){
        int fx=find(e[i].u);
        int fy=find(e[i].v);
        if(fx==fy)continue;
        else {
            if(fx==0||fy==0)
                pre[fx]=pre[fy]=0;
            else pre[fx]=fy;
            ans+=e[i].w,q[++p]={e[i].u,e[i].v};
        }
    }

    cout<<ans<<endl;
    int cnt=0;
    for(int i=1;i<=n;i++)if(q[i].first==0||q[i].second==0)cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)if(q[i].first==0||q[i].second==0)cout<<(q[i].first?q[i].first:q[i].second)<<" ";cout<<endl;
    cout<<n-cnt<<endl;
    for(int i=1;i<=n;i++)if(q[i].first!=0&&q[i].second!=0)cout<<q[i].first<<" "<<q[i].second<<endl;
}