#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=1005;
int a[MAXN][MAXN];
void work(int n)
{
	for (int i=0;i<n;++i)
	{
		for (int j=1;j<=(n-1)/2;++j)
			a[i][(i+j)%n]=1;
		for (int j=(n+1)/2;j<n;++j)
			a[(i+j)%n][i]=1;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("8800.in","r",stdin);
	freopen("8800.out","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	if (n==4) printf("-1\n");
	else
	{
		if (n%2) work(n);
		else
		{
			work(n-1);
			for (int i=0;i<n-1;++i)
				if (i%2) a[i][n-1]=1;
				else a[n-1][i]=1;
		}
		for (int i=0;i<n;++i)
		{
			for (int j=0;j<n;++j)
				printf("%d ",a[i][j]);
			printf("\n");
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}