# include <cstdio>
# include <set>
using namespace std;
const int MN=1000*1000+42;
int tab[MN];
void inv (int a, int b)
{
	for (int i=a, k=b; i<k; i++, k--)
		swap(tab[i], tab[k]);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", tab+i);
	int first=-1, second=-1;
	for (int i=0; i<n-1; ++i)
	{
// 		printf("%d\n", i);
		if (first==-1)
		{
// 			printf("f\n");
			if (tab[i]>tab[i+1])
				first=i;
		}
		else
		{
// 			printf("s\n");
			if (tab[i]<tab[i+1])
			{
				second=i;
				break;
			}
		}
	}
// 	printf("%d %d\n", first, second);
	if (first==-1)
	{
		printf("yes\n1 1\n");
		return 0;
	}
	if (second==-1)
		second=n-1;
	inv(first, second);
	bool OK=true;
	for (int i=0; i<n-1; ++i)
		if (tab[i]>tab[i+1])
			OK=false;
	if (OK)
		printf("yes\n%d %d\n", first+1, second+1);
	else
		printf("no\n");
	
}