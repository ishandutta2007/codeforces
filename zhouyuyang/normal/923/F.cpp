#include<bits/stdc++.h>
#define pa pair<int,int>
#define N 100005
#define se second
#define fi first
using namespace std;
struct Tree{
	set<pa > all,e,leaf;
	set<int> ver,adj[N];
	int n,deg[N];
	void add(int x,int y){
		e.insert(pa(x,y));
		e.insert(pa(y,x));
		adj[x].insert(y);
		adj[y].insert(x);
		deg[x]++; deg[y]++;
	}
	void init(){
		for (int i=1;i<=n;i++){
			ver.insert(i);
			all.insert(pa(deg[i],i));
			if (deg[i]==1)
				leaf.insert(pa(*adj[i].begin(),i));
		}
	}
	int star(){
		return ver.size()-all.rbegin()->fi-1;
	}
	void erase(int x){
		int y=*adj[x].begin();
		ver.erase(x);
		leaf.erase(pa(y,x));
		all.erase(pa(1,x));
		adj[x].erase(y);
		adj[y].erase(x);
		all.erase(pa(deg[y],y));
		all.insert(pa(--deg[y],y));
		if (deg[y]==1)
			leaf.insert(pa(*adj[y].begin(),y));
	}
	pa leaves(){
		set<pa > s;
		s.insert(*leaf.begin());
		s.insert(*++leaf.begin());
		s.insert(*leaf.rbegin());
		s.insert(*++leaf.rbegin());
		int big=-1;
		set<pa >::iterator it;
		for (it=s.begin();it!=s.end();it++)
			if (deg[it->fi]>2){
				big=it->fi;
				break;
			}
		if (big!=-1){
			int x=-1,y=-1;
			for (it=s.begin();it!=s.end();it++)
				if (it->fi==big)
					x=it->se;
				else y=it->se;
			return pa(x,y);
		}
		return pa(leaf.begin()->se,leaf.rbegin()->se);
	}
}T1,T2;
int ans[N],n;
void solvestar(Tree &T1,Tree &T2){
	int u=(++T1.all.rbegin())->se;
	int v=*T1.adj[u].begin();
	int w=*T1.adj[u].rbegin();
	if (T1.deg[w]==1) swap(v,w);
	int W=T2.leaf.begin()->se;
	int V=T2.leaf.begin()->fi;
	set<int>::iterator it;
	int U=-1;
	for (it=T2.ver.begin();it!=T2.ver.end();it++)
		if (T2.e.find(pa(*it,V))==T2.e.end())
			if (T2.e.find(pa(*it,W))==T2.e.end()){
				U=*it; break;
			}
	ans[u]=U; ans[v]=V; ans[w]=W;
	static vector<int> g,h;
	g.resize(0); h.resize(0);
	for (it=T1.ver.begin();it!=T1.ver.end();it++)
		if (*it!=u&&*it!=v&&*it!=w)
			g.push_back(*it);
	for (it=T2.ver.begin();it!=T2.ver.end();it++)
		if (*it!=U&&*it!=V&&*it!=W)
			h.push_back(*it);
	for (int i=0;i<g.size();i++)
		ans[g[i]]=h[i];
}
void solveBf(){
	vector<int> g,h;
	int n=T1.ver.size();
	set<int>::iterator it;
	for (it=T1.ver.begin();it!=T1.ver.end();it++)
		g.push_back(*it);
	for (it=T2.ver.begin();it!=T2.ver.end();it++)
		h.push_back(*it);
	do{
		bool fl=1;
		for (int i=0;i<n;i++)
			for (int j=0;j<i;j++)
				if (T1.e.find(pa(g[i],g[j]))!=T1.e.end())
					if (T2.e.find(pa(h[i],h[j]))!=T2.e.end()){
						fl=0; i=j=n;
					}
		if (fl){
			for (int i=0;i<n;i++)
				ans[g[i]]=h[i];
			return;
		}
	}while (next_permutation(g.begin(),g.end()));
}
void solve(){
	if (T1.ver.size()<=5)
		solveBf();
	else if (T1.star()==1)
		solvestar(T1,T2);
	else if (T2.star()==1){
		solvestar(T2,T1);
		static int tmp[N];
		for (int i=1;i<=n;i++)
			tmp[ans[i]]=i;
		for (int i=1;i<=n;i++)
			ans[i]=tmp[i];
	}
	else{
		pa a=T1.leaves(),c=T2.leaves();
		pa b=pa(*T1.adj[a.fi].begin(),*T1.adj[a.se].begin());
		pa d=pa(*T2.adj[c.fi].begin(),*T2.adj[c.se].begin());
		T1.erase(a.fi); T1.erase(a.se);
		T2.erase(c.fi); T2.erase(c.se);
		solve();
		if (ans[b.fi]!=d.fi&&ans[b.se]!=d.se)
			ans[a.fi]=c.fi,ans[a.se]=c.se;
		else ans[a.fi]=c.se,ans[a.se]=c.fi;
	}
}
int main(){
	scanf("%d",&n);
	T1.n=T2.n=n;
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		T1.add(x,y);
	}
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		T2.add(x-n,y-n);
	}
	T1.init();
	T2.init();
	if (!T1.star()||!T2.star())
		return puts("No"),0;
	solve();
	puts("Yes");
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]+n);
}