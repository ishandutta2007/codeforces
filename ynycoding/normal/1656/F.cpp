#include <cstdio>
#include <algorithm>
#define ll long long
const int N=200005;
int T, n, a[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		std::sort(a+1, a+n+1);
		ll sl=0, sr=0, tot=0, ans=-0x3f3f3f3f3f3f3f3f;
		for(int i=2; i<n; ++i) sr+=a[i];
		tot=sr;
		for(int i=1; i<n; ++i)
		{
			ll b=0, k=0;
			k=tot+1ll*(n-i-1)*a[1]+1ll*(i-1)*a[n];
			b=1ll*a[1]*sr+1ll*a[n]*sl;
			k+=a[1]+a[n], b+=1ll*a[1]*a[n];
			if(i==1&&k>0) { puts("INF"); goto out; }
			if(i==n-1&&k<0) { puts("INF"); goto out; }
			ans=std::max(ans, -a[i]*k+b);
			ans=std::max(ans, -a[i+1]*k+b);
			sl+=a[i+1], sr-=a[i+1];
		}
		printf("%lld\n", ans);
		out:;
	}
	return 0;
}