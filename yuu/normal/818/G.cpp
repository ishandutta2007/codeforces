#include <bits/stdc++.h>
using namespace std;
int n;
int a[5001];
class MCMF{
public:
	static const int sz=20000;
	class edge{
	public:
		using pointer=edge*;
		int v, c, w;
		pointer rev;
		edge(int v, int c, int w): v(v), c(c), w(w){}
	};
	vector <edge::pointer> g[sz];
	int n;
	void reset(int _n){
		n=_n;
		for(int i=0; i<n; i++) g[i].clear();//can delete edge to lower memory usage if needed
	}
	void add_edge(int u, int v, int c, int w){
		// cerr<<u<<' '<<v<<' '<<c<<' '<<w<<'\n';
		g[u].push_back(new edge(v, c, w));
		g[v].push_back(new edge(u, 0, -w));
		g[u].back()->rev=g[v].back();
		g[v].back()->rev=g[u].back();
	}
	int d[sz];
	edge::pointer trace[sz];
	int source, sink;
	queue <int> q;
	bool inq[sz];
	bool find_path(){
		for(int i=0; i<sz; i++) d[i]=1e9;
		d[source]=0;		
		q.push(source);
		inq[source]=1;
		while(!q.empty()){
			auto u=q.front();
			inq[u]=0;
			q.pop();
			for(auto i: g[u]) if(i->c) if(d[i->v]>d[u]+i->w){
				d[i->v]=d[u]+i->w;
				trace[i->v]=i;
				if(!inq[i->v]){
					inq[i->v]=1;
					q.push(i->v);
				}
			}
		}
		return d[sink]!=1e9;
	}
	int ansflow, anscost;
	void increase_flow(){
		int u=sink;
		int cap=1e9;
		while(u!=source){
			// cerr<<u<<' ';
			cap=min(cap, trace[u]->c);
			u=trace[u]->rev->v;
		}
		// cerr<<'\n';
		ansflow+=cap;
		anscost+=cap*d[sink];
		u=sink;
		while(u!=source){
			trace[u]->c-=cap;
			trace[u]->rev->c+=cap;
			u=trace[u]->rev->v;
		}
	}
	pair <int, int> flow(int s, int t){
		source=s;
		sink=t;
		ansflow=anscost=0;
		while(find_path()) increase_flow();
		return {ansflow, anscost};
	}
} F;
int main(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	F.reset(n*2+3);
	for(int i=1; i<=n; i++)	F.add_edge(i+2, i+n+2, 1, -1);
	for(int i=1; i<=n; i++)	F.add_edge(1, i+2, 1, 0);
	for(int i=1; i<=n; i++)	F.add_edge(i+n+2, 2, 1, 0);
	const int flowsize=4;
	for(int i=1; i<=n; i++){
		int mod=flowsize*2, p1=flowsize*2, n1=flowsize*2; 
		for(int j=i+1; j<=n; j++){
			if((a[i]-a[j])%7==0){
				if(mod){
					mod--;
					F.add_edge(i+n+2, j+2, 1, 0);
				}
			}
			else if(a[j]==a[i]+1){
				if(p1){
					p1--;
					F.add_edge(i+n+2, j+2, 1, 0);
				}
			}
			else if(a[j]==a[i]-1){
				if(n1){
					n1--;
					F.add_edge(i+n+2, j+2, 1, 0);
				}
			}
		}
	}
	F.add_edge(0, 1, flowsize, 0);
	cout<<-F.flow(0, 2).second<<'\n';
}