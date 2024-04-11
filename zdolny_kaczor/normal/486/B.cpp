# include <cstdio>
const int MN = 110;
int in[MN][MN];
int out[MN][MN];
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i)
		for (int k=0; k<n; ++k)
			scanf("%d", &in[i][k]);
	for (int i=0; i<m; ++i)
		for (int k=0; k<n; ++k)
		{
			out[i][k]=1;
		}
	for (int i=0; i<m; ++i)
		for (int k=0; k<n; ++k)
			if (in[i][k]==0)
			{
				for (int l=0; l<n; ++l)
					out[i][l]=0;
				for (int l=0; l<m; ++l)
					out[l][k]=0;
			}
	bool OK = true;
	for (int i=0; i<m; ++i)
		for (int k=0; k<n; ++k)
		{
			int OR = 0;
			for (int l=0; l<n; ++l)
				OR |= out[i][l];
			for (int l=0; l<m; ++l)
				OR |= out[l][k];
			if (OR != in[i][k])
				OK = false;
		}
	if (OK)
	{
		printf("YES\n");
		for (int i=0; i<m; ++i)
		{
			for (int k=0; k<n; ++k)
				printf("%d ", out[i][k]);
			printf("\n");
		}
		
	}
	else
		printf("NO\n");
}