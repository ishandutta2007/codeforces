#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	if (n<=3) printf("NO\n");
	else if (n%2==0)
	{
		printf("YES\n");
		printf("1 * 2 = 2\n");
		printf("2 * 3 = 6\n");
		printf("6 * 4 = 24\n");
		for (int i=5;i<n;i+=2)
		{
			printf("%d - %d = 1\n",i+1,i);
			printf("24 * 1 = 24\n");
		}
	}
	else
	{
		printf("YES\n");
		printf("1 + 5 = 6\n");
		printf("4 + 6 = 10\n");
		printf("10 - 2 = 8\n");
		printf("3 * 8 = 24\n");
		for (int i=6;i<n;i+=2)
		{
			printf("%d - %d = 1\n",i+1,i);
			printf("24 * 1 = 24\n");
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}