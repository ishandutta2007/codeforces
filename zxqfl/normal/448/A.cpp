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

int main()
{
	int N;
	N = 3;
	int a[N], b[N];

	loop(i, N)
		rint(a[i]);
	loop(i, N)
		rint(b[i]);

	int A = 0, B = 0;
	loop(i, N)
		A += a[i];
	loop(i, N)
		B += b[i];

	int S;
	rint(S);

	printf("%s\n", ((A + 4) / 5 + (B + 9) / 10 <= S) ? "YES" : "NO");
}