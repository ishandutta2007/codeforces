#include <bits/stdc++.h>

using ll = long long;
const int maxn = 1500000 + 7;

std::map<int,std::vector<std::pair<int,int> > > R;

const int mod = 1e9 + 7;
const int lim = 1500000;

int f[maxn],size[maxn],P[maxn],u,v,n,not_prime[maxn],tl,idx,dfn[maxn],ref[maxn],cnt;
std::vector<int>ch[maxn],inc[maxn],dec[maxn];
std::map<int,int>S;

void add(int l,int r,int v) {
	if ( l > r ) return;
	inc[l].push_back(v);
	dec[r].push_back(v);
}

void dfs(int u,int fa) {
	dfn[u] = ++idx; ref[idx] = u;
	size[u] = f[u] = 1;
	for (int v:ch[u]) if (v != fa) { 
		dfs(v,u); size[u] += size[v]; 
		f[u] = (f[u] + (ll) P[size[v]] * f[v] % mod) % mod;
	}
}

void dfs2(int u,int fa,int s = 0) {
	add(1,dfn[u] - 1,f[u]);
	add(dfn[u]+size[u],n,f[u]);
	int sum = ( f[u] + (ll) P[n - size[u]] * s % mod ) % mod;
	for (int v:ch[u]) {
		if (v == fa) continue;
		int g = (sum - (ll) P[size[v]] * f[v] % mod + mod) % mod;
		dfs2(v,u,g);
		add(dfn[v],dfn[v]+size[v]-1,g);
	}
}

void ins(int x) {
	if (S[x] == 0) cnt++;
	S[x] ++;
}

void erz(int x) {
	if (S[x] == 1) cnt--;
	S[x] --;
}

void sieve() {
	for (int i = 2; i <= lim; ++ i) {
		if (!not_prime[i]) P[++tl] = i;
		for (int j = i + i; j <= lim; j += i) not_prime[j] = 1;
	}
}

int main() {
	scanf("%d",&n);
	sieve();
	//printf("%d\n",tl);
	for (int i = 1; i < n; ++ i) {
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	} dfs(1,0); dfs2(1,0);
	int mx = -1, u = 0;
	for (int i = 1; i <= n; ++ i) {
		for (auto x:inc[i]) ins(x);
		if (cnt > mx) { mx = cnt; u = ref[i]; }
//		printf("%d %d\n",ref[i],cnt);
		for (auto x:dec[i]) erz(x);
	} printf("%d",u);
	return 0;
}