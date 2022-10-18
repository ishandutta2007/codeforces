#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
using std::vector;
const int N=200005, M=1000005;
int n, q, p[N], rp[N], ql[M];
ll rans[M];
vector<int> qr[N];
struct BIT{
	ll sum[N];
	inline void add(int p, ll v) { while(p<=n) sum[p]+=v, p+=p&(-p); }
	inline ll ask(int p) { ll ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
};
struct RBIT{
	BIT A, B;
	inline void add(int x, ll v)
	{
		// printf("add %d\n", x);
		A.add(x, v), B.add(x, v*x);
	}
	inline ll ask(int p)
	{
		// printf("ask %d\n", p);
		return 1ll*(p+1)*A.ask(p)-B.ask(p);
	}
}A, B;
int stk[N], pos[N], l[N], top;
int cx;
inline void add(int l, int r, int v)
{
	A.add(l, v), A.add(r+1, -v);
	B.add(l, 1ll*cx*v), B.add(r+1, -1ll*cx*v);
}
int is[N];
int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1, x; i<=n; ++i) scanf("%d", p+i), rp[p[i]]=i;
	for(int i=1, l, r; i<=q; ++i)
	{
		scanf("%d%d", &l, &r);
		ql[i]=l;
		qr[r].pb(i);
	}
	for(int i=1; i<=n; ++i)
	{
		cx=i-1;
		while(top&&stk[top]<p[i])
		{
			add(pos[top-1]+1, l[pos[top]], -1);
			is[pos[top]]=0;
			--top;
		}
		if(l[i]>pos[top]) add(pos[top]+1, l[i], 1);
		else l[i]=pos[top];
		is[i]=1;
		stk[++top]=p[i], pos[top]=i;
		for(int j=1; j*p[i]<=n; ++j) if(rp[j]<i)
		{
			int x=rp[j], y=rp[j*p[i]];
			int v=std::min(x, y);
			if(l[y]<v)
			{
				if(is[y]) add(l[y]+1, v, 1);
				l[y]=v;
			}
		}
		for(int x:qr[i])
		{
			rans[x]=(A.ask(i)-A.ask(ql[x]-1))*i-(B.ask(i)-B.ask(ql[x]-1));
		}
	}
	for(int i=1; i<=q; ++i) printf("%lld\n", rans[i]);
	return 0;
}