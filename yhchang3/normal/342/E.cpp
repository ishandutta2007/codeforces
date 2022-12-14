#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010, LOG = 17 + 1;

vector<pair<int,int>> e[maxn];vector<int> vtx;
int gfa[maxn], gdep[maxn], sz[maxn],dis[LOG][maxn], vis[maxn], mx[maxn];
void get_cent(int x) {
	vis[x] = true, vtx.emplace_back(x), sz[x] = 1, mx[x] = 0;
	for(auto &[u,w]:e[x])
		if(!vis[u])
			get_cent(u), mx[x] = max(mx[x], sz[u]), sz[x] += sz[u];
}
void dfs(int x,int d,int Gdep) {
	dis[Gdep][x] = d, vis[x] = true;
	for(auto &[u,w]:e[x])
		if(!vis[u])
			dfs(u,w+d,Gdep);
}
void cent_decomp(int x,int Gfa,int Gdep) {
	get_cent(x);int t = vtx.size();
	for(int i:vtx) {
		if(max(mx[i],t-sz[i]) <= (t >> 1))
			x = i;
		vis[i] = false;
	}
	dfs(x,0,Gdep), gfa[x] = Gfa, gdep[x] = Gdep;
	for(int i:vtx)	vis[i] = false;vtx.clear();vis[x] = true;
	for(auto &[u,w]:e[x])	if(!vis[u])	cent_decomp(u,x,Gdep + 1);
}

int w[maxn];

void modify(int x,int cent,int son,int Gdep) {
	if(Gdep < 0)	return;
	w[cent] = min(w[cent], dis[Gdep][x]);
	modify(x,gfa[cent],cent,Gdep-1);
}

int query(int x,int cent,int son,int Gdep) {
	if(Gdep < 0)	return 1e9;
	return min(query(x,gfa[cent],cent,Gdep-1), dis[Gdep][x] + w[cent]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i=1,x,y;i<n;i++)
		cin >> x >> y, e[x].emplace_back(y,1), e[y].emplace_back(x,1);
	cent_decomp(1,0,0);
	for(int i=1;i<=n;i++)
		w[i] = 1e9;
	modify(1,1,0,gdep[1]);
	while(q--) {
		int op, x;
		cin >> op >> x;
		if(op == 1) {
			modify(x,x,0,gdep[x]);
		}
		else {
			cout << query(x,x,0,gdep[x]) << '\n';
		}
	}
}