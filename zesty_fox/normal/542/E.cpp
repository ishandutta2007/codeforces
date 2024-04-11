#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int N=1010,M=100010,INF=0x3f3f3f3f;
int n,m,ans,head[N],tot;
struct Edge{int to,nxt;}e[M<<1];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

vector<int> v;
queue<int> q;
int dis[N][N],vis[N];
void bfs(int st){
    memset(dis[st],0x3f,sizeof(dis[st]));
    dis[st][st]=0;q.push(st);
    while(!q.empty()){
        int x=q.front();q.pop();
        vis[x]=1;v.push_back(x);
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[st][y]==INF){
                dis[st][y]=dis[st][x]+1;
                q.push(y);
            }
        }
    }
}

int col[N];
bool dfs(int x,int color){
    col[x]=color;vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(vis[y]){
            if(col[y]==color) return false;
        }
        else if(!dfs(y,color^1)) return false;
    }
    return true;
}

bool check(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(!dfs(i,0)) return false;
        }
    }
    return true;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        addedge(x,y);addedge(y,x);
    }
    if(!check()){
        puts("-1");
        return 0;
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            v.clear();bfs(i);
            vector<int> tmp=v;
            int siz=tmp.size(),maxn=0;
            for(auto j:tmp) bfs(j);
            for(int j=0;j<siz;j++){
                for(int k=j;k<siz;k++) maxn=max(maxn,dis[tmp[j]][tmp[k]]);
            }
            ans+=maxn;
        }
    }
    cout<<ans<<endl;
    return 0;
}