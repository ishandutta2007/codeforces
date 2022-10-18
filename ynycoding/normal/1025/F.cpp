#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define x first
#define y second
#define mp std::make_pair
using std::pair;
typedef pair<int, int> vec;
const int N=2005;
int n, id[N<<1];
ll ans;
vec p[N], rp[N];
vec operator +(const vec &a, const vec &b) { return mp(a.x+b.x, a.y+b.y); }
vec operator -(const vec &a, const vec &b) { return mp(a.x-b.x, a.y-b.y); }
ll operator *(const vec &a, const vec &b) { return 1ll*a.x*b.y-1ll*a.y*b.x; }
inline int sgn(ll x) { return x>0?1:x<0?-1:0; }
inline ll calc(int x) { return 1ll*x*(x-1)/2; }
bool cmp(int x, int y)
{
	const vec &a=rp[x], &b=rp[y];
	if(!sgn(a.y)&&a.x>0) return 1;
	if(!sgn(b.y)&&b.x>0) return 0;
	if(sgn(a.y)==sgn(b.y)||!sgn(a.y)||!sgn(b.y)) return sgn(a*b)>=0;
	return sgn(a.y)>sgn(b.y);
}
inline void solve(int x)
{
	for(int i=1; i<x; ++i) id[i]=i;
	for(int i=x+1; i<=n; ++i) id[i-1]=i;
	for(int i=1; i<=n; ++i) rp[i]=p[i]-p[x];
	std::sort(id+1, id+n, cmp);
	std::copy(id+1, id+n, id+n);
	ll ret=0;
	for(int l=1, r=1; l<n; ++l)
	{
		r=std::max(l, r);
		while(r<l+n-2&&rp[id[l]]*rp[id[r+1]]>=0) ++r;
		int len=r-l+1;
		ans+=calc(n-1-len)*calc(len-1);
		ret+=calc(n-1-len)*calc(len-1);
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", &p[i].x, &p[i].y);//, p[i].x=-p[i].x;
	for(int i=1; i<=n; ++i) solve(i);
	printf("%lld\n", ans>>1);
	return 0;
}