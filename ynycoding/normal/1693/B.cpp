#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
#define ll long long
using std::vector;
const int N=200005;

int T, n, p[N], l[N], r[N];
ll sum[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=2; i<=n; ++i) scanf("%d", p+i);
		for(int i=1; i<=n; ++i) scanf("%d%d", l+i, r+i), sum[i]=0;
		int cnt=0;
		for(int i=n; i; --i)
		{
			if(l[i]>sum[i]) sum[i]=r[i], ++cnt;
			sum[i]=std::min(sum[i], 1ll*r[i]);
			sum[p[i]]+=sum[i];
		}
		printf("%d\n", cnt);
	}
	return 0;
}