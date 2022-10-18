#include <cstdio>
#include <algorithm>
#define x first
#define y second
#define ll long long
using std::pair;
typedef pair<int, int> data;
const int N=100005;
int n, q, a[N], val[N], dis[N], ok1, okn;
data to[40][N][20];
inline data ask(int t, int x, int y)
{
	int l=std::__lg(y-x+1);
	int a=std::min(to[t][x][l].x, to[t][y-(1<<l)+1][l].x);
	int b=std::max(to[t][x][l].y, to[t][y-(1<<l)+1][l].y);
	return {a, b};
}
data operator +(const data &a, const data &b)
{
	return {std::min(a.x, b.x), std::max(a.y, b.y)};
}
void build(void)
{
	for(int t=0; (1ll<<t)<=1ll*n*n; ++t)
	{
		for(int i=1; i<n; ++i)
		{
			int l=std::min(a[i], a[i+1]), r=std::max(a[i], a[i+1])-1;
			if(!t) to[t][i][0]={l, r};
			else
			{
				auto v=to[t-1][i][0];
				to[t][i][0]=ask(t-1, v.x, v.y);
			}
		}
		for(int l=1; (1<<l)<=n; ++l) for(int i=1; i+(1<<l)-1<n; ++i)
			to[t][i][l]=to[t][i][l-1]+to[t][i+(1<<(l-1))][l-1];
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	if(n==1)
	{
		while(q--) puts("0");
		return 0;
	}
	for(int i=1; i<=n; ++i) scanf("%d", a+i), ok1|=(a[i]==1), okn|=(a[i]==n);
	int lim=std::__lg(1ll*n*n);
	build();
	for(int i=1, l, r; i<=q; ++i)
	{
		scanf("%d%d", &l, &r);
		if(l==1&&r==n) { puts("0"); continue; }
		if(!ok1||!okn||l==r) { puts("-1"); continue; }
		--r;
		ll k=0;
		for(int i=lim; ~i; --i)
		{
			auto t=ask(i, l, r);
			if(t.x>1||t.y<n-1) l=t.x, r=t.y, k|=1ll<<i;
		}
		++k;
		printf("%lld\n", (k<=1ll*n*(n-1)/2)?k:-1);
	}
	return 0;
}