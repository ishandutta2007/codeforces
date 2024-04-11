#include <bits/stdc++.h>
using namespace std;

vector < vector <int> > g, gc;
vector < vector < pair <int, pair <int, int> > > > gk;
vector <int> c, color, labels;
vector <bool> vis, visk;

bool dfsk(int u, int label){
	vis[u] = true;
	labels[u] = label;
	
	for(int v : g[u]){
		if(c[v] != c[u])continue;
		
		if(vis[v]){
			if(labels[u] == labels[v])return true;
		}else{
			if(dfsk(v, label ^ 1))return true;
		}
	}
	return false;
}

bool dfs(int u){
	if(color[u] == -1)color[u] = 0;
	
	for(int v : gc[u]){
		if(color[v] == -1){
			color[v] = color[u] ^ 1;
			if(dfs(v))return true;
		}else{
			if(color[u] == color[v])return true;
		}
	}
	
	if(color[u ^ 1] == -1){
		color[u ^ 1] = color[u] ^ 1;
		if(dfs(u ^ 1))return true;
	}else{
		if(color[u] == color[u ^ 1])return true;
	}
	
	return false;
}

int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	c.resize(n);
	vector < vector <int> > vc(k);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
		c[i]--;
		vc[c[i]].push_back(i);
	}
	
	g.resize(n);
	gk.resize(k);
	
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--, b--;
		
		g[a].push_back(b);
		g[b].push_back(a);
		
		if(c[a] != c[b]){
			if(c[a] > c[b])swap(a, b);
			gk[c[a]].push_back(make_pair(c[b], make_pair(a, b)));
		}
	}
	
	vis.resize(n, false);
	labels.resize(n, -1);
	
	vector <bool> mark(k, false);
	
	int cnt = 0, nc = 0;
	for(int i = 0; i < k; i++){
		for(int u : vc[i])if(!vis[u]){
			if(dfsk(u, nc)){
				mark[i] = true;
				break;
			}
			nc += 2;
		}
		if(!mark[i]){
			cnt++;
		}
	}
	
	
	long long res = 1LL * cnt * (cnt - 1) / 2;
	
	gc.resize(nc);
	color.resize(nc, -1);
	
	for(int i = 0; i < k; i++)if(!mark[i]){
		sort(gk[i].begin(), gk[i].end());
		
		for(int j = 0; j < (int)gk[i].size(); ){
			set <int> active;
			
			if(mark[gk[i][j].first]){
				int l = j;
				while(l < (int)gk[i].size() && gk[i][j].first == gk[i][l].first){
					l++;
				}
				j = l;
				continue;
			}
			
			int l = j;
			while(l < (int)gk[i].size() && gk[i][j].first == gk[i][l].first){
				auto[u, v] = gk[i][l].second;
				
				gc[labels[u]].push_back(labels[v]);
				gc[labels[v]].push_back(labels[u]);
				active.insert(labels[u]);
				active.insert(labels[v]);
				active.insert(labels[u] ^ 1);
				active.insert(labels[v] ^ 1);
				
				l++;
			}
			/*
			cout << i + 1 << ',' << gk[i][j].first + 1 << " ::: " << endl;
			for(int u = 0; u < nc; u++){
				cout << u + 1 << " ====> ";
				for(int v : gc[u])
					cout << v + 1 << ", ";
				cout << endl;
			}
			cout << "color :: ";
			for(int u = 0; u < nc; u++)
				cout << color[u] << ' ';
			cout << endl;
			*/
			bool ok = true;
			for(int u : active)if(color[u] == -1){
				if(dfs(u)){
					ok = false;
					break;
				}
			}
			
			if(!ok)res--;
			
			for(int u : active){
				gc[u].clear();
				color[u] = -1;
			}
			
			j = l;
		}
	}
	
	printf("%lld\n", res);
	
	return 0;
}