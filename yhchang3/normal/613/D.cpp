#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int dfn[maxn], p[maxn][18], dep[maxn], stp;
vector<int> e[maxn];
void dfs(int x,int f) {
	p[x][0] = f, dep[x] = dep[f] + 1;
	dfn[x] = ++stp;
	for(int i=1;i<18;i++)
		p[x][i] = p[p[x][i - 1]][i - 1];
	for(int y:e[x])
		if(y != f)
			dfs(y, x);
}

int LCA(int x,int y) {
	if(dep[x] < dep[y])	swap(x, y);
	int k = dep[x] - dep[y];
	for(int i=17;i>=0;i--)
		if((k >> i) & 1)
			x = p[x][i];
	if(x == y)	return x;
	for(int i=17;i>=0;i--)
		if(p[x][i] != p[y][i])
			x = p[x][i], y = p[y][i];
	return p[x][0];
}

struct VirtualTree {
	int s[maxn], sz = 0;vector<int> G[maxn];
	void reset(int x) {
		for(int it:G[x])
			reset(it);
		vector<int>().swap(G[x]);
	}
	void build(vector<int> &v, int root = 1) {
		sort(v.begin(), v.end(),[&](int x,int y){
			return dfn[x] < dfn[y];	
		});
		sz = 0, s[sz++] = root;
		for(int x:v) {
			if(x == root)	continue;
			int l = LCA(x, s[sz - 1]);
			if(l != s[sz - 1]) {
				while(dfn[l] < dfn[s[sz - 2]])
					G[s[sz-2]].emplace_back(s[sz-1]), sz--;
				G[l].emplace_back(s[--sz]);
				if(s[sz - 1] != l)	s[sz++] = l;
			}
			s[sz++] = x;
		}
		for(int i=0;i<sz-1;i++)
			G[s[i]].emplace_back(s[i+1]);
	}
}VT;

int imp[maxn];


bool check(int x) {
	for(int y:VT.G[x]) {
		if(imp[x] && imp[y] && p[y][0] == x)
			return false;
		if(!check(y))
			return false;
	}
	return true;
}

int c[maxn];
int DP(int x) {
	int res = 0, comp = 0;
	for(int y:VT.G[x])
		res += DP(y), comp += c[y];
	if(imp[x]) {
		res += comp;
		c[x] = 1;
	}
	else if(comp > 1) {
		res++;
		c[x] = 0;
	}
	else {
		c[x] = comp;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1,x,y;i<n;i++)
		cin >> x >> y, e[x].emplace_back(y), e[y].emplace_back(x);
	dfs(1, 0);
	int T;
	cin >> T;
	while(T--) {
		int m;
		cin >> m;
		vector<int> v(m);
		for(int i=0;i<m;i++)
			cin >> v[i], imp[v[i]] = true;
		VT.build(v);
		if(check(1)) {
			cout << DP(1) << '\n';
		}
		else {
			cout << -1 << '\n';
		}
		VT.reset(1);
		for(int i=0;i<m;i++)
			imp[v[i]] = false;
	}
}