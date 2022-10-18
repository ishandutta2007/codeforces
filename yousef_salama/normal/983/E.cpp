#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, pi, m, ai, bi, q, ui, vi;
vector <int> g[MAXN];

int tt, par[MAXN][20], depth[MAXN], li[MAXN], ri[MAXN];
void dfs(int u){
	for(int j = 1; j < 20; j++){
		if(par[u][j - 1] == -1)par[u][j] = -1;
		else par[u][j] = par[par[u][j - 1]][j - 1];
	}
	
	li[u] = ri[u] = tt++;

	for(int v : g[u]){
		par[v][0] = u;
		depth[v] = depth[u] + 1;
		
		dfs(v);
		ri[u] = ri[v];
	}
}

int lca(int u, int v){
	if(depth[u] < depth[v])swap(u, v);
	
	for(int d = 19; d >= 0; d--){
		if(depth[u] - (1 << d) >= depth[v]){
			u = par[u][d];
		}
	}
	
	if(u == v)return u;
	
	for(int d = 19; d >= 0; d--){
		if(par[u][d] != par[v][d]){
			u = par[u][d];
			v = par[v][d];
		}
	}
	return par[u][0];
}

vector <int> add[MAXN], rem[MAXN];
multiset <int> s2[MAXN];
int up[MAXN][20];

int kthpar(int u, int k){
	for(int j = 19; j >= 0; j--)if(k & (1 << j)){
		u = par[u][j];
	}
	return u;
}
void dfs2(int u){
	for(int v : g[u]){
		dfs2(v);
		
		if(s2[v].size() > s2[u].size())swap(s2[u], s2[v]);
		
		for(int x : s2[v])
			s2[u].insert(x);
	}
	
	for(int x : add[u])
		s2[u].insert(x);
	for(int x : rem[u]){
		s2[u].erase(s2[u].lower_bound(x));
		s2[u].erase(s2[u].lower_bound(x));
	}
		
	if(s2[u].empty())up[u][0] = depth[u];
	else up[u][0] = *s2[u].begin();
}

struct query{
	int l, r, index, sign;
	query(int l, int r, int index, int sign): l(l), r(r), index(index), sign(sign){}
};

int ans[MAXN], cnt[MAXN];
bool upd[MAXN];
vector < pair <int, int> > evs;
vector <query> qi[MAXN];

int tree[MAXN];
void tadd(int u){
	u++;
	
	while(u < MAXN){
		tree[u]++;
		u += u & (-u);
	}
}
int tsum(int u){
	u++;
	
	int r = 0;
	while(u > 0){
		r += tree[u];
		u -= u & (-u);
	}
	return r;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d", &pi);
		g[pi - 1].push_back(i);
	}
	
	par[0][0] = -1;
	dfs(0);
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &ai, &bi);
		ai--, bi--;
		
		int l = lca(ai, bi);
		add[ai].push_back(depth[l]);
		add[bi].push_back(depth[l]);
		
		rem[l].push_back(depth[l]);
		
		evs.push_back(make_pair(min(li[ai], li[bi]), max(li[ai], li[bi])));
	}
	sort(evs.begin(), evs.end());
	
	dfs2(0);
	
	for(int j = 1; j < 20; j++)
	for(int i = 0; i < n; i++)
		up[i][j] = up[kthpar(i, depth[i] - up[i][j - 1])][j - 1];
	
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		scanf("%d %d", &ui, &vi);
		ui--, vi--;
		
		if(depth[ui] < depth[vi])swap(ui, vi);
		
		if(li[vi] <= li[ui] && li[ui] <= ri[vi]){
			int res = 0;
			for(int d = 19; d >= 0; d--){
				if(up[ui][d] > depth[vi]){
					ui = kthpar(ui, depth[ui] - up[ui][d]);
					res += 1 << d;
				}
			}
			
			if(up[ui][0] <= depth[vi])ans[i] = res + 1;
			else ans[i] = -1;
		}else{
			int l = lca(ui, vi);
			
			int res = 0;
			for(int d = 19; d >= 0; d--){
				if(up[ui][d] > depth[l]){
					ui = kthpar(ui, depth[ui] - up[ui][d]);
					res += 1 << d;
				}
			}
			for(int d = 19; d >= 0; d--){
				if(up[vi][d] > depth[l]){
					vi = kthpar(vi, depth[vi] - up[vi][d]);
					res += 1 << d;
				}
			}
			
			if(up[ui][0] <= depth[l] && up[vi][0] <= depth[l]){
				ans[i] = res + 1;
				
				if(li[ui] > li[vi])swap(ui, vi);
				
				qi[ri[ui]].push_back(query(li[vi], ri[vi], i, 1));
				if(li[ui] > 0)qi[li[ui] - 1].push_back(query(li[vi], ri[vi], i, -1));
				
				upd[i] = true;
			}else{
				ans[i] = -1;
			}
		}
	}
	
	for(int i = 0, j = 0; i < n; i++){
		while(j < (int)evs.size() && evs[j].first <= i){
			tadd(evs[j].second);
			j++;
		}
		
		for(query q : qi[i]){
			cnt[q.index] += q.sign * (tsum(q.r) - tsum(q.l - 1));
		}
	}
	
	for(int i = 0; i < q; i++){
		if(upd[i])printf("%d\n", ans[i] + (cnt[i] == 0));
		else printf("%d\n", ans[i]);
	}
	
	return 0;
}