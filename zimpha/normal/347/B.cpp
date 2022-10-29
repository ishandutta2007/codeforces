#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN=100000+10;

int a[MAXN];
int n;

int main()
{
	scanf("%d", &n);
	int ret=0;
	for (int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i]==i) ret++;
	}
	int ans=ret, tmp;
	for (int i=0; i<n; i++)
	{
		if (a[i]==i) continue;
		if (a[a[i]]==i) tmp=ret+2;
		else tmp=ret+1;
		if (tmp>ans) ans=tmp;
	}
	printf("%d\n", ans);
	return 0;
}