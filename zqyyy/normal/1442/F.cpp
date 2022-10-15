#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1007, M=1<<20|7, inf=0x3f3f3f3f;
int n, m, T, tot, seq[N], deg[N], id[N], popcnt[M], vis[M];
set<int>G[N];
vector<tuple<int, int, int> >E;
inline void init() {
	n=read(), m=read(), T=read();
	for (int i=1; i<=m; i++) {
		int x=read(), y=read();
		G[x].insert(y), deg[y]++;
	}
	queue<int>q; for (int i=1; i<=n; i++) if (!deg[i]) q.push(i);
	while (!q.empty()) {
		int x=q.front(); q.pop(), seq[++tot]=x;
		for (int y:G[x]) if (!--deg[y]) q.push(y);
	}
	reverse(seq+1, seq+tot+1), ckmin(tot, min(n, 20)), reverse(seq+1, seq+tot+1);
	for (int i=1; i<=tot; i++) id[seq[i]]=i;
	for (int i=1; i<=tot; i++) {
		int x=seq[i];
		for (int j=1; j<i; j++) {
			int y=seq[j];
			if (G[y].find(x)==G[y].end()) E.push_back({1, y, x}); //y->x j->i
		}
	}
	for (int i=1; i<(1<<tot); i++) popcnt[i]=popcnt[i>>1]+(i&1);
	vector<int>vec(1<<tot); iota(vec.begin(), vec.end(), 0);
	sort(vec.begin(), vec.end(), [&](const int &x, const int &y) {return popcnt[x]<popcnt[y];});
	for (int x=1; x<=n; x++) {
		if (id[x]) continue;
		E.push_back({1, x, x}); int s=0;
		for (int i=1; i<=tot; i++)
			if (G[x].find(seq[i])!=G[x].end()) s|=1<<i-1;
		for (int S:vec) {
			int t=S^s;
			if (vis[t]) continue;
			vis[t]=x;
			for (int i=1; i<=tot; i++)
				if (s>>(i-1)&1) {
					if (~t>>(i-1)&1) E.push_back({0, x, seq[i]});
				} else if (t>>(i-1)&1) E.push_back({1, x, seq[i]});
			break;
		}
	}
	printf("%lu\n", E.size());
	for (auto [op, u, v]:E) printf("%c %d %d\n", op?'+':'-', u, v);
	fflush(stdout);
}
int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	init();
	auto report=[&](int x) {
		cout<<"! "<<x<<endl;
		string s; cin>>s;
		return s[0]=='C';
	};
	while (T--) {
		int S=0;
		for (int i=1; i<=tot; i++) {
			int x=seq[i];
			cout<<"? 1 "<<x<<endl;
			string s; cin>>s;
			if (s[0]=='L') {report(x); goto end;}
			if (s[0]=='W') S|=1<<i-1;
		}
		report(vis[S]);
		end:;
	}
	return 0;
}