#include <cstdio>
int n, k, p1, p2, a1, a2, cnt1, cnt2;
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=k+1; ++i)
	{
		putchar('?');
		for(int j=1; j<=k+1; ++j) if(i!=j) printf(" %d", j);
		puts("");
		fflush(stdout);
		int p, a;
		scanf("%d%d", &p, &a);
		if(!p1) p1=p, a1=a;
		if(p==p1) ++cnt1;
		else p2=p, a2=a, ++cnt2;
	}
	printf("! %d\n", a1>a2?cnt1:cnt2);
	fflush(stdout);
	return 0;
}