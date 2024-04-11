#include<iostream>
using namespace std;
#define ll long long

struct nod{
    int u,v,nxt;
}e[200010];
int head[100010],cnt;
void add(int u,int v){
    e[++cnt]={u,v,head[u]};
    head[u]=cnt;
}

ll cost[100010][3];
int sz[100010];
int tag[6][100010];
ll dfs(int u,int fa,int col,int fcl,int t){

    //cout<<u<<" "<<col<<" "<<fcl<<endl;

    tag[t][u]=col;
    ll ret=cost[u][col];
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)continue;
        ret+=dfs(v,u,3-col-fcl,col,t);
    }
    return ret;
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>cost[i][0];
    for(int i=1;i<=n;i++)cin>>cost[i][1];
    for(int i=1;i<=n;i++)cin>>cost[i][2];
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        add(a,b);add(b,a);
        sz[a]++,sz[b]++;
    }
    int rt=0;
    for(int i=1;i<=n;i++){
        if(sz[i]>=3){
            cout<<-1<<endl;
            return 0;
        }
        if(sz[i]==1)rt=i;
    }

    //cout<<rt<<endl;

    ll tmp1=dfs(rt,0,0,1,1);
    ll tmp2=dfs(rt,0,1,0,2);
    ll tmp3=dfs(rt,0,0,2,3);
    ll tmp4=dfs(rt,0,2,0,4);
    ll tmp5=dfs(rt,0,1,2,5);

    //cout<<tmp1<<tmp2<<tmp3<<tmp4<<tmp5<<endl;

    ll ans=dfs(rt,0,2,1,0),tt=0;
    if(ans>tmp1)ans=tmp1,tt=1;
    if(ans>tmp2)ans=tmp2,tt=2;
    if(ans>tmp3)ans=tmp3,tt=3;
    if(ans>tmp4)ans=tmp4,tt=4;
    if(ans>tmp5)ans=tmp5,tt=5;

    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        cout<<tag[tt][i]+1<<" ";
    }cout<<endl;

}