#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
struct nod{
    int u,v,nxt;
}e[600010];
int head[300010],cnt;
void add(int u,int v){
    e[++cnt]={u,v,head[u]};
    head[u]=cnt;
}
int dp[300010],w[300010];
int ans=0;
int dfs(int u,int fa){
    int ret=w[u];
    multiset<int,greater<int> > s;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(fa==v)continue;
        s.insert(dfs(v,u));
    }
    if(!s.empty()){
        auto it=s.begin();
        ret+=*it;s.erase(it);   
    }
    ans=max(ans,ret+(s.empty()?0:*s.begin()));
    //cout<<u<<" "<<ret<<endl;
    return ret;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cnt=0;ans=0;
        for(int i=1;i<=n;i++)head[i]=0,w[i]=-1;
        for(int i=1;i<n;i++){
            int a,b;cin>>a>>b;
            add(a,b);add(b,a);
            w[a]++,w[b]++;
        }
        dfs(1,0);
        cout<<ans+2<<endl;
    }
}