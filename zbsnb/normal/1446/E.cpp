#include<bits/stdc++.h>
using namespace std;
 
inline int id(int x,int y) { return x*510+y; }
vector<int> e[300010];
int col[300010];
int vis[300010];
int dfs(int u,int fa){
    if(vis[u]) return 1;
    vis[u]=1;
    int ret=0;
    for(auto &v:e[u]){
        if(v==fa||col[v]==0) continue;
        if(dfs(v,u)) ret=1;
    }
    return ret;
}

int dfs_fuck(int u,int fa){
    int ret=1;
    for(auto &v:e[u]){
        if(v==fa||col[v]==0) continue;
        ret+=dfs_fuck(v,u);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
 
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;x+=3,y+=3;
        col[id(x,y)]=1;
    }
 
    for(int i=1;i<=300000;i++){
        int x=i/510,y=i%510;
        int now=id(x,y);
        int nb1=id(x+1,y);
        int nb2=id(x-1,y);
        int nb3=(x&1)?id(x+1,y-1):id(x-1,y+1);
        if(nb1>=1&&nb1<=300000) e[now].push_back(nb1);
        if(nb2>=1&&nb2<=300000) e[now].push_back(nb2);
        if(nb3>=1&&nb3<=300000) e[now].push_back(nb3);
    }
 
    vector<int> fuck;

    int ans=0;
    for(int i=1;i<=300000;i++){
        int cnt=0;
        for(auto &v:e[i]){
            if(col[i]^col[v]) ans++,cnt++;
        }
        if(col[i]==0&&cnt==3) fuck.push_back(i); 
    }    
    ans/=2;

    for(int i=1;i<=300000;i++) vis[i]=0;

    queue<int> q;
    for(int i=1;i<=300000;i++){
        if(col[i]) continue;
        for(auto &v:e[i]){
            if(col[v]) vis[i]++;
        }
        if(vis[i]>=2) q.push(i);
    }
 
    while(!q.empty()){
        int u=q.front(); q.pop(); 
        if(col[u]) continue;
        col[u]=1;
        for(auto &v:e[u]){
            if(col[v]) continue;
            else{
                vis[v]++;
                if(vis[v]>=2) q.push(v);
            }
        }
    }
 
    for(int i=1;i<=300000;i++) vis[i]=0;
    for(int i=1;i<=300000;i++){
        if(vis[i]||col[i]==0) continue;
        else if(dfs(i,0)){
            cout<<"SICK"<<endl;
            return 0;
        }
        else ans-=2;
    }

    for(int i=1;i<=300000;i++) vis[i]=0;
    for(auto &it:fuck){
        // cout<<dfs_fuck(it,0)<<endl;
        if(dfs_fuck(it,0)==4){
            ans-=2;
        }
    }
 
    cout<<"RECOVERED"<<endl;
    cout<<ans<<endl;
 
}