# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 10;
int ord[MN];
char num[MN][MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i)
		scanf("%s", num[i]);
	for (int i=0; i<k; ++i)
		ord[i]=i;
	int res=1000000000;
	do
	{
		int minr=1<<30, maxr=0;
		for (int i=0; i<n; ++i)
		{
			int val=0;
			for (int j=0; j<k; ++j)
				val=val*10+num[i][ord[j]]-'0';
			minr=min(minr, val);
			maxr=max(maxr, val);
		}
		int curr=maxr-minr;
		res=min(res, curr);
	}
	while (next_permutation(ord, ord+k));
	printf("%d\n", res);
}