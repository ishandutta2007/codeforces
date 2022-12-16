#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N=300010;
struct Edge{
    int to,nxt;
}e[N<<1];
int head[N],tot,n,m,q,f[N],len[N];
int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return;
    f[y]=x;len[x]=max((len[x]+1)/2+1+(len[y]+1)/2,max(len[y],len[x]));
}

void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

int dis[N],vis[N];
vector<int> v;
void dfs(int x,int fa){
    vis[x]=1;v.push_back(x);
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dis[y]=dis[x]+1;
        dfs(y,x);
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        addedge(x,y);addedge(y,x);
    }
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            v.clear();dis[i]=0;dfs(i,0);
            int p,maxn=-1;
            for(auto j:v){
                merge(i,j);
                if(dis[j]>maxn) maxn=dis[j],p=j;
            }
            dis[p]=0;dfs(p,0);maxn=-1;
            for(auto j:v) maxn=max(maxn,dis[j]);
            len[i]=maxn;
        }
    }
    while(q--){
        int op,x,y;scanf("%d",&op);
        if(op==1){
            scanf("%d",&x);
            printf("%d\n",len[find(x)]);
        }
        else{
            scanf("%d%d",&x,&y);
            merge(x,y);
        }
    }
    return 0;
}