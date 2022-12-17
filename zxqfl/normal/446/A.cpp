#include <bits/stdc++.h>

#define rloop(i, x) for (int i = (x); i >= 0; i--)
#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define INF ((int) 1e9)
#define mp make_pair
#define pb push_back
#define rint(N) scanf("%d", &(N))

#define MAXN 100000

typedef long long ll;
using namespace std;

int N;
int seq[MAXN];
int pcount[MAXN];

int rpcount(int a, int b)
{
	if (a == 0)
		return pcount[b];
	else
		return pcount[b] - pcount[a-1];
}

bool prob(int a, int b)
{
	if (b - a < 2)
		return false;
	return rpcount(a+1, b-1) > 0;
}

bool works(int L)
{
	int a = 0, b = 0;
	int count = 0;
	int cidx = -1;
	while (b < N-1)
	{
		b++;
		if (seq[b] <= seq[b-1])
		{
			cidx = b;
			count++;
		}
		if (b - a + 1 > L)
		{
			a++;
			if (seq[a] <= seq[a-1])
				count--;
		}
		//printf("%d %d %d %d %d\n", L, a, b, count, cidx);

		bool ok = true;
		if (count > 1 || b - a + 1 != L)
			continue;
		if (count == 1)
		{
			if (cidx != b && cidx != a && seq[cidx-1] + 1 >= seq[cidx+1])
			{
				if (cidx > a+1 && seq[cidx] - 1 <= seq[cidx-2])
					ok = false;
			}
		}
		//printf("NOK %d %d %d %d %d\n", L, a, b, count, cidx);

		if (ok)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	rint(N);

	if (N <= 2)
	{
		printf("%d\n", N);
		return 0;
	}

	loop(i, N)
		rint(seq[i]), pcount[i] = 0;

	loop(i, N - 2)
	{
		if (seq[i] >= seq[i+1] && seq[i+2] <= seq[i] + 1)
			pcount[i]++;
	}

	sloop(i, 1, N)
		pcount[i] += pcount[i-1];

	int lo = 2, hi = N;

	while (lo < hi)
	{
		int mid = (lo+hi+1) / 2;
		if (works(mid))
			lo = mid;
		else
			hi = mid-1;
	}


	printf("%d\n", lo);
}