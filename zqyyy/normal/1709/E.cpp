#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n, ans, id[N], a[N], d[N];
set<int> s[N];
vector<int> G[N];
void dfs(int x, int fa) {
	d[x]=d[fa]^a[x]; vector<int> son;
	for (int y:G[x])
		if (y^fa) {
			dfs(y, x);
			if (!s[id[y]].empty()) son.push_back(y);
		}
	if (son.empty()) {s[x].insert(d[x]); return;}
	int p=son[0], &b=id[x]; b=id[p];
	for (int y:son) if (s[id[y]].size()>s[b].size()) p=y, b=id[y];
	if (s[b].find(a[x]^d[x])!=s[b].end()) {ans++, s[b].clear(); return;}
	s[b].insert(d[x]);
	for (int y:son) {
		if (y==p) continue;
		for (int v:s[id[y]])
			if (s[b].find(a[x]^v)!=s[b].end()) {ans++, s[b].clear(); return;}
		for (int v:s[id[y]]) s[b].insert(v);
	}
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read();
	for (int i=1; i<=n; i++) a[i]=read(), id[i]=i;
	for (int i=1; i<n; i++) {
		int x=read(), y=read();
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0), printf("%d\n", ans);
	return 0;
}