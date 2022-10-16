#include <bits/stdc++.h>
using namespace std;
int k;
queue <int> q;
bool done[1<<17];
int trace[1<<17];
vector <int> g[1<<17];
vector <int> f[1<<17];
int bfs(int u){
	for(int i=1; i<=k; i++) done[i]=0;
	q.push(u);
	done[u]=1;
	trace[u]=-1;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int v: g[u]) if(!done[v]){
			done[v]=1;
			trace[v]=u;
			q.push(v);
		}
	}
	return u;
}
set <int> ans;
int h[1<<17];
vector <int> fixes;
bool dfs(int u){
	done[u]=1;
	h[u]=0;
	for(int &x: f[u]) if(done[x]){
		swap(x, f[u].back());
		f[u].pop_back();
		break;
	}
	for(int v: f[u]){
		if(!dfs(v)) return 0;
		h[u]=max(h[u], h[v]+1);
	}
	if(f[u].empty()) return 1;
	else if(f[u].size()==1){
		if(h[u]>1) return 0;
		///have to fix u-th vertex
		fixes.push_back(u);
	}
	else if(f[u].size()==2){
		if(h[f[u][0]]==h[f[u][1]]) return 1;
		return 0;
		// if(h[f[u][0]]>h[f[u][1]]) swap(f[u][0], f[u][1]);
		// if(h[f[u][0]]+1!=h[f[u][1]]) return 0;
		// fixes.push_back(u);
	}
	else if(f[u].size()==3){
		sort(f[u].begin(), f[u].end(), [](int x, int y){
			return h[x]<h[y];
		});
		if(h[f[u][1]]!=h[f[u][0]]) return 0;
		if(h[f[u][2]]!=h[f[u][1]]+1) return 0;
		fixes.push_back(u);
	}
	else return 0;
	if(fixes.size()>1) return 0;
	return 1;
}
void test(int u){
	for(int i=1; i<=k; i++) done[i]=0;
	for(int i=1; i<=k; i++) f[i]=g[i];
	fixes.clear();
	if(!dfs(u)) fixes.clear();
	for(auto &x: fixes) ans.insert(x);
}
int main(){
	int n;
	cin>>n;
	if(n==2){
		cout<<"2\n1 2\n";
		return 0;
	}
	k=(1<<n)-2;
	for(int i=1, a, b; i<k; i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1; i<=k; i++) if(g[i].size()>4){
		cout<<"0\n";
		return 0;
	}
	int u=bfs(bfs(1));
	vector <int> path;
	while(u!=-1){
		path.push_back(u);
		u=trace[u];
	}
	set <int> tests;
	vector <int> core;
	for(int i=-2; i<=2; i++){
		int id=(i+((int)path.size()))/2;
		if(id<0||id>=path.size()) continue;
		core.push_back(path[id]);
	}
	for(int x: core){
		tests.insert(x);
		for(int y: g[x]) tests.insert(y);
	}
	for(int x: tests) test(x);
	cout<<ans.size()<<'\n';
	for(int x: ans) cout<<x<<' ';
	cout<<'\n';
}