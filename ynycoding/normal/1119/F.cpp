#include <cstdio>
#include <random>
#include <vector>
#include <set>
#include <assert.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define mp std::make_pair
#define x first
#define y second
#define pb push_back
#define ll long long
using std::pair;
using std::vector;
using namespace __gnu_pbds;
const int N=500005;
namespace Treap{
	std::mt19937 rnd(114514);
	int rt, val[N], sz[N], ch[N][2], key[N], top;
	ll sum[N];
	#define ls ch[u][0]
	#define rs ch[u][1]
	inline int newnode(int v) { return val[++top]=v, key[top]=rnd(), sum[top]=v, sz[top]=1, ch[top][0]=ch[top][1]=0, top; }
	inline void upt(int u) { sum[u]=sum[ls]+sum[rs]+val[u], sz[u]=sz[ls]+sz[rs]+1; }
	int merge(int x, int y)
	{
		if(!x||!y) return x|y;
		int u;
		if(key[x]>key[y])
		{
			u=x;
			rs=merge(rs, y);
		}
		else
		{
			u=y;
			ls=merge(x, ls);
		}
		upt(u);
		return u;
	}
	void split(int u, int &x, int &y, int v)
	{
		if(!u) { x=y=0; return; }
		if(val[u]<=v)
		{
			x=u;
			split(rs, rs, y, v);
		}
		else
		{
			y=u;
			split(ls, x, ls, v);
		}
		upt(u);
	}
	ll ask(int u, int k)
	{
		if(!u) return 0;
		if(sz[ls]+1==k) return sum[ls]+val[u];
		if(sz[ls]>=k) return ask(ls, k);
		return ask(rs, k-sz[ls]-1)+sum[ls]+val[u];
	}
	inline void insert(int v)
	{
		int x, y;
		split(rt, x, y, v);
		x=merge(x, newnode(v));
		rt=merge(x, y);
	}
	inline void del(int v)
	{
		int x, y, z;
		split(rt, x, y, v-1);
		split(y, y, z, v);
		y=merge(ch[y][0], ch[y][1]);
		rt=merge(x, y);
		rt=merge(rt, z);
	}
	inline void clr(void) { rt=top=0; }
}
using Treap::clr;
using Treap::insert;
using Treap::del;
using Treap::rt;
using Treap::ask;
int deg[N], cid[N], cw[N], lim;
ll cans[N];
ll ans[N], sum[N];
vector<pair<int, int> > e[N], edeg[N];
vector<int> rw[N];
void dfs(int u, int fa, int fw)
{
	deg[u]=e[u].size();
	std::sort(e[u].begin(), e[u].end());
	for(auto t:e[u])
	{
		int v=t.y;
		if(v==fa) { edeg[u].pb(mp(deg[v], v)); continue; }
		dfs(v, u, t.x);
		edeg[u].pb(mp(deg[v], v));
	}
	std::sort(edeg[u].begin(), edeg[u].end());
	std::fill(sum, sum+lim+1, 0);
	clr();
	int fdeg=deg[fa];
	for(int i=0; i<deg[u]; ++i)
	{
		auto t=e[u][i];
		int v=t.y;
		if(v==fa) continue;
		cid[v]=i;
		cw[v]=t.x;
		insert(cw[v]);
	}
	rw[u].resize(deg[u]);
	for(int i=deg[u]-1; (fa?i:~i); --i)
	{
		for(int j=deg[u]-1; ~j; --j)
		{
			auto t=edeg[u][j];
			if(t.x<=i) break;
			int v=t.y;
			if(v==fa) continue;
			del(cw[v]);
			cw[v]=rw[v][i];
			insert(cw[v]);
		}
		ll x=ask(rt, deg[u]-i), y=ask(rt, deg[u]-i-1);
		if(i>=fdeg) ans[i]+=(fa?std::min(x, y+fw):x);
		else
		{
			ans[i]+=(fa?std::min(x, y+fw):x);
			rw[u][i]=std::max(0ll, y+fw-x);
		}
	}
	if(fa) cans[0]=cans[1]+fw;
}
vector<ll> minimum_closure_costs(int n, vector<int> x, vector<int> y, vector<int> w)
{
	ll t=0;
	for(int i=0; i<n-1; ++i) e[x[i]].pb(mp(w[i], y[i])), e[y[i]].pb(mp(w[i], x[i])), t+=w[i];
	dfs(1, 0, 0);
	vector<ll> ret;
	ans[0]=t;
	for(int i=0; i<n; ++i) ret.pb(ans[i]);
	return ret;
}
int n;
vector<int> x, y, w;
int main()
{
	scanf("%d", &n);
	x.resize(n-1), y.resize(n-1), w.resize(n-1);
	for(int i=0; i<n-1; ++i) scanf("%d%d%d", x.data()+i, y.data()+i, w.data()+i);
	vector<ll> f=minimum_closure_costs(n, x, y, w);
	for(int i=0; i<n; ++i) printf("%lld\n", f[i]);
	return 0;
}