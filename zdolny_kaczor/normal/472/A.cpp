# include <cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	switch(n%6)
	{
		case 0:
			printf("%d %d\n", 6, n-6);
		break;
		case 1:
			printf("%d %d\n", 4, n-4);
			break;
		case 2:
			printf("%d %d\n", 4, n-4);
			break;
		case 3:
			printf("%d %d\n", 6, n-6);
			break;
		case 4:
			printf("%d %d\n", 6, n-6);
			break;
		case 5:
			printf("%d %d\n", 8, n-8);
			break;
			
	}
}