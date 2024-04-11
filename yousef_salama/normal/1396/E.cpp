#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

vector <int> g[MAXN];
int n, par[MAXN], sz[MAXN], depth[MAXN];
long long k;

void init(int u, int parent = -1){
	if(parent == -1)depth[u] = 0;
	else depth[u] = depth[parent] + 1;
	
	par[u] = parent;
	sz[u] = 1;
	
	for(int v : g[u]){
		if(v == parent)continue;
		
		init(v, u);
		sz[u] += sz[v];
	}
}

int get_centroid(int u, int parent = -1){
	bool ok = true;
	for(int v : g[u]){
		if(v == parent)continue;
		
		int r = get_centroid(v, u);
		if(r != -1)return r;
		
		if(sz[v] * 2 > n)ok = false;
	}
	
	if(ok && sz[u] * 2 >= n)return u;
	else return -1;
}

vector < vector <int> > v[MAXN];
int max_depth[MAXN];

void init2(int u, int subtree, int parent){
	while((int)v[subtree].size() <= depth[u]){
		v[subtree].push_back(vector <int>());
		max_depth[subtree]++;
	}
	v[subtree][depth[u]].push_back(u);
	
	for(int v : g[u]){
		if(v == parent)continue;
		init2(v, subtree, u);
	}
}

int main(){
	scanf("%d %lld", &n, &k);
	
	for(int i = 0; i < n - 1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	init(0);
	int cent = get_centroid(0);
	
	init(cent);
	
	long long sum = 0;
	for(int i = 0; i < n; i++)
		sum += depth[i];
	
	priority_queue < pair <int, int> > q;
	for(int u : g[cent])
		q.push({sz[u], u});
	
	memset(max_depth, -1, sizeof max_depth);
	for(int u : g[cent])
		init2(u, u, cent);
	
	if(k > sum || (sum - k) % 2 != 0){
		printf("NO\n");
		return 0;
	}
	
	vector < pair <int, int> > p;
	vector <bool> vis(n, false);
	
	while(sum > k){
		if(q.empty() || q.top().first < 2)break;
		
		pair <int, int> t = q.top();
		q.pop();
		
		if(t.first > 2)q.push({t.first - 2, t.second});
		
		while(true){
			if(v[t.second][max_depth[t.second]].empty()){
				max_depth[t.second]--;
				continue;
			}
			if(vis[v[t.second][max_depth[t.second]].back()]){
				v[t.second][max_depth[t.second]].pop_back();
				continue;
			}
			break;
		}

		if(sum - 2 * (max_depth[t.second] - 1) > k){
			int a = par[v[t.second][max_depth[t.second]].back()];
			
			while(true){
				if(g[a].back() == par[a] || vis[g[a].back()]){
					g[a].pop_back();
					continue;
				}
				break;
			}
			int b = g[a].back();
			g[a].pop_back();
			
			while(!g[a].empty()){
				if(g[a].back() == par[a] || vis[g[a].back()]){
					g[a].pop_back();
					continue;
				}
				break;
			}
			
			if(g[a].empty()){
				p.push_back({a, b});
				vis[a] = true;
				vis[b] = true;
			}else{
				p.push_back({b, g[a].back()});
				vis[b] = true;
				vis[g[a].back()] = true;
			}
			sum -= 2 * (max_depth[t.second] - 1);
		}else{
			int a = v[t.second][max_depth[t.second]].back();
			int steps = (2 * (max_depth[t.second] - 1) + k - sum) / 2;
			
			while(steps > 0){
				a = par[a];
				steps--;
			}
			
			p.push_back({a, par[a]});
			
			assert(!vis[a]);
			assert(!vis[par[a]]);
			vis[a] = true;
			vis[par[a]] = true;
			
			sum = k;
			
			break;
		}
	}
	
	if(sum > k){
		printf("NO\n");
		return 0;
	}
	
	v[cent].push_back({{cent}});
	max_depth[cent] = 0;
	q.push({1, cent});
	
	while(!q.empty()){
		pair <int, int> t1 = q.top();
		q.pop();
		pair <int, int> t2 = q.top();
		q.pop();
		
		while(true){
			if(v[t1.second][max_depth[t1.second]].empty()){
				max_depth[t1.second]--;
				continue;
			}
			if(vis[v[t1.second][max_depth[t1.second]].back()]){
				v[t1.second][max_depth[t1.second]].pop_back();
				continue;
			}
			break;
		}
		
		while(true){
			if(v[t2.second][max_depth[t2.second]].empty()){
				max_depth[t2.second]--;
				continue;
			}
			if(vis[v[t2.second][max_depth[t2.second]].back()]){
				v[t2.second][max_depth[t2.second]].pop_back();
				continue;
			}
			break;
		}
		
		p.push_back({v[t1.second][max_depth[t1.second]].back(), v[t2.second][max_depth[t2.second]].back()});
		vis[v[t1.second][max_depth[t1.second]].back()] = true;
		vis[v[t2.second][max_depth[t2.second]].back()] = true;
	
		if(t1.first > 1)q.push({t1.first - 1, t1.second});
		if(t2.first > 1)q.push({t2.first - 1, t2.second});
	}
	
	printf("YES\n");
	for(pair <int, int> c : p)	
		printf("%d %d\n", c.first + 1, c.second + 1);
	
	return 0;
}