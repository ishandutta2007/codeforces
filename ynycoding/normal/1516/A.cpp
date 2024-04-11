#include <cstdio>
#include <algorithm>
const int N=1005;
int T, n, k, a[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1; i<n&&k; ++i)
		{
			if(a[i]>k) a[i]-=k, a[n]+=k, k=0;
			else k-=a[i], a[n]+=a[i], a[i]=0;
		}
		for(int i=1; i<=n; ++i) printf("%d ", a[i]);
		puts("");
	}
	return 0;
}