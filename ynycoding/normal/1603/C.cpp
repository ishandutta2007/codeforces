#include <cstdio>
#include <algorithm>
const int N=100005, MOD=998244353;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
int T, n, a[N], cnt[N], ans;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		ans=0;
		for(int i=1; i<=n; ++i)
		{
			cnt[i]=1;
			for(int j=i-1; j; --j)
			{
//				printf("now %d %d\n", i, j);
				if((a[j]+cnt[j]-1)/cnt[j]<=a[j+1]/cnt[j+1]) break;
				int d=a[j+1]/cnt[j+1];
				int t=(a[j]+d-1)/d;
//				printf("t %d\n", t);
				inc(ans, 1ll*j*(n-i+1)%MOD*(t-cnt[j])%MOD);
				cnt[j]=t;
			}
		}
//		for(int i=1; i<=n; ++i) printf("%d ", cnt[i]);
//		puts("");
		printf("%d\n", ans);
	}
	return 0;
}