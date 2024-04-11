#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> g[100001];
int f[100001][20];
pair <int, int> d[100001][2];
bool done[100001];
int cnt=0;
int top[100001];
int h[100001];
int first[100001];
int last[100001];
void dfs(int u){
	done[u]=1;
	cnt++;
	first[u]=cnt;
	d[u][0]={0, u};
	d[u][1]={-1e9, 0};
	for(int i=0; f[f[u][i]][i]; i++) f[u][i+1]=f[f[u][i]][i];
	for(int v: g[u]) if(!done[v]){
		h[v]=h[u]+1;
		f[v][0]=u;
		dfs(v);
		if(d[v][0].first+1>d[u][0].first){
			d[u][1]=d[u][0];
			d[u][0]={d[v][0].first+1, v};
		}
		else if(d[v][0].first+1>d[u][1].first){
			d[u][1]={d[v][0].first+1, v};
		}
	}
	last[u]=cnt;
}
void redfs(int u, int w){
	top[u]=w;
	for(int v: g[u]) if(f[v][0]==u) redfs(v, max(w, d[u][v==d[u][0].second].first)+1);
}
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	int value, lazy;
	pointer left, right;
	segment_tree(int l, int r): l(l), r(r){
		m=(l+r)/2;
		value=lazy=-1e9;
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
	}
	void down(){
		left->value=max(left->value, lazy);
		right->value=max(right->value, lazy);
		left->lazy=max(left->lazy, lazy);
		right->lazy=max(right->lazy, lazy);
	}
	void up(){
		value=max(left->value, right->value);
	}
	void update(int u, int v, int x){
		if(u>v) return;
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			lazy=max(lazy, x);
			value=max(value, x);
		}
		else{
			down();
			left->update(u, v, x);
			right->update(u, v, x);
			up();
		}
	}
	int get(int u, int v){
		if(u>v) return -1e9;
		if(l>v||r<u) return -1e9;
		if(u<=l&&v>=r) return value;
		else{
			down();
			return max(left->get(u, v), right->get(u, v));
		}
	}
};
segment_tree::pointer tree;
int lca(int u, int v){
	if(h[u]<h[v]) swap(u, v);
	for(int i=__lg(h[u]); i>=0; i--) if(h[f[u][i]]>=h[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=__lg(h[u]); i>=0; i--) if(f[u][i]!=f[v][i]){
		u=f[u][i];
		v=f[v][i];
	}
	return f[u][0];
}
int climb(int u, int len){
	for(int i=__lg(len); len; i=__lg(len)){
		len-=1<<i;
		u=f[u][i];
	}
	return u;
}
int find_root(int u, int v){
	for(int i=__lg(h[u]); i>=0; i--) if(h[f[u][i]]>h[v]) u=f[u][i];
	return u;
}
int max_range(int l, int r, int u, int v, int a, int b){
	// cerr<<l<<' '<<r<<' '<<u<<' '<<v<<' '<<a<<' '<<b<<'\n';
	
	if(a<u){
		swap(a, u);
		swap(v, b);
	}
	
	if(u<=a&&v>=b)	return max(tree->get(l, u-1), tree->get(v+1, r));
	else if(v>=a) return max(tree->get(l, u-1), tree->get(max(v, b)+1, r));
	else return max(tree->get(l, u-1), max(tree->get(v+1, a-1), tree->get(b+1, r)));
}
vector <pair <pair <int, int>, int>> qr;
class query{
public:
	int u, v, l, x, ans;
	void input(int id){
		cin>>u>>v;
		// if(n==27&&id==221){
			// cout<<u<<' '<<v<<'\n';
			// exit(0);
		// }
		l=lca(u, v);
		ans=0;
		if(h[u]<h[v]) swap(u, v);
		ans=max(ans, d[u][0].first);
		// cerr<<ans<<'\n';
		x=climb(u, (h[u]+h[v]-h[l]*2-1)/2);
		if(v!=l) ans=max(ans, d[v][0].first);
		else{
			bool contained=(first[d[v][0].second]<=first[u])&&(last[d[v][0].second]>=first[u]);
			ans=max(ans, d[v][contained].first);
		}
		// cerr<<ans<<'\n';
		int ra=find_root(v, l);
		// cerr<<x<<'\n';
		// cerr<<first[l]<<' '<<last[l]<<' '<<first[x]<<' '<<last[x]<<' '<<first[ra]<<' '<<last[ra]<<'\n';
		// cerr<<ans<<'\n';
		ans=max(ans, max_range(first[l], last[l], first[x], last[x], (ra==l)?(last[l]+1):first[ra], (ra==l)?(last[l]+1):last[ra])+h[v]-h[l]*2);
		// cerr<<max_range(first[l], last[l], first[x], last[x], (ra==l)?(last[l]+1):first[ra], (ra==l)?(last[l]+1):last[ra])<<'\n';
		// cerr<<ans<<'\n';
		if(l!=ra&&v!=ra) qr.push_back({{v, ra}, id});
		// cerr<<u<<' '<<v<<'\n';
		// cerr<<l<<' '<<x<<'\n';
		if(l!=x) qr.push_back({{u, x}, id});
		ans=max(ans, h[v]-h[l]+top[l]);
		// cerr<<ans<<'\n';
	}
};
vector <query> q;
vector <int> pos;
int main(){
	cin>>n;
	for(int i=1, u, v; i<n; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	h[1]=1;
	dfs(1);
	redfs(1, 0);
	tree=new segment_tree(1, n);
	for(int i=1; i<=n; i++) tree->update(first[i], first[i], h[i]);
	cin>>m;
	q.resize(m);
	for(int i=0; i<m; i++) q[i].input(i);
	sort(qr.begin(), qr.end(), [](pair <pair <int, int>, int> a, pair <pair <int, int>, int> b){
		return h[a.first.second]>h[b.first.second];
	});
	for(int i=1; i<=n; i++)	pos.push_back(i);
	sort(pos.begin(), pos.end(), [](int a, int b){
		return h[a]<h[b];
	});
	tree=new segment_tree(1, n);
	for(auto x: qr){
		while((!pos.empty())&&(h[pos.back()]>=h[x.first.second])){
			int u=pos.back();
			pos.pop_back();
			if(d[u][0].second){
				tree->update(first[u], first[d[u][0].second]-1, d[u][0].first-h[u]);
				tree->update(last[d[u][0].second]+1, last[u], d[u][0].first-h[u]);
			}
			if(d[u][1].second){
				tree->update(first[u], first[d[u][1].second]-1, d[u][1].first-h[u]);
				tree->update(last[d[u][1].second]+1, last[u], d[u][1].first-h[u]);
			}
			// cerr<<u<<' '<<first[u]<<' '<<last[u]<<' '<<-h[u]<<'\n';
			tree->update(first[u], last[u], -h[u]);
		}
		// cerr<<first[x.first.first]<<' '<<first[x.first.first]<<' '<<h[x.first.first]<<'\n';
		// for(int i=1; i<=n; i++) cerr<<tree->get(i, i)<<" \n"[i==n];
		// cerr<<x.first.first<<' '<<x.first.second<<' '<<x.second<<'\n';
		// cerr<<tree->get(first[x.first.first], first[x.first.first])<<'\n';
		// cerr<<h[x.first.first]<<'\n';
		// cerr<<q[x.second].ans<<'\n';
		q[x.second].ans=max(q[x.second].ans, tree->get(first[x.first.first], first[x.first.first])+h[x.first.first]);
	}
	for(int i=0; i<m; i++) cout<<q[i].ans<<'\n';
}