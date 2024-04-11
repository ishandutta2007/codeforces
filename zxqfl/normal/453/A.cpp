#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
	int M, N;
	rint(M), rint(N);

	double c = 0;
	double A = 0, B = 0;
	for (int i = 1; i <= M; i++)
	{
		double nc = pow((double) i / M, N);
		double d = nc - c;
		A += d * i;
		B += d;
		c = nc;
	}
	printf("%.12lf\n", A / B);
}