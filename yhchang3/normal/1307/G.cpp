#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;

struct MCMF{
	struct edge_type{
		int to,w,c,f,rev;
		edge_type(int to=0,int w=0,int f=0,int rev=0):to(to),w(w),f(f),rev(rev){}
	};
	int s,t,n;
	vector<edge_type> edges;
	vector<int> e[MAXN];
	int dist[MAXN];
	bool vis[MAXN];
	int p[MAXN];
	const int INF = 1e9;
	void addedge(int u,int v,int w,int cap){
		int sz = edges.size();
		edges.emplace_back(edge_type(v,w,cap,sz+1));
		e[u].emplace_back(sz);
		edges.emplace_back(edge_type(u,-w,0,sz));
		e[v].emplace_back(sz+1);
	}
	bool spfa(){
		queue<int> q;
		for(int i=0;i<=n;i++)
			vis[i]=false,dist[i]=INF,p[i]=-1;
		dist[s]=0;
		vis[s]=true;
		q.emplace(s);
		while(!q.empty()){
			int x = q.front();q.pop();
			vis[x]=false;
			for(int i:e[x]){
				auto &it = edges[i];
				if(it.f&&it.w+dist[x]<dist[it.to]){
					p[it.to]=i;
					dist[it.to]=it.w+dist[x];
					if(!vis[it.to])	q.emplace(it.to),vis[it.to]=true;
				}
			}
		}
		return p[t]!=-1;
	}
	int cost=0,flow=0;
	vector<int> D,tot;
	void update(){
		int x=t;
		while(x!=s){
			int y=p[x];
			edges[y].f--;
			edges[y^1].f++;
			x=edges[y^1].to;
		}
		D.emplace_back(dist[t]);
	}
	void solve(int s_,int t_,int n_){
		s=s_,t=t_,n=n_;
		while(spfa())	update();
		tot.resize(D.size());
		for(int i=0;i<D.size();i++){
			if(i==0)	continue;
			tot[i]=tot[i-1]+i*(D[i]-D[i-1]);
		}
	}
}mcmf;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mcmf.addedge(u,v,w,1);
	}
	mcmf.solve(1,n,n);
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		int idx = upper_bound(mcmf.tot.begin(),mcmf.tot.end(),x)-mcmf.tot.begin()-1;
		double ans = mcmf.D[idx];
		cout<<fixed<<setprecision(10)<<ans+1.*(x-mcmf.tot[idx])/(idx+1)<<'\n';
	}
}