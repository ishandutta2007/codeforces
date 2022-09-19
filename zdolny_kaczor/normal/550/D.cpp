# include <cstdio>
const int MN=300;
bool mat[MN][MN];
bool rem(int a, int b)
{
	mat[a][b]=mat[b][a]=false;
}
void makecom(int stnr, int size)
{
	for (int i=0; i<size; ++i)
		for (int k=0; k<size; ++k)
			if (i!=k)
				mat[i+stnr][k+stnr]=true;
	rem(stnr, stnr+1);
	rem(stnr, stnr+2);
	for (int i=3; i<size; i+=2)
		rem(stnr+i, stnr+i+1);
}
void show(int n)
{
	int e=0;
	for (int i=1; i<=n; ++i)
		for (int k=i+1; k<=n; ++k)
			if (mat[i][k])
				e++;
	printf("%d %d\n", n, e);
	for (int i=1; i<=n; ++i)
		for (int k=i+1; k<=n; ++k)
			if (mat[i][k])
				printf("%d %d\n", i, k);
}
int main()
{
	int k;
	scanf("%d", &k);
	if (k==1)
	{
		printf("YES\n2 1\n1 2\n");
		return 0;
	}
	if (k%2==0)
	{
		printf("NO\n");
		return 0;
	}
	else
	{
		printf("YES\n");
		makecom(1, k+2);
		makecom(k+3, k+2);
		mat[1][k+3]=mat[k+3][1]=true;
		show(2*(k+2));
	}
}