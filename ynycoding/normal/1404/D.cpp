#include <cstdio>
#include <vector>
#include <algorithm>
const int N=1000005;
int n, a[N], to[N], p[N], vis[N], is[N];
int tot;
inline int MT(int x) { return x<=n?x+n:x-n; }
int main()
{
	scanf("%d", &n);
	if(!(n&1))
	{
		puts("First");
		fflush(stdout);
		for(int i=1; i<=2*n; ++i) printf("%d ", i%n+1);
		return 0;
	}
	puts("Second");
	fflush(stdout);
	for(int i=1; i<=2*n; ++i)
	{
		scanf("%d", p+i);
		if(!a[p[i]]) a[p[i]]=i;
		else to[a[p[i]]]=i, to[i]=a[p[i]];
	}
	for(int i=1; i<=2*n; ++i) if(!vis[i])
	{
		int x=i;
		while(!vis[x])
		{
			vis[x]=1;
			is[x]=1;
			tot^=x&1;
			vis[to[x]]=1;
			x=MT(to[x]);
		}
	}
	if(tot)
	{
		for(int i=1; i<=2*n; ++i) if(vis[i]<2)
		{
			int x=i, len=0;
			while(vis[x]!=2)
			{
				vis[x]=2;
				vis[to[x]]=2;
				x=MT(to[x]);
				++len;
			}
			if(len&1)
			{
				x=i;
				while(vis[x]!=3)
				{
					is[x]=0, is[to[x]]=1;
					vis[x]=vis[to[x]]=3;
					x=MT(to[x]);
				}
				break;
			}
		}
	}
	for(int i=1; i<=2*n; ++i) if(is[i]) printf("%d ", i);
	return 0;
}