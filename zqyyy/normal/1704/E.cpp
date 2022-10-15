#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=1007, mod=998244353;
int n, m, deg[N];
vector<int>G[N];
set<pair<ll, ll> >s[N];
inline void clear() {
	for (int i=1; i<=n; i++) G[i].clear(), s[i].clear(), deg[i]=0;
}
inline void insert(set<pair<ll, ll> >&s, pair<ll, ll> tmp) {
	auto it=s.lower_bound(tmp);
	if (it!=s.begin()) {
		auto t=prev(it);
		if (t->se>=tmp.fi) it=t;
	}
	if (it!=s.end()) {
		ll len=tmp.se-tmp.fi, l=min(it->fi, tmp.fi);
		while (true) {
			len+=it->se-it->fi, s.erase(it++);
			if (it==s.end() || l+len<it->fi) break;
		}
		s.insert({l, l+len});
	} else s.insert(tmp);
}
inline void work() {
	n=read(), m=read();
	for (int i=1; i<=n; i++) {
		int x=read();
		if (x) s[i].insert({0ll, x});
	}
	for (int i=1; i<=m; i++) {
		int x=read(), y=read();
		G[x].push_back(y), deg[y]++;
	}
	queue<int>q;
	for (int i=1; i<=n; i++) if (!deg[i]) q.push(i);
	while (!q.empty()) {
		int x=q.front(); q.pop();
		if (!G[x].size()) {
			if (!s[x].empty()) printf("%d\n", (int)(s[x].rbegin()->se%mod));
			else puts("0");
			return;
		}
		vector<pair<ll, ll> >vec;
		for (auto t:s[x]) vec.push_back({t.fi+1, t.se+1});
		for (int y:G[x]) {
			for (auto t:vec) insert(s[y], t);
			if (!--deg[y]) q.push(y);
		}
	}
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	int test=read();
	while (test--) work(), clear();
	return 0;
}