#include <cstdio>
#include <algorithm>
#include <numeric>
#define ll long long
#define x first
#define y second
#define mp std::make_pair
const int N=205;
using std::pair;
typedef pair<int, int> vec;
namespace Basic{
	auto operator +(const auto &a, const auto &b)
	{
		return mp(a.x+b.x, a.y+b.y);
	}
	auto operator -(const auto &a, const auto &b)
	{
		return mp(a.x-b.x, a.y-b.y);
	}
	auto operator *(const vec &a, const vec &b)
	{
		return 1ll*a.x*b.y-1ll*a.y*b.x;
	}
}
using namespace Basic;
int n, k, pos[N];
ll s[N][N], tot;
vec p[N];
pair<int, ll> f[N][N];
inline int nxt(int x) { return x==n?1:x+1; }
inline int pr(int x) { return  x==1?n:x-1; }
inline int dis(int a, int b) { return a>b?b-a+n:b-a; }
inline void upt(auto &x, auto a) { x=x>a?x:a; }
bool chk(ll c)
{
	std::iota(pos, pos+n+1, 0);
	int T=n-1;
//	if(k==0&&tot>=c) return 1;
	while(T--)
	{
		for(int i=1; i<=n; ++i)
		{
			pos[i]=nxt(pos[i]);
			int r=pos[i];
			f[i][r]=mp(0, 0);
			for(int x=i; x!=r; x=nxt(x))
			{
				auto t=f[i][x]+f[x][r];
				if(s[i][r]+t.y>=c) ++t.x, t.y=-s[i][r];
				upt(f[i][r], t);
			}
//			printf("fa %d %d %d %lld\n", i, r, f[i][r].x, -f[i][r].y);
		}
	}
	for(int i=1; i<=n; ++i) if(f[i][pr(i)].x+(tot+f[i][pr(i)].y>=c)>k) return 1;
//	puts("Fail");
	return 0;
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
	for(int i=1; i<=n; ++i)
	{
		int r=nxt(i);
		ll cur=p[i]*p[r];
		while(r!=i)
		{
			s[i][r]=std::abs(cur+p[r]*p[i]);
			cur+=p[r]*p[nxt(r)];
			r=nxt(r);
		}
		tot=std::abs(cur);
	}
//	printf("tot %lld\n", tot);
//	chk(3);
//	return 0;
	ll l=0, r=tot;
	while(l<r)
	{
		ll mid=(l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld\n", l);
	return 0;
}