#include<bits/stdc++.h>
using namespace std;

const int MAXN=300+5,INF=1e9,MAXM=15000+10;
bool visit[MAXN],inqueue[MAXN];
int head[MAXN],dist[MAXN],parent[MAXN],stamp,maxflow,mincost;
//parent indicates the index of the in-edge
int n,k;
queue<int> q;
struct EDGE{
   int to,r,cost,next;
}edge[MAXM*2];
int SPFA(int s,int t){
   for(int i=0;i<MAXN;i++)
      dist[i]=INF;
   memset(inqueue,0,sizeof inqueue);
   while(!q.empty()) q.pop();
   dist[s]=0;inqueue[s]=true;q.push(s);
   while(!q.empty()){
      int now=q.front();q.pop();inqueue[now]=false;
      for(int i=head[now];i!=-1;i=edge[i].next){
         if(edge[i].r>0){
            int next=edge[i].to;
            int cost=edge[i].cost;
            if(dist[next]>dist[now]+cost){
               parent[next]=i;
               dist[next]=dist[now]+cost;
               if(!inqueue[next]){
                  inqueue[next]=true;
                  q.push(next);
               }
            }
         }
      }
   }
   return dist[t];
}
void addedge(int a,int b,int r,int cost){
   edge[stamp]={b,r,cost,head[a]};
   head[a]=stamp++;
   edge[stamp]={a,0,-cost,head[b]};
   head[b]=stamp++;
}
void init(){
   stamp=maxflow=mincost=0;
   memset(head,-1,sizeof head);
}
void Minimum_Cost_Flow(int s,int t){
   while(SPFA(s,t)!=INF){
      int flow=INF,cost=0,tmpnode=t;
      while(tmpnode!=s){
         flow=min(flow,edge[parent[tmpnode]].r);
         cost+=edge[parent[tmpnode]].cost;
         tmpnode=edge[parent[tmpnode]^1].to;
      }
      if(mincost+(long long int)flow*cost>k){
         maxflow+=(k-mincost)/cost;
         return ;
      }
      maxflow+=flow;
      mincost+=flow*cost;
      tmpnode=t;
      while(tmpnode!=s){
         edge[parent[tmpnode]].r-=flow;
         edge[parent[tmpnode]^1].r+=flow;
         tmpnode=edge[parent[tmpnode]^1].to;
      }
   }

}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>k;
   int x;
   init();
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         cin>>x;
         if(i==j) continue;
         if(x>0){
            addedge(i,j,x,0);
            addedge(i,j,INF,1);
         }
      }
   }
   Minimum_Cost_Flow(1,n);
   cout<<maxflow<<endl;
}