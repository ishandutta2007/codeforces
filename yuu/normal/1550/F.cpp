#include <bits/stdc++.h>
using namespace std;
int n, q, s, d;
int a[200001];
set <pair <int, int>> all;
set <int> com[200001];
int from_set[200001];
int f[200001];
bool done[200001];
class edge{
public:
	int a, b, w;
	edge(int a, int b, int w): a(a), b(b), w(w){}
	bool operator < (const edge &e) const{
		if(w!=e.w) return w<e.w;
		if(a!=e.a) return a<e.a;
		return b<e.b;
	}
};
vector <pair <int, int>> g[200001];
edge find_best_edge(int x, int c){
	auto it=all.lower_bound({c, 0});//first thing >=c
	if(it==all.end()) return edge(x, all.rbegin()->second, abs(all.rbegin()->first-c));
	else if(it==all.begin()) return edge(x, it->second, abs(it->first-c));//c is left most
	else{
		edge res=edge(x, it->second, abs(it->first-c));
		it--;
		return min(res, edge(x, it->second, abs(it->first-c)));
	}
}
void boruvka(){
	for(int i=1; i<=n; i++){
		all.insert({a[i], i});
		com[i].insert(i);
		from_set[i]=i;
	}
	int set_count=n;
	while(set_count>1){
		vector <edge> new_edge;
		for(int i=1; i<=n; i++) if(i==from_set[i]){
			edge best_edge(0, 0, 1e9);
			for(const int &x: com[i]) all.erase({a[x], x});
			for(const int &x: com[i]){
				best_edge=min(best_edge, find_best_edge(x, a[x]-d));
				best_edge=min(best_edge, find_best_edge(x, a[x]+d));
			}
			for(const int &x: com[i]) all.insert({a[x], x});
			new_edge.push_back(best_edge);
		}
		for(auto e: new_edge){
			if(from_set[e.a]==from_set[e.b]) continue;
			g[e.a].push_back({e.b, e.w});
			g[e.b].push_back({e.a, e.w});
			e.a=from_set[e.a];
			e.b=from_set[e.b];
			if(com[e.a].size()<com[e.b].size()) swap(e.a, e.b);
			for(const int &x: com[e.b]){
				com[e.a].insert(x);
				from_set[x]=e.a;
			}
			com[e.b].clear();
			set_count--;
		}
	}
}
void dfs(int u, int k=0){
	done[u]=1;
	f[u]=k;
	for(auto &v: g[u]) if(!done[v.first]) dfs(v.first, max(k, v.second));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q>>s>>d;
	for(int i=1; i<=n; i++) cin>>a[i];
	boruvka();
	dfs(s);
	for(int i=1, x, k; i<=q; i++){
		cin>>x>>k;
		if(f[x]<=k) cout<<"Yes\n";
		else cout<<"No\n";
	}
}