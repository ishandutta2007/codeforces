#include <cstdio>
#include <cstdlib>
#include <vector>
#define mp std::make_pair
#define x first
#define y second
#define N 2505
#define ll long long
using std::pair;
int n, m, q, sum[N][N], x, y, x1, y1;
ll hash[N][N], hs;
inline int lowbit(int x) { return x&(-x); }
inline void add(int x, int y, int v, ll hs)
{ while(x<=n) { for(int i=y; i<=m; i+=lowbit(i)) sum[x][i]+=v, hash[x][i]^=hs; x+=lowbit(x); } }
inline void cover(int v)
{
	hs=x*y+((x1*y1)<<32);
	add(x, y, v, hs), add(x1+1, y, -v, hs), add(x, y1+1, -v, hs), add(x1+1, y1+1, v, hs);
}
inline pair<int, ll> query(int x, int y)
{
	pair<int, ll> ret(0, 0);
	while(x) { for(int i=y; i; i-=lowbit(i)) ret.x+=sum[x][i], ret.y^=hash[x][i]; x-=lowbit(x); }
	return ret;
}
int main()
{
	srand(19260817);
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1, t; i<=q; ++i)
	{
		scanf("%d%d%d%d%d", &t, &x, &y, &x1, &y1);
		if(t==1) cover(1);
		if(t==2) cover(-1);
		if(t==3)
		{
			pair<int, ll> t1=query(x, y), t2=query(x1, y1);
			puts(t1.x==t2.x&&t1.y==t2.y?"Yes":"No");
		}
	}
	return 0;
}