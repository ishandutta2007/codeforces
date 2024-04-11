#include <cstdio>
#include <vector>
#include <assert.h>
#include <bitset>
#include <algorithm>
#define pb push_back
using std::vector;
using std::bitset;
const int N=105, MOD=998244353;
int n, m, sz[N], fac[N], inv[N], id[N];
bitset<N> q[N];
vector<bitset<N> > v;
bitset<N> U;
inline int solve(bitset<N> v, vector<bitset<N> > q, int cnt, int ok)
{
	if(!v.count()) return 1;
	if(q.empty()) return ok?1ll*fac[v.count()]*(cnt+1)%MOD:1ll*fac[v.count()+cnt]*inv[cnt]%MOD;
	vector<bitset<N> > e;
	e.pb((*q.rbegin())&v);
	q.pop_back();
	while(1)
	{
		bool ok=0;
		vector<bitset<N> > buff;
		for(auto &x:q)
		{
			int l=0;
			while(l<e.size()&&(e[l]&x).none()) ++l;
			if(l==e.size()) continue;
			if((e[l]&x)==x) continue;
			int r=l+1;
			bitset<N> tmp;
			tmp=e[l];
			while(r<e.size()&&(e[r]&x)==e[r]) tmp|=e[r], ++r;
			if(r!=e.size()) tmp|=e[r];
			tmp&=x;
			if(l==r&&(e[r]&x)==x) continue;
			for(int i=r+1; i<e.size(); ++i) if((e[i]&x).any())
				puts("0"), exit(0);
			if(l&&r!=e.size()&&tmp!=x) puts("0"), exit(0);
			if(tmp!=x)
			{
				ok=1;
				if(!l) e.insert(e.begin(), x^tmp), buff.pb(x&tmp);
				else if(r==e.size()) e.pb(x^tmp), buff.pb(x&tmp);
				else puts("0"), exit(0);
				break;
			}
			if(r<e.size()&&(e[r]&x).any())
			{
				auto a=e[r]&x;
				ok=1;
				e[r]^=a;
				assert(e.size()>=r);
				e.insert(e.begin()+r, a);
				break;
			}
			if(l<e.size()&&(e[l]&x)!=e[l])
			{
				auto a=e[l]&x;
				ok=1;
				e[l]^=a;
				assert(e.size()>=l+1);
				e.insert(e.begin()+l+1, a);
				break;
			}
		}
		for(auto &x:buff) q.pb(x);
		if(!ok) break;
	}
	for(auto &x:e) v^=x;
	int ret=1;
	for(auto &x:e)
	{
		vector<bitset<N> > tmp;
		for(auto &y:q) if((x&y).any()&&(x&y)!=x)
			tmp.pb(y);
		ret=1ll*ret*solve(x, tmp, 0, 1)%MOD;
	}
	if(e.size()>1) ret=2ll*ret%MOD;
	vector<bitset<N> > tmp;
	int cok=0;
	for(auto &y:q) if((v&y).any())
	{
		if((v&y)!=v) tmp.pb(y);
		else cok=1;
	}
	ret=1ll*ret*solve(v, tmp, (ok?0:cnt)+1, cok)%MOD;
	ret=1ll*ret*(cnt+1)%MOD;
	return ret;
}
int main()
{
	scanf("%d%d", &n, &m);
	inv[0]=inv[1]=fac[0]=1;
	for(int i=2; i<=n; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=1; i<=n; ++i) fac[i]=1ll*fac[i-1]*i%MOD, inv[i]=1ll*inv[i]*inv[i-1]%MOD;
	for(int i=1; i<=n; ++i) U.set(i);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d", sz+i);
		for(int j=1, x; j<=sz[i]; ++j) scanf("%d", &x), q[i].set(x);
		id[i]=i;
	}
	std::sort(id+1, id+m+1, [] (int x, int y) { return q[x].count()<q[y].count(); });
	for(int i=1; i<=m; ++i) if(q[id[i]].count()<n) v.pb(q[id[i]]);
	printf("%d\n", solve(U, v, 0, 0));
	return 0;
}