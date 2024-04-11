#include <cstdio>
#include <algorithm>
const int N=100005;
int T, n, q, a[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		int c0=0;
		while(1)
		{
			if(n==1) break;
			if(!c0)
			{
				for(int i=1; i<n; ++i) a[i]=a[i+1]-a[i];
				--n;
			}
			else
			{
				for(int i=n; i>1; --i) a[i]-=a[i-1];
				--c0;
			}
			std::sort(a+1, a+n+1);
			int t=0;
			while(t<n&&!a[t+1]) ++t;
			if(t==n) break;
			c0+=t;
			std::copy(a+t+1, a+n+1, a+1);
			n-=t;
		}
		printf("%d\n", a[n]);
	}
	return 0;
}