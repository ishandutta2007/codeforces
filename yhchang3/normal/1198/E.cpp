#include<bits/stdc++.h>
using namespace std;

// Template of Dinic's Algo Starts
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
// Template of Dinic's Algo Ends


bool hasedge[110][110];

struct Rectangle{
	int x1, x2, y1, y2;
}rec[50];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<int,int> discrete_x, discrete_y;
	discrete_x[1] = discrete_x[n+1] = 0;
	discrete_y[1] = discrete_y[n+1] = 0;
	for(int i=0;i<m;i++){
		cin >> rec[i].x1 >> rec[i].y1 >> rec[i].x2 >> rec[i].y2;
		discrete_x[rec[i].x1] = discrete_x[rec[i].x2+1] = 0;	
		discrete_y[rec[i].y1] = discrete_y[rec[i].y2+1] = 0;	
	}
	int xcnt = 0, ycnt = 0;
	for(auto &it:discrete_x)
		it.second = xcnt++;
	for(auto &it:discrete_y)
		it.second = ycnt++;
	for(int i=0;i<m;i++)
		for(int x=discrete_x[rec[i].x1];x<discrete_x[rec[i].x2+1];x++)
			for(int y=discrete_y[rec[i].y1];y<discrete_y[rec[i].y2+1];y++)
				hasedge[x][y] = true;
	const int inf = 1e9;
	Dinic<210> D;
	int st = xcnt + ycnt, ed = st + 1, maxidx = ed;
	//build edge
	for(auto it=discrete_x.begin();next(it)!=discrete_x.end();++it)
		D.addedge(st, it->second, next(it) -> first - it -> first);
	for(auto it=discrete_y.begin();next(it)!=discrete_y.end();++it)
		D.addedge(it->second + xcnt, ed, next(it) -> first - it -> first);
	for(int x=0;x<xcnt;x++)
		for(int y=0;y<ycnt;y++)
			if(hasedge[x][y])
				D.addedge(x, y+xcnt, inf);
	cout << D.maxflow(maxidx, st, ed) << endl; 
}