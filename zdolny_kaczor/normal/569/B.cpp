# include <cstdio>
const int MN=100*1000+10;
int a[MN];
int cou[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", a+i);
	for (int i=0; i<n; ++i)
		cou[a[i]]++;
	int low=1;
	for (int i=0; i<n; ++i)
		if (cou[a[i]]>1 || a[i]>n)
		{
			for (;cou[low]; ++low)
				;
			cou[a[i]]--;
			a[i]=low;
			cou[low]++;
		}
	for (int i=0; i<n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}