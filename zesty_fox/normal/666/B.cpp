#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=3010,INF=0x3f3f3f3f;
int n,m,dis1[N][N],dis2[N][N],far1[N][4],far2[N][4];
struct Edge{int to,nxt;};
queue<int> q;
struct Graph{
    Edge e[N<<2];int head[N],tot;
    Graph(){
        tot=0;memset(head,0,sizeof(head));
    }
    void addedge(int x,int y){
        e[++tot]=(Edge){y,head[x]};
        head[x]=tot;
    }
    void bfs(int s,int dis[N][N],int far[N][4]){
        while(!q.empty()) q.pop();
        q.push(s);dis[s][s]=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int i=head[x];i;i=e[i].nxt){
                int y=e[i].to;
                if(dis[s][y]!=INF) continue;
                dis[s][y]=dis[s][x]+1;
                q.push(y);
            }
        }
        int p1=0,p2=0,p3=0,d1=0,d2=0,d3=0;
        for(int i=1;i<=n;i++){
            if(dis[s][i]==INF||i==s) continue;
            if(dis[s][i]>d1){
                d3=d2,d2=d1,d1=dis[s][i],p3=p2,p2=p1,p1=i;
            }
            else if(dis[s][i]>d2){
                d3=d2,d2=dis[s][i],p3=p2,p2=i;
            }
            else if(dis[s][i]>d3){
                d3=dis[s][i],p3=i;
            }
        }
        if(p1) far[s][1]=p1;
        if(p2) far[s][2]=p2;
        if(p3) far[s][3]=p3;
    }
}g,_g;
ll maxn;int p1,p2,p3,p4;
int main(){
    memset(dis1,0x3f,sizeof(dis1));
    memset(dis2,0x3f,sizeof(dis2));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        g.addedge(x,y);_g.addedge(y,x);
    }
    for(int i=1;i<=n;i++) g.bfs(i,dis1,far1),_g.bfs(i,dis2,far2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j||dis1[i][j]==INF) continue;
            for(int k=1;k<=3;k++){
                for(int l=1;l<=3;l++){
                    if(!far2[i][k]||!far1[j][l]) continue;
                    if(far2[i][k]==far1[j][l]||far2[i][k]==j||\
                       far1[j][l]==i) continue;
                    ll sum=dis1[i][j]+dis2[i][far2[i][k]]+dis1[j][far1[j][l]];
                    if(sum>maxn){
                        maxn=sum,p1=far2[i][k],p2=i,p3=j,p4=far1[j][l];
                    }
                }
            }
        }
    }
    printf("%d %d %d %d\n",p1,p2,p3,p4);
    return 0;
}