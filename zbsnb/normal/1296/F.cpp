#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

struct nod{
    int u,v,nxt;
}e[100010];
int head[100010],cnt;
void add(int u,int v){
    e[++cnt]={u,v,head[u]};
    head[u]=cnt;
}

int ans[100010];
int dfs(int u,int fa,int aim,int val){
    // cout<<u<<" "<<aim<<endl;
    if(u==aim){
        // cout<<u<<endl;
        return 1;
    }
    int ret=0;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)continue;
        if(dfs(v,u,aim,val)){
            // cout<<"now:"<<i<<endl;
            ans[i/2]=max(ans[i/2],val);
            ret=1;
        }
    }
    return ret;
}

int dfs2(int u,int fa,int aim){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa)continue;
        if(v==aim){
            return ans[i/2];
        }
        int tmp=dfs2(v,u,aim);
        if(tmp!=-1){
            return min(ans[i/2],tmp); 
        }
    }
    return -1;
}

int a[5010];
int b[5010];
int c[5010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    cnt=1;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<n;i++)ans[i]=1;
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        cin>>a[i]>>b[i]>>c[i];
        dfs(a[i],0,b[i],c[i]);
    }

    // for(int i=1;i<n;i++)cout<<ans[i]<<" ";cout<<endl;

    int flg=0;
    for(int i=1;i<=q;i++){
        int tmp=dfs2(a[i],0,b[i]);
        // cout<<i<<" "<<tmp<<endl;
        if(tmp!=c[i]){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1;i<n;i++)cout<<ans[i]<<" ";cout<<endl;
}