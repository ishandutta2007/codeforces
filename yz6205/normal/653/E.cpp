#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
bool checkMax(int& a, int b) { return a<b ? a=b,1 : 0; }
bool checkMin(int& a, int b) { return a>b ? a=b,1 : 0; }
#ifdef __LOCALE__
#define ses(a) cout << #a << "=" << a << ' '
#define see(a) cout << #a << "=" << a << endl
#else
#define ses(a)
#define see(a)
#endif

const int N = 300005;
set <int> e[N];
int n,m,k;

set <int> ava;
int able;

void dfs(int u) {
	queue<int> que; que.push(u); ava.erase(u);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		see(u);
		if (!e[u].count(1)) { able=1; }
		for (set<int>::iterator it = ava.begin(); it!=ava.end(); ) {
			if (e[u].count(*it)) { ++it; }
			else { que.push(*it); ava.erase(*(it++)); } } } }

int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep (i,m) { int u,v; scanf("%d%d",&u,&v); e[u].insert(v); e[v].insert(u); }
	if ( static_cast<int>(e[1].size()) >= n-k ) { puts("impossible"); return 0; }
	for (int i=2;i<=n;i++) { ava.insert(i); }
	int cnt = 0;
	for (int i=2;i<=n;i++) if (ava.count(i)) {
		able=0; cnt++; dfs(i); 
		if (able == 0) { puts("impossible"); return 0; } }
	puts( cnt <= k ? "possible" : "impossible" ); 	
	return 0;
}