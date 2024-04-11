#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
struct nod{
    int u,v,w,nxt;
}e[1000010];
int head[500010],cnt;
void add(int u,int v,int w){
    e[++cnt]={u,v,w,head[u]};
    head[u]=cnt;
}
int n,k;
ll sum[500010],a[500010];
void dfs(int u,int fa){
    ll tmp=0;
    multiset<int,greater<int> > s;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)continue;
        dfs(v,u);
        tmp+=sum[v];
        s.insert(e[i].w-a[v]);
    }

    //cout<<u<<" "<<tmp<<endl;

    int i=1;
    a[u]=0;
    for(auto it=s.begin();it!=s.end()&&i<=k;it++,i++){
        if(*it>0)tmp+=*it;
        else break;
        //cout<<*it<<endl;
        if(i==k) a[u]=*it;
    }
    sum[u]=tmp;
    //cout<<u<<" "<<a[u]<<" "<<tmp<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        cin>>n>>k;
        cnt=0;
        for(int i=1;i<=n;i++){
            head[i]=0;
        }
        for(int i=1;i<n;i++){
            int u,v,w;cin>>u>>v>>w;
            add(u,v,w);add(v,u,w);
        }
        dfs(1,0);
        cout<<sum[1]<<endl;
    }
}