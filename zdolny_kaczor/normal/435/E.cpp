# include <cstdio>
void swap (char & a, char & b)
{
	char temp=a;
	a=b;
	b=temp;
}
void swap(int & a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int m, n;
char tab[1001][1001];
# define MN 1000
void flip()
{
	for (int i=0; i<MN; ++i)
		for (int j=i+1; j<MN; ++j)
			swap(tab[i][j], tab[j][i]);
	swap(m, n);
}
char found[1000][2];
char oddeven[5];
bool solve()
{
	for (int i=0; i<m; ++i)
		for (int k=0; k<2; ++k)
			found[i][k]='0';
	for (int i=1; i<=4; ++i)
		oddeven[i]=-1;
	for (int i=0; i<m; ++i)
		for (int k=0; k<n; ++k)
			if (tab[i][k]!='0')
			{
				if (found[i][k%2]!='0' && found[i][k%2]!=tab[i][k])
					return 0;
				found[i][k%2]=tab[i][k];
			}
	for (int i=0; i<m; ++i)
		for (int k=0; k<2; ++k)
			if (found[i][k]!='0')
			{
				if (oddeven[found[i][k]-'0']==(i+1)%2)
					return 0;
				oddeven[found[i][k]-'0']=i%2;
			}
	for (int i=0; i<m; ++i)
		if (found[i][0]==found[i][1] && found[i][0]!='0')
			return 0;
	for (int i=0; i<m; ++i)
		for (int k=0; k<2; ++k)
			for (int l=0; l<2; ++l)
				if (found[i][k]==found[i-1][l] && found[i][k]!='0')
					return 0;
	int oe_amo[2]={0, 0};
	for (int i=1; i<=4; ++i)
		if (oddeven[i]!=-1)
			oe_amo[oddeven[i]]++;
	for (int k=0; k<2; ++k)
		if (oddeven[k]>2)
			return 0;
// 	for (int i=1; i<=4; ++i)
// 		printf("oe[%d]=%d\n", i, oddeven[i]);
// 	for (int i=0; i<2; ++i)
// 		printf("oe_amo[%d]=%d\n", i, oe_amo[i]);
	for (int i=1; i<=4; ++i)
		if (oddeven[i]==-1)
			for (int k=0; k<2; ++k)
				if (oe_amo[k]<2)
				{
					oe_amo[k]++;
					oddeven[i]=k;
					break;
				}
// 	for (int i=1; i<=4; ++i)
// 		printf("oe[%d]=%d\n", i, oddeven[i]);
	for (int i=0; i<m; ++i)
		for (int k=0; k<2; ++k)
			if (found[i][k]=='0')
				for (int l=1; l<=4; ++l)
					if (found[i][k^1]!='0'+l && oddeven[l]==i%2)
					{
						found[i][k]='0'+l;
						break;
					}
	for (int i=0; i<m; ++i)
		for (int k=0; k<n; ++k)
			tab[i][k]=found[i][k%2];
	return 1;
}
void show()
{
	for (int i=0; i<m; ++i)
	{
		for (int j=0; j<n; ++j)
			putchar(tab[i][j]);
		putchar(10);
	}
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i=0; i<m; ++i)
		scanf("%s", tab[i]);
	if (solve())
	{
		show();
	}
	else
	{
		flip();
		if (solve())
		{
			flip();
			show();
		}
		else
			printf("0\n");
	}
}