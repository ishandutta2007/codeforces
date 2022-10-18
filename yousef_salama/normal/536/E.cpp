#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, q, f[MAXN];

struct node{
	int score, maxpref, maxsuf, size;
};

node make_node(int a, int b, int c, int d){
	return {a, b, c, d};
}
node operator +(node a, node b){
	node c;

	c.score = a.score + b.score - f[a.maxsuf] - f[b.maxpref] + f[a.maxsuf + b.maxpref];

	if(a.maxpref == a.size)c.maxpref = a.size + b.maxpref;
	else c.maxpref = a.maxpref;

	if(b.maxsuf == b.size)c.maxsuf = a.maxsuf + b.size;
	else c.maxsuf = b.maxsuf;

	c.size = a.size + b.size;

	return c;
}

node tree[4 * MAXN];
void init_tree(int i, int L, int R){
	if(L == R){
		tree[i] = {0, 0, 0, 1};
		return;
	}

	int mid = (L + R) / 2;
	init_tree(2 * i, L, mid);
	init_tree(2 * i + 1, mid + 1, R);
	tree[i] = tree[2 * i] + tree[2 * i + 1];
}
void update(int i, int L, int R, int p){
	if(p < L || R < p)return;
	if(L == R){
		tree[i] = {f[1], 1, 1, 1};
		return;
	}

	int mid = (L + R) / 2;
	update(2 * i, L, mid, p);
	update(2 * i + 1, mid + 1, R, p);
	tree[i] = tree[2 * i] + tree[2 * i + 1];
}
node query(int i, int L, int R, int p, int q){
	if(q < p)return {0, 0, 0, 0};

	if(q < L || R < p)return {0, 0, 0, 0};
	if(p <= L && R <= q)return tree[i];

	int mid = (L + R) / 2;
	return query(2 * i, L, mid, p, q) + query(2 * i + 1, mid + 1, R, p, q);
}

struct path{
	int index, u, v, w;
};
bool operator <(path a, path b){
	if(a.w != b.w)return a.w < b.w;
	else return a.index < b.index;
}

int res[MAXN];
path edges[MAXN], queries[MAXN];

vector <int> G[MAXN];
int sz[MAXN], parent[MAXN];
void dfs_sz(int u, int par = -1){
	sz[u] = 1;
	parent[u] = par;

	for(int &v : G[u]){
		if(v == par)continue;

		dfs_sz(v, u);
		sz[u] += sz[v];

		if(G[u][0] == par || sz[v] > G[u][0])swap(v, G[u][0]);
	}
}

int mtime, up[MAXN], Ltime[MAXN], Rtime[MAXN];
void dfs_hld(int u, int par = -1){
	Ltime[u] = Rtime[u] = mtime++;
	for(int v : G[u]){
		if(v == par)continue;

		if(v == G[u][0])up[v] = up[u];
		else up[v] = v;

		dfs_hld(v, u);
		Rtime[u] = Rtime[v];
	}
}

int s[MAXN];
int main(){
	scanf("%d %d", &n, &q);

	f[0] = 0;
	for(int i = 1; i < n; i++)
		scanf("%d", &f[i]);

	for(int i = 0; i < n - 1; i++){
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
		edges[i].u--, edges[i].v--;

		G[edges[i].u].push_back(edges[i].v);
		G[edges[i].v].push_back(edges[i].u);

		edges[i].index = i;
	}
	sort(edges, edges + n - 1);

	for(int i = 0; i < q; i++){
		scanf("%d %d %d", &queries[i].u, &queries[i].v, &queries[i].w);
		queries[i].u--, queries[i].v--;

		queries[i].index = i;
	}
	sort(queries, queries + q);

	dfs_sz(0);

	mtime = 0;
	up[0] = 0;
	dfs_hld(0);

	init_tree(1, 0, n - 1);
	memset(s, 0, sizeof s);

	int j = n - 2;
	for(int i = q - 1; i >= 0; i--){
		while(j >= 0 && edges[j].w >= queries[i].w){
			if(Ltime[edges[j].u] > Ltime[edges[j].v])
				swap(edges[j].u, edges[j].v);

			s[edges[j].v] = 1;
			update(1, 0, n - 1, Ltime[edges[j].v]);
			j--;
		}

		node a = {0, 0, 0, 0};
		node b = {0, 0, 0, 0};

		int u = queries[i].u, v = queries[i].v;
		while(true){
			if(Ltime[up[u]] <= Ltime[v] && Rtime[v] <= Rtime[up[u]]){
				break;
			}else{
				a = query(1, 0, n - 1, Ltime[up[u]] + 1, Ltime[u]) + a;
				a = make_node(f[s[up[u]]], s[up[u]], s[up[u]], 1) + a;

				u = parent[up[u]];
			}
		}

		while(up[v] != up[u]){
			b = query(1, 0, n - 1, Ltime[up[v]] + 1, Ltime[v]) + b;
			b = make_node(f[s[up[v]]], s[up[v]], s[up[v]], 1) + b;

			v = parent[up[v]];
		}

		if(Ltime[u] < Ltime[v]){
			b = query(1, 0, n - 1, Ltime[u] + 1, Ltime[v]) + b;
		}else{
			a = query(1, 0, n - 1, Ltime[v] + 1, Ltime[u]) + a;
		}
		swap(a.maxpref, a.maxsuf);

		res[queries[i].index] = (a + b).score;
	}

	for(int i = 0; i < q; i++)
		printf("%d\n", res[i]);

	return 0;
}