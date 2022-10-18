#include <cstdio>
#include <random>
#include <algorithm>
#define ll long long
std::mt19937 rnd(1145);
const int N=1000500;
int T=3, n, ans=0x3f3f3f3f;
ll a[N], mx;
int pr[N], is[N], top;
void init(int n)
{
	for(int i=2; i<=n; ++i)
	{
		if(!is[i]) pr[++top]=i;
		for(int j=1; j<=top&&i*pr[j]<=n; ++j)
		{
			is[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
}
inline int calc(ll d)
{
//	printf("calc %lld\n", d);
	ll ret=0;
	for(int i=1; i<=n; ++i)
	{
		ret+=a[i]<d?d-a[i]:std::min(d-a[i]%d, a[i]%d);
		if(ret>n) return 0x3f3f3f3f;
	}
	return ret;
}
inline void proc(ll x)
{
//	printf("proc %lld\n", x);
	for(int i=1; i<=top; ++i) if(x%pr[i]==0)
	{
//		printf("in %d %lld\n", i, x);
		ans=std::min(ans, calc(pr[i]));
		while(x%pr[i]==0) x/=pr[i];
	}
	if(x>1) ans=std::min(ans, calc(x));
//	puts("out");
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%lld", a+i), mx=std::max(mx, a[i]);
	init((int)std::sqrt(mx)+5);
	while(T--)
	{
		int x=rnd()%n+1;
//		fprintf(stderr, "%d\n", x);
		for(ll i=std::max(1ll, a[x]-2); i<=a[x]+2; ++i) proc(i);
	}
	printf("%d\n", ans);
	return 0;
}