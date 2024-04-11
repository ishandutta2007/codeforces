#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

#define MAXN 100

using namespace std;
typedef long long ll;

int N;

int main()
{
	rint(N);

	double arr[MAXN];

	loop(i, N)
		scanf("%lf", arr + i);

	sort(arr, arr + N);

	double p0 = 1;
	double p1 = 0;
	double best = 0;

	loop(i, N)
	{
		double x = arr[N-i-1];

		p1 -= p1 * x;
		p1 += p0 * x;
		p0 -= p0 * x;

		best = max(best, p1);
	}

	printf("%.15lf\n", best);
}