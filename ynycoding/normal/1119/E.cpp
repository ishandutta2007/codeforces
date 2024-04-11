#include <cstdio>
#define ll long long
#define MAXN 300005
int n, a[MAXN];
ll ans, s;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i)
	{
		if(s*2<=a[i]) ans+=s, a[i]-=2*s, s=0;
		else ans+=(a[i]>>1), s-=(a[i]>>1), a[i]&=1;
		ans+=a[i]/3, a[i]%=3;
		s+=a[i];
	}
	printf("%I64d", ans);
	return 0;
}