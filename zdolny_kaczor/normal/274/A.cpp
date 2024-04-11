# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e5+32;
long long tab[MN];
bool out[MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (k==1)
	{
		printf("%d\n", n);
		return 0;
	}
	for (int i=0; i<n; ++i)
		scanf("%I64d", tab+i);
	sort(tab, tab+n);
	int p1=0, p2=0;
	int res = n;
	while (p2<n)
	{
// 		printf("%d %d\n", p1, p2);
		if (tab[p1]*k>tab[p2])
			p2++;
		else if (tab[p1]*k==tab[p2])
		{
			p2++;
			p1++;
			if (!out[p1])
			{
				res--;
				out[p2]=true;
			}
// 			printf("res--\n");
		}
		else
			p1++;
	}
	printf("%d\n", res);
}