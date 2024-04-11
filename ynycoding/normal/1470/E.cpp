#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define mp std::make_pair
using std::pair;
const int N=30005, K=5;
int T, n, c, q, p[N], id[N], stk[K][2], top;
ll le[N][K], tot[N][K], res;
pair<int, ll> decide(int x, int c, ll res)
{
	for(int i=x; i>=x-c&&i; --i)
		id[x-i+1]=i;
	std::sort(id+1, id+std::min(x, c+1)+1, [] (int x, int y) { return p[x]<p[y]; } );
	auto ret=mp(0, 0ll);
	for(int i=1; i<=std::min(x, c+1); ++i)
	{
		int y=id[i];
		ll v=tot[y-1][c-(x-y)];
		if(res>v) ret.second+=v, res-=v;
		else
		{
			ret.first=y;
			return ret;
		}
	}
	return mp(-1, 0ll);
}
inline int adv(int x, ll &res, int &c)
{
	int l=0, r=x;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(le[x][c]-le[mid-1][c]>=res||le[x][c]-le[mid-1][c]+tot[mid-1][c]<res) l=mid;
		else r=mid-1;
	}
	if(!l) return 0;
	res-=le[x][c]-le[l][c];
	auto t=decide(l, c, res);
	auto [x1, y1]=t;
	if(x1<0) return -1;
	stk[++top][0]=l, stk[top][1]=x1;
	res-=y1;
	c-=l-x1;
	return x1;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &c, &q);
		for(int i=1; i<=n; ++i) scanf("%d", p+i);
		std::reverse(p+1, p+n+1);
		for(int i=0; i<=c; ++i) tot[0][i]=1;
		for(int i=1; i<=n; ++i)
		{
			memset(tot[i], 0, sizeof(tot[i]));
			memset(le[i], 0, sizeof(le[i]));
			for(int j=0; j<=c; ++j) for(int t=0; t+j<=c&&t<i; ++t)
				tot[i][t+j]+=tot[i-t-1][j];
		}
		for(int i=1; i<=n; ++i)
		{
			for(int t=1; t<=c; ++t)
				for(int j=i-1; j>=i-t&&j; --j) if(p[j]<p[i])
				{
					le[i][t]+=tot[j-1][t-(i-j)];
				}
		}
		for(int i=1; i<=n; ++i) for(int j=0; j<=c; ++j)
			le[i][j]+=le[i-1][j];
		for(int i=1, x, y, rc; i<=q; ++i)
		{
			scanf("%d%lld", &y, &res);
			y=n-y+1;
			x=n;
			rc=c;
			top=0;
			while(1)
			{
				x=adv(x, res, rc);
				if(x==-1) { puts("-1"); goto out; }
				if(!x) break;
				--x;
			}
			for(int i=1; i<=top; ++i) std::reverse(p+stk[i][1], p+stk[i][0]+1);
			printf("%d\n", p[y]);
			for(int i=1; i<=top; ++i) std::reverse(p+stk[i][1], p+stk[i][0]+1);
			out:;
		}
	}
	return 0;
}