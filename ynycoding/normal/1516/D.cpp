#include <cstdio>
#include <deque>
#include <algorithm>
const int N=100005;
int n, q, a[N], pr[N], pos[N], to[N][20];
int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", a+i);
		int x=a[i];
		for(int j=2; j*j<=x; ++j) if(x%j==0)
		{
			pr[i]=std::max(pr[i], pos[j]);
			pos[j]=i;
			while(x%j==0) x/=j;
		}
		if(x>1) pr[i]=std::max(pr[i], pos[x]), pos[x]=i;
//		++pr[i];
		pr[i]=std::max(pr[i], pr[i-1]);
//		printf("pr %d %d\n", i, pr[i]);
	}
	for(int i=1; i<=n; ++i)
	{
		to[i][0]=pr[i];
		for(int j=1; (1<<j)<=i; ++j)
			to[i][j]=to[to[i][j-1]][j-1];
	}
	for(int i=1, l, r; i<=q; ++i)
	{
		scanf("%d%d", &l, &r);
		int x=r, ans=0;
		for(int i=19; ~i; --i) if(to[x][i]>=l)
			x=to[x][i], ans|=1<<i;
		printf("%d\n", ans+1);
	}
	return 0;
}