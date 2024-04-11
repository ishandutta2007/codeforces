# include <cstdio>
# include <map>
using namespace std;
int tab[100][100];
int seed=1304104130;
int abs(int x)
{
	if (x<0)
		return -x;
	else
		return x;
}
int rand()
{
	return seed=abs(seed*12493LL+142412%1000000009);
}
int best(int a)
{
// 	printf("a=%d\n", a);
	int last=-1;
	for (int i=1; i*i<a; ++i)
	{
		if (a%i==0 && (a/i-i)%2==0)
			last=(a/i-i)/2;
	}
	return last;
}
bool issq(int x)
{
	int min=0, max=x;
	while (min<=max)
	{
		long long int med=(min+max)/2;
		if (med*med==x)
			return true;
		else if (med*med>x)
			max=med-1;
		else
			min=med+1;
	}
	return false;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (n==1 && m==1)
	{
		printf("1\n");
		return 0;
	}
	else if (n==1)
	{
		for (int i=0; i<m-1; ++i)
			printf("3 ");
		printf("%d\n", best(9*(m-1)));
		return 0;
	}
	else if (m==1)
	{
		for (int i=0; i<n-1; ++i)
			printf("3\n");
		printf("%d\n", best(9*(n-1)));
		return 0;
	}
	while (true)
	{
		for (int i=0; i<n-1; ++i)
			for (int k=0; k<m-1; ++k)
				tab[i][k]=rand()%3*8+8;
		for (int i=0; i<n-1; ++i)
		{
			int sum=0;
			for (int k=0; k<m-1; ++k)
				sum+=tab[i][k]*tab[i][k];
			tab[i][m-1]=2*best(sum/4);
		}
		for (int k=0; k<m-1; ++k)
		{
			int sum=0;
			for (int i=0; i<n-1; ++i)
				sum+=tab[i][k]*tab[i][k];
			tab[n-1][k]=2*best(sum/4);
		}
// 		for (int i=0; i<n; ++i)
// 		{
// 			for (int k=0; k<m; ++k)
// 				printf("%d ", tab[i][k]);
// 			putchar(10);
// 		}
// 		getchar();
		int sum1=0, sum2=0;
		for (int i=0; i<n-1; ++i)
			sum1+=tab[i][m-1]*tab[i][m-1];
		for (int k=0; k<m-1; ++k)
			sum2+=tab[n-1][k]*tab[n-1][k];
// 		printf("sums=%d %d\n", sum1, sum2);
		for (int div=1; div*div<sum1; ++div)
			if (sum1%div==0 && (div+sum1/div)%2==0)
			{
				int r=(sum1/div-div)/2;
// 				printf("r=%d\n", r);
				if (issq(r*r+sum2))
				{
					tab[n-1][m-1]=r;
					for (int i=0; i<n; ++i)
					{
						for (int k=0; k<m; ++k)
							printf("%d ", tab[i][k]);
						putchar(10);
					}
					return 0;
				}
			}
	}
}