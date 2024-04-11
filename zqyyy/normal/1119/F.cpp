#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
const int N=250007;
int n, now, deg[N], id[N], vis[N];
ll f[N][2];
vector<pair<int, int> >G[N];
struct Heap {
	priority_queue<ll>q1, q2; ll sum;
	inline void push(ll x) {sum+=x, q1.push(x);}
	inline void erase(ll x) {sum-=x, q2.push(x);}
	inline void upd() {while (!q2.empty() && q1.top()==q2.top()) q1.pop(), q2.pop();}
	inline ll top() {return upd(), q1.top();}
	inline void pop() {return sum-=top(), q1.pop();}
	inline bool empty() {return upd(), q1.empty();}
	inline int size() {return q1.size()-q2.size();}
}q[N];
void dfs(int x, int fa) {
	vis[x]=now;
	while (!G[x].empty() && deg[G[x].back().fi]<=now)
		q[x].push(G[x].back().se), G[x].pop_back();
	vector<ll>tmp, del;
	int num=deg[x]-now; ll sum=0;
	while (q[x].size()>num) q[x].pop();
	for (auto &[y, w]:G[x]) {
		if (y==fa) continue;
		dfs(y, x); ll v=f[y][1]+w-f[y][0];
		if (v<=0) num--, sum+=f[y][1]+w;
		else sum+=f[y][0], q[x].push(v), del.push_back(v);
	}
	while (!q[x].empty() && q[x].size()>num) tmp.push_back(q[x].top()), q[x].pop();
	f[x][0]=q[x].sum+sum;
	while (!q[x].empty() && q[x].size()>num-1) tmp.push_back(q[x].top()), q[x].pop();
	f[x][1]=q[x].sum+sum;
	for (ll v:tmp) q[x].push(v); for (ll v:del) q[x].erase(v);
}
int main() {
#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=read(); ll ans0=0;
	for (int i=1; i<n; i++) {
		int x=read(), y=read(), w=read(); ans0+=w;
		G[x].push_back({y, w}), G[y].push_back({x, w}), deg[x]++, deg[y]++;
	}
	iota(id+1, id+n+1, 1), sort (id+1, id+n+1, [&](int x, int y) {return deg[x]<deg[y];});
	for (int i=1; i<=n; i++)
		sort (G[i].begin(), G[i].end(), [](auto x, auto y) {return deg[x.fi]>deg[y.fi];});
	printf("%lld ", ans0); int pos=1;
	for (now=1; now<n; now++) {
		while (pos<=n && deg[id[pos]]<=now) pos++;
		ll ans=0;
		for (int i=pos; i<=n; i++) {
			int x=id[i];
			if (vis[x]==now) continue;
			dfs(x, 0), ans+=f[x][0];
		}
		printf("%lld%c", ans, " \n"[now==n-1]);
	}
	return 0;
}