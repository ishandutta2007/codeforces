# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <algorithm>
using namespace std;
# define MN 1000000
long long val[MN];
long long xors[MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i)
		val[i]=rand()+rand()*(long long)RAND_MAX+rand()*(long long)RAND_MAX*RAND_MAX;
	for (int i=0; i<m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		xors[x]^=val[y];
		xors[y]^=val[x];
	}
	for (int i=0; i<n; ++i)
		val[i]^=xors[i];
	sort(xors, xors+n);
	int bef=-1;
	long long res=0;
	for (int i=0; i<n; ++i)
	{
		bef++;
		if (i && xors[i]!=xors[i-1])
			bef=0;
		res+=bef;
	}
# define xors val
	sort(xors, xors+n);
	bef=-1;
	for (int i=0; i<n; ++i)
	{
		bef++;
		if (i && xors[i]!=xors[i-1])
			bef=0;
		res+=bef;
	}

	cout << res << '\n';
}