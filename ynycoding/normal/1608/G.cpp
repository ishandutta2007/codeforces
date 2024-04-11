#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define pb push_back
using std::vector;
using std::pair;
const int N=200005;
int n, m, q, x[N], y[N];
int s[N];
int posl[N], posr[N], sa[N], rk[N], id[N], cnt[N], rid[N], dep[N], top;
int al[N], ar[N], rans[N];
int sum[N], tot;
vector<pair<int, int> > e[N];
vector<int> qr[N];
inline void add(int p, int v) { while(p<=tot) sum[p]+=v, p+=p&(-p);}
inline int ask(int p) { int ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
void SA(int n)
{
	for(int i=1; i<=n; ++i) ++cnt[s[i]];
	int m=27;
	for(int i=1; i<=m; ++i) cnt[i]+=cnt[i-1];
	for(int i=1; i<=n; ++i) sa[cnt[rk[i]=s[i]]--]=i;
	for(int len=1; len==1||m!=n; len<<=1)
	{
		top=0;
		for(int i=n-len+1; i<=n; ++i) id[++top]=i;
		for(int i=1; i<=n; ++i) if(sa[i]>len) id[++top]=sa[i]-len;
		std::fill(cnt, cnt+m+1, 0);
		for(int i=1; i<=n; ++i) ++cnt[rk[i]], rid[i]=rk[id[i]];
		for(int i=1; i<=m; ++i) cnt[i]+=cnt[i-1];
		for(int i=top; i; --i) sa[cnt[rid[i]]--]=id[i];
		std::copy(rk+1, rk+n+1, rid+1);
		auto cmp=[&] (int x, int y) { return rid[x]==rid[y]&&(x+len>n?0:rid[x+len])==(y+len>n?0:rid[y+len]); };
		m=0;
		for(int i=1; i<=n; ++i)
		{
			if(i==1||!cmp(sa[i-1], sa[i])) ++m;
			rk[sa[i]]=m;
		}
	}
}
int ul[N][20], ur[N][20], dl[N][20], dr[N][20], pa[N][20];
inline bool cmple(int xl, int xr, int y, int p, int len)
{
	return (xl<=rk[p]&&rk[p]<=xr)?y<=(p+len>tot?0:rk[p+len]):xl<rk[p];
}
inline void merge(int xl, int xr, int yl, int yr, int len, int &x, int &y)
{
	int l=0, r=tot;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(cmple(xl, xr, yl, sa[mid], len)) r=mid-1;
		else l=mid;
	}
	x=l+1;
	r=tot;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(cmple(xl, xr, yr+1, sa[mid], len)) r=mid-1;
		else l=mid;
	}
	y=l;
}
void dfs(int u, int fa, int w)
{
	pa[u][0]=fa;
	dep[u]=dep[fa]+1;
	ul[u][0]=dl[u][0]=al[w], ur[u][0]=dr[u][0]=ar[w];
	for(int i=1; (1<<i)<=n; ++i)
	{
		pa[u][i]=pa[pa[u][i-1]][i-1];
		if(!pa[u][i]) break;
		merge(ul[u][i-1], ur[u][i-1], ul[pa[u][i-1]][i-1], ur[pa[u][i-1]][i-1], (1<<(i-1)), ul[u][i], ur[u][i]);
		int len=1<<(i-1);
		merge(dl[pa[u][i-1]][i-1], dr[pa[u][i-1]][i-1], dl[u][i-1], dr[u][i-1], len, dl[u][i], dr[u][i]);
	}
	for(auto [v, c]:e[u]) if(v!=fa)
	{
		dfs(v, u, c);
	}
}
inline int lca(int x, int y)
{
	if(dep[x]<dep[y]) std::swap(x, y);
	for(int i=19; ~i; --i) if(dep[pa[x][i]]>=dep[y])
		x=pa[x][i];
	if(x==y) return x;
	for(int i=19; ~i; --i) if(pa[x][i]!=pa[y][i])
		x=pa[x][i], y=pa[y][i];
	return pa[x][0];
}
void find(int x, int y, int &cl, int &cr)
{
	int l=lca(x, y);
	int xl=0, xr=tot, yl=0, yr=tot;
	int cur=0;
	for(int i=19; ~i; --i) if(dep[pa[x][i]]>=dep[l])
	{
		merge(xl, xr, ul[x][i], ur[x][i], cur, xl, xr);
		cur|=(1<<i);
		x=pa[x][i];
	}
	for(int i=19; ~i; --i) if(dep[pa[y][i]]>=dep[l])
	{
		merge(dl[y][i], dr[y][i], yl, yr, 1<<i, yl, yr); 
		y=pa[y][i];
	}
	merge(xl, xr, yl, yr, cur, cl, cr);
}
char t[N];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1, x, y; i<n; ++i)
	{
		scanf("%d%d%s", &x, &y, t);
		e[x].pb({y, t[0]-'a'+1});
		e[y].pb({x, t[0]-'a'+1});
	}
	for(int i=1; i<=m; ++i)
	{
		scanf("%s", t+1);
		int len=strlen(t+1);
		for(int i=1; i<=len; ++i) s[tot+i]=t[i]-'a'+1;
		posl[i]=tot+1, posr[i]=tot+len;
		s[tot+len+1]=27;
		tot+=len+1;
	}
	SA(tot);
	for(int i=0; i<=19; ++i) ur[0][i]=dr[0][i]=tot;
	ar[0]=tot;
	std::fill(al+1, al+27+1, tot+1);
	for(int i=1; i<=tot; ++i) if(s[i]<=26)
	{
		al[s[i]]=std::min(al[s[i]], rk[i]);
		ar[s[i]]=std::max(ar[s[i]], rk[i]);
	}
	dfs(1, 0, 0);
	for(int i=1, l, r; i<=q; ++i)
	{
		scanf("%d%d%d%d", x+i, y+i, &l, &r);
		qr[l-1].pb(-i);
		qr[r].pb(i);
	}
	for(int i=1; i<=m; ++i)
	{
		int l, r;
		for(int j=posl[i]; j<=posr[i]; ++j) add(rk[j], 1);
		for(int _x:qr[i])
		{
			int x=std::abs(_x);
			find(::x[x], y[x], l, r);
			int v=ask(r)-ask(l-1);
			if(_x<0) rans[x]-=v;
			else rans[x]+=v;
		}
	}
	for(int i=1; i<=q; ++i) printf("%d\n", rans[i]);
	return 0;
}