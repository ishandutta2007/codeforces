#include <cstdio>
int n, prev, met;
int main()
{
	scanf("%d", &n);
	for(int i=1, a; i<=n; ++i)
	{
		scanf("%d", &a);
		if(a==prev) return puts("NO"), 0;
		if(!met&&a<=prev) met=1;
		if(met&&a>=prev) return puts("NO"), 0;
		prev=a;
	}
	puts("YES");
	return 0;
}