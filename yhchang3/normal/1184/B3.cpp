#include<bits/stdc++.h>
using namespace std;

const int MAXN=3000+5,MAXM=10000+10;
const long long int INF = 1e15;
bool visit[MAXN];
int head[MAXN],dist[MAXN],stamp,tmphead[MAXN];
struct EDGE{
   int to;
   long long int r;
   int next;
}edge[MAXM*2];
void init(){
   stamp=0;
   memset(head,-1,sizeof head);
}
void addedge(int a,int b,long long int c){
   edge[stamp]={b,c,head[a]};
   head[a]=stamp++;
   edge[stamp]={a,0,head[b]};
   head[b]=stamp++;
}
int BFS(int s,int t){
   for(int i=0;i<=t;i++)//The nodes being used
      dist[i]=1e9;
   memset(visit,0,sizeof visit);
   queue<int> q;
   q.push(s);dist[s]=0;visit[s]=true;
   while(!q.empty()){
      int now=q.front();q.pop();
      for(int i=head[now];i!=-1;i=edge[i].next){
         int nextnode=edge[i].to;
         if(edge[i].r>0&&!visit[nextnode]){
            dist[nextnode]=dist[now]+1;
            visit[nextnode]=true;
            q.push(nextnode);
            if(nextnode==t)   return dist[t];
         }
      }
   }
   return -1;
}
long long int DFS(int now,long long int df,int t){
   if(now==t)  return df;
   visit[now]=true;
   for(int i=tmphead[now];i!=-1;tmphead[now]=i=edge[i].next){
      int nextnode=edge[i].to;
      if(edge[i].r>0&&dist[now]+1==dist[nextnode]&&!visit[nextnode]){
         long long int f=DFS(nextnode,min(df,edge[i].r),t);
         if(f){
            edge[i].r-=f;
            edge[i^1].r+=f;
            return f;
         }
      }
   }
   return 0;
}
long long int Dinic(int s,int t){
   long long int flow=0;
   while(BFS(s,t)!=-1){
      memcpy(tmphead,head,sizeof head);
      while(true){
         memset(visit,0,sizeof visit);
         long long int f=DFS(s,INF,t);
         if(!f)   break;
         flow+=f;
      }
   }
   return flow;
}

int dp[101][101];
struct SP{
	int x,a,f,p,pro,idx;
	bool operator<(const SP& rhs)const{
		return a<rhs.a;
	}
}sp[100001];

struct BA{
	int x,d,g;
	bool operator<(const BA& rhs)const{
		return d<rhs.d;
	}
}ba[100001];
int cur[101];
int s1[1001],s2[1001];
map<int,int> mp;
set<int> st;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	init();
	for(int i=1;i<=100;i++)
		cur[i]=-1e9-1;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
			dp[i][j]=1e9+1;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		dp[u][v]=dp[v][u]=1;
	}
	for(int i=1;i<=100;i++)
		dp[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	int s,b,k;
	cin>>s>>b>>k;
	for(int i=1;i<=s;i++){
		cin>>sp[i].x>>sp[i].a>>sp[i].f>>sp[i].p;
		sp[i].pro=-1e9-1;
		sp[i].idx=i;
	}
	sort(sp+1,sp+s+1);
	for(int i=1;i<=b;i++){
		cin>>ba[i].x>>ba[i].d>>ba[i].g;
	}
	sort(ba+1,ba+b+1);
	int pb=1;
	for(int i=1;i<=s;i++){
		while(pb<=b&&ba[pb].d<=sp[i].a)
			cur[ba[pb].x]=max(cur[ba[pb].x],ba[pb].g),pb++;
		for(int j=1;j<=n;j++)
			if(dp[j][sp[i].x]<=sp[i].f)
				sp[i].pro=max(sp[i].pro,cur[j]);
	}
	for(int i=1;i<=k;i++){
		cin>>s1[i]>>s2[i];
		st.insert(s1[i]);st.insert(s2[i]);
	}
	int stp=0;
	for(int it:st)
		mp[it]=++stp;
	long long int ans=0;
	for(int i=1;i<=s;i++){
		sp[i].pro-=sp[i].p;
		if(sp[i].pro>=0)	ans+=sp[i].pro;
		if(mp.find(sp[i].idx)!=mp.end()){
			if(sp[i].pro>0)
				addedge(stp+1,mp[sp[i].idx],sp[i].pro);
			else if(sp[i].pro<0)
					addedge(mp[sp[i].idx],stp+2,(sp[i].pro<-1e9?INF:-sp[i].pro));
		}
	}
	for(int i=1;i<=k;i++)
		addedge(mp[s1[i]],mp[s2[i]],INF);
	cout<<ans-Dinic(stp+1,stp+2)<<endl;
}