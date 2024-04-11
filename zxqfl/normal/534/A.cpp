#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
	nrint(N);
	vector<string> V = {"", "1\n1", "1\n1", "2\n1 3", "4\n2 4 1 3"};
	if (N <= 4)
		cout << V[N] << endl;
	else
	{
		printf("%d\n", N);
		for (int i = 1; i <= N; i += 2) printf("%d ", i);
		for (int i = 2; i <= N; i += 2) printf("%d ", i);
	}
}