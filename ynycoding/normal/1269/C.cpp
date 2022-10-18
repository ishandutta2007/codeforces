#include <cstdio>
#define MAXN 200005
int n, k, a[MAXN], ok=1;
char s[MAXN];
int main()
{
	scanf("%d%d%s", &n, &k, s);
	for(int i=1; i<=n; ++i) a[i]=s[i-1]-'0';
	for(int i=1, j=1; i<=n; ++i, ++j)
	{
		if(j>k) j-=k;
		if(a[j]>a[i]) break;
		if(a[j]<a[i]) { ok=0; break; }
	}
	if(ok)
	{
		printf("%d\n", n);
		for(int i=1, j=1; i<=n; ++i, ++j)
		{
			if(j>k) j-=k;
			printf("%d", a[j]);
		}
		return 0;
	}
	++a[k];
	for(int i=k; i; --i) if(a[i]==10) a[i]=0, ++a[i-1];
	if(a[0])
	{
		printf("%d\n", n+1);
		for(int i=1, j=1; i<=n; ++i, ++j)
		{
			if(j>=k) j-=k;
			printf("%d", a[j]);
		}
		return 0;
	}
	printf("%d\n", n);
	for(int i=1, j=1; i<=n; ++i, ++j)
	{
		if(j>k) j-=k;
		printf("%d", a[j]);
	}
	return 0;
}