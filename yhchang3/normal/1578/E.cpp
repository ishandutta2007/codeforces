#include<bits/stdc++.h>
using namespace std;

template<int SZX,int SZY> struct BM{
	int mx[SZX+1],my[SZY+1],lev[SZX+1],visx[SZX+1],visy[SZY+1];
	vector<int> e[SZX+1];
	bool dfs(int x){
		for(int y:e[x]){
			int w=my[y];
			if(w==-1||(lev[w]==lev[x]+1&&dfs(w)))
				return mx[x]=y,my[y]=x,true;
		}
		return lev[x]=-1,false;
	}
	void clear(int m){for(int i=1;i<=m;i++)	vector<int>().swap(e[i]);}
	void addedge(int x,int y){e[x].emplace_back(y);}
	int matching(int m,int n){
		fill(mx+1,mx+m+1,-1),fill(my+1,my+n+1,-1);
		for(int res=0;;){
			queue<int> q;
			for(int i=1;i<=m;i++)
				if(mx[i]==-1)	q.emplace(i),lev[i]=0;
				else	lev[i]=-1;
			while(!q.empty()){
				int x=q.front();q.pop();
				for(int y:e[x]){
					int w=my[y];
					if(w!=-1&&lev[w]==-1)
						q.emplace(w),lev[w]=lev[x]+1;
				}
			}
			int delta=0;
			for(int i=1;i<=m;i++)
				if(mx[i]==-1&&dfs(i))
					delta++;
			if(delta)	res+=delta;
			else	return res;
		}
		return 0;
	}
};

#define eb emplace_back
template<int SZ> struct Dinic{
	typedef int F;struct EDGE{int to,rev;F flow,cap;};
	int lev[SZ],n,s,t;vector<EDGE> E;vector<int> G[SZ];
	vector<int>::iterator cur[SZ];
	void init(){E.clear();for(int i=0;i<SZ;i++)	G[i].clear();}
	void reset(){for(auto &it:E)	it.flow = 0;}
	void addedge(int u,int v,F cap,bool GH=false){
		int id = E.size();
		E.eb((EDGE){v,id+1,0,cap});G[u].eb(id);
		E.eb((EDGE){u,id,0,GH?cap:0});G[v].eb(id+1);
	}
	bool bfs(){
		for(int i=0;i<=n;i++)	lev[i]=-1;queue<int> q;q.emplace(s);lev[s]=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i:G[u]){
				auto &e=E[i];int v=e.to;
				if(lev[v]<0&&e.flow<e.cap)	q.emplace(v),lev[v]=lev[u]+1;
			}
		}
		return lev[t]>=0;
	}
	F dfs(int u,F flow){
		if(u==t)	return flow;
		for(;cur[u]!=G[u].end();cur[u]++){
			auto &e = E[*cur[u]];int v=e.to;
			if(e.flow<e.cap&&lev[u]+1==lev[v]){
				F df=dfs(v,min(flow,e.cap-e.flow));
				if(df>0){e.flow+=df;E[e.rev].flow-=df;return df;}
			}
		}
		return 0;
	}
	F maxflow(int n_,int s_,int t_){
		n=n_;s=s_;t=t_;F flow = 0;
		while(bfs()){
			for(int i=0;i<=n;i++)	cur[i]=G[i].begin();
			while(F df = dfs(s,numeric_limits<F>::max()))	flow+=df;
		}
		return flow;
	}
};

BM<300, 300> B;
Dinic<305> D;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	vector<int> price(n + 1);
	for(int i=1;i<=n;i++) {
		int k;
		cin >> k;
		v[i].resize(k);
		for(int j=0;j<k;j++)
			cin >> v[i][j], B.addedge(i, v[i][j]);
	}
	for(int i=1;i<=n;i++)
		cin >> price[i];
	assert(B.matching(n, n) == n);
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(price[i] < 0)	D.addedge(n + 1, i, -price[i]), ans += price[i];
		else	D.addedge(i, n + 2, price[i]);
		for(int x : v[i])
			if(x != B.mx[i])
				D.addedge(i, B.my[x], 1e9);
	}
	cout << ans + D.maxflow(n + 2, n + 1, n + 2) << endl;
}