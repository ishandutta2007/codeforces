#include <bits/stdc++.h>

#define rloop(i, x) for (int i = (x); i >= 0; i--)
#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define INF ((int) 1e9)
#define mp make_pair
#define pb push_back
#define rint(N) scanf("%d", &(N))

#define MAXN 1000
#define MAXK 1000001

typedef long long ll;
using namespace std;

int N;
int A[5000];

int midx(int a, int b)
{
	int idx = a;
	for (int i = a; i <= b; i++)
		if (A[i] < A[idx])
			idx = i;

	return idx;
}

int solve(int a, int b, int alr)
{
	if (b < a)
		return 0;

	int best = b - a + 1;
	int idx = midx(a, b);
	int nv = solve(a, idx-1, A[idx]) + solve(idx+1, b, A[idx]) + A[idx] - alr;
	return min(best, nv);
}

int main()
{
	rint(N);

	loop(i, N)
		rint(A[i]);

	printf("%d\n", solve(0, N-1, 0));
}