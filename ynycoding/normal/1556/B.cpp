#include <cstdio>
#include <algorithm>
#define ll long long
const int N=100005;
int T, n, pos[N], top;
ll ans;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		top=0;
		for(int i=1, x; i<=n; ++i)
		{
			scanf("%d", &x);
			if(x&1) pos[++top]=i;
		}
		if(std::abs(n-2*top)>1) { puts("-1"); continue; }
		ans=0x3f3f3f3f3f3f3f;
		if(top*2>=n)
		{
			ll ret=0;
			for(int i=1; i*2-1<=n; ++i)
				ret+=std::abs(i*2-1-pos[i]);
			ans=ret;
		}
		if(top*2<=n)
		{
			ll ret=0;
			for(int i=1; i*2<=n; ++i)
				ret+=std::abs(i*2-pos[i]);
			ans=std::min(ans, ret);
		}
		printf("%lld\n", ans);
	}
	return 0;
}