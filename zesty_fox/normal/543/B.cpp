#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=3010,INF=0x3f3f3f3f;
int n,m,head[N],tot,dis[N][N];
int s1,t1,l1,s2,t2,l2,ans=INF;
struct Edge{
    int to,nxt;
}e[N<<2];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

int q[N*N],hd,tl;
void bfs(int st){
    dis[st][st]=0;
    q[hd=tl=1]=st;
    while(hd<=tl){
        int x=q[hd];hd++;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(dis[st][y]==INF){
                dis[st][y]=dis[st][x]+1;
                q[++tl]=y;
            }
        }
    }
}

int main(){
    memset(dis,0x3f,sizeof(dis));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        addedge(x,y);addedge(y,x);
    }
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    for(int i=1;i<=n;i++) bfs(i);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==INF) continue;
            int tmp1[2]={dis[s1][i]+dis[i][j]+dis[j][t1],\
                dis[s1][j]+dis[j][i]+dis[i][t1]};
            int tmp2[2]={dis[s2][i]+dis[i][j]+dis[j][t2],\
                dis[s2][j]+dis[j][i]+dis[i][t2]};
            for(int k=0;k<2;k++){
                if(tmp1[k]>l1) continue;
                for(int l=0;l<2;l++){
                    if(tmp2[l]>l2) continue;
                    ans=min(ans,tmp1[k]+tmp2[l]-dis[i][j]);
                }
            }
        }
    }
    if(dis[s1][t1]<=l1&&dis[s2][t2]<=l2) ans=min(ans,dis[s1][t1]+dis[s2][t2]);
    cout<<max(m-ans,-1)<<endl;
    return 0;
}