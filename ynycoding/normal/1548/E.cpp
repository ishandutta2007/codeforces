#include <cstdio>
#include <algorithm>
#define ll long long
const int N=200005;
int n, m, X, a[N], b[N], ra[N], rb[N], id[N], id1[N], mx[N], mx1[N], stk[N], val[N], top;
int rk[N], rk1[N];
ll ans;
void proc(int n, int *a, int *mx)
{
	top=0;
	val[0]=0x3f3f3f3f;
	for(int i=1; i<=n; ++i)
	{
		while(top&&a[stk[top]]>a[i])
		{
			mx[stk[top]]=std::min(val[top-1], val[top]), --top;
			val[top]=std::max(a[stk[top+1]], std::max(val[top], val[top+1]));
		}
		stk[++top]=i;
		val[top]=0;
	}
	while(top) mx[stk[top]]=val[top-1], --top;
}
int sum[N], sum1[N];
inline void add(int p) { while(p<=n) ++sum[p], p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
inline void add1(int p) { while(p<=m) ++sum1[p], p+=p&(-p); }
inline int ask1(int p) { int ret=0; while(p) ret+=sum1[p], p-=p&(-p); return ret; }
int main()
{
	scanf("%d%d%d", &n, &m, &X);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), mx[i]=a[i], id[i]=i;
	for(int i=1; i<=m; ++i) scanf("%d", b+i), mx1[i]=b[i], id1[i]=i;
	proc(n, a, mx);
	proc(m, b, mx1);
	
	std::sort(id+1, id+n+1, [] (int x, int y) { return a[x]<a[y]; });
	for(int i=1; i<=n; ++i) rk[id[i]]=i, ra[i]=a[id[i]];
	std::sort(id1+1, id1+m+1, [] (int x, int y) { return b[x]<b[y]; });
	for(int i=1; i<=m; ++i) rk1[id1[i]]=i, rb[i]=b[id1[i]];
	
	for(int i=1; i<=n; ++i) mx[i]-=a[i];
	for(int i=1; i<=m; ++i) mx1[i]-=b[i];
	std::sort(id+1, id+n+1, [] (int x, int y) { return mx[x]>mx[y]; });
	std::sort(id1+1, id1+m+1, [] (int x, int y) { return mx1[x]>mx1[y]; });
	
	int l=0, r=0;
	while(l<n||r<m)
	{
		int x=id[l+1], y=id1[r+1];
		if(l<n&&(r==m||mx[x]>mx1[y]))
		{
			int lw=X-mx[x]-a[x]+1, up=X-a[x];
			if(lw<=up)
			{
				int l=std::lower_bound(rb+1, rb+m+1, lw)-rb, r=std::upper_bound(rb+1, rb+m+1, up)-rb-1;
				ans+=ask1(r)-ask1(l-1);
			}
			add(rk[x]);
			++l;
		}
		else
		{
			int lw=X-mx1[y]-b[y]+1, up=X-b[y];
			if(lw<=up)
			{
				int l=std::lower_bound(ra+1, ra+n+1, lw)-ra, r=std::upper_bound(ra+1, ra+n+1, up)-ra-1;
				ans+=ask(r)-ask(l-1);
			}
			add1(rk1[y]);
			++r;
		}
	}
	printf("%lld\n", ans);
	return 0;
}