#include<bits/stdc++.h>
using namespace std;
const int N = 200,INF = 1e9, K = 7;
int p[1<<K][N],pp[N];
bool g[100][100];
int w[N][N],v[N],dp[1<<K][N],off[N];//init:w[i][j]=(i==j?0:INF),v[i]=0
void init(int n){//INF=1e9
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)  w[i][j]=INF;w[i][i]=v[i]=0;}
}
void addedge(int x,int y,int d){w[x][y]=w[y][x]=min(w[x][y],d);}
int solve(int n,vector<int> chosen){//put the weight of vertex onto edge
	for(int i=0;i<n;i++)  for(int j=0;j<n;j++)
		w[i][j]+=(i==j?v[i]:(v[i]+v[j]));
	for(int k=0;k<n;k++)  for(int i=0;i<n;i++)  for(int j=0;j<n;j++)
		w[i][j]=min(w[i][j],w[i][k]+w[k][j]-v[k]);
	int k=chosen.size();
	for(int i=0;i<(1<<k);i++)  for(int j=0;j<n;j++)   dp[i][j]=INF;
	for(int i=0;i<n;i++){
		dp[0][i]=0;for(int j=0;j<k;j++)  dp[1<<j][i]=w[chosen[j]][i],p[1<<j][i]=-INF;}
	for(int s=1;s<(1<<k);s++){
		if(!(s&(s-1)))	continue;
		for(int i=0;i<n;i++)  for(int sub=s&(s-1);sub;sub=s&(sub-1)){
			int z=dp[sub][i]+dp[s^sub][i]-v[i];
			if(dp[s][i]>z){
				dp[s][i]=z;
				p[s][i]=-sub;
			}
		}
		for(int i=0;i<n;i++){
			off[i]=INF;
			for(int j=0;j<n;j++){
				int z=dp[s][j]+w[j][i]-v[j];
				if(z<off[i]){
					off[i]=z;
					pp[i]=j;
				}
			}
		}
		for(int i=0;i<n;i++)
			if(dp[s][i]>off[i])
				dp[s][i]=off[i],p[s][i]=pp[i];
	}
	return min_element(dp[(1<<k)-1],dp[(1<<k)-1]+n)-dp[(1<<k)-1];
}
int n,m,k;
vector<pair<int,int> > D;
vector<int> P;
void dfs(int s,int i){
	g[i/m][i%m]=true;
	if(p[s][i]==-INF){
		D.emplace_back(i,P[__builtin_ctz(s)]);
		return;
	}
	if(p[s][i]<0){
		int z=-p[s][i];
		dfs(z,i);dfs(z^s,i);
	}
	else{
		int z=p[s][i];
		D.emplace_back(i,z);
		dfs(s,p[s][i]);
	}
}
int pre[N],dist[N],vis[N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	init(n*m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>v[i*m+j];
			int u=(i-1)*m+j,l=i*m+j-1;
			if(i!=0)	addedge(i*m+j,u,0);
			if(j!=0)	addedge(i*m+j,l,0);
		}
	for(int i=0,x,y;i<k;i++){
		cin>>x>>y;
		x--;y--;
		P.emplace_back(x*m+y);
		g[x][y]=true;
	}
	int idx=solve(n*m,P);
	dfs((1<<k)-1,idx);
	vector<int> st[200];
	for(auto it:D)
		st[it.first].emplace_back(it.second);
	for(int u=0;u<n*m;u++){
		pre[u]=-1;
		for(int j=0;j<n*m;j++)
			dist[j]=INF,vis[j]=0;
		dist[u]=v[u];
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > pq;
		pq.emplace(dist[u],u);
		while(!pq.empty()){
			int x=pq.top().second;pq.pop();
			if(vis[x])	continue;
			vis[x]=true;
			int i=x/m,j=x%m;
			int U=(i-1)*m+j,L=i*m+j-1;
			int D=(i+1)*m+j,R=i*m+j+1;
			if(i!=0&&!vis[U]&&dist[U]>dist[x]+v[U]){
				dist[U]=dist[x]+v[U];
				pre[U]=x;
				pq.emplace(dist[U],U);
			}
			if(i+1!=n&&!vis[D]&&dist[D]>dist[x]+v[D]){
				dist[D]=dist[x]+v[D];
				pre[D]=x;
				pq.emplace(dist[D],D);
			}
			if(j!=0&&!vis[L]&&dist[L]>dist[x]+v[L]){
				dist[L]=dist[x]+v[L];
				pre[L]=x;
				pq.emplace(dist[L],L);
			}
			if(j+1!=m&&!vis[R]&&dist[R]>dist[x]+v[R]){
				dist[R]=dist[x]+v[R];
				pre[R]=x;
				pq.emplace(dist[R],R);
			}
		}
		for(int it:st[u]){
			while(it!=-1)
				g[it/m][it%m]=true,it=pre[it];
		}
	}
	cout<<dp[(1<<k)-1][idx]<<'\n';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<(g[i][j]?'X':'.');
		cout<<'\n';
	}
}