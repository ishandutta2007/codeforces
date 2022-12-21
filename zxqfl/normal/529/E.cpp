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
#define rlong(x) scanf("%d", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) int x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

using namespace std;
typedef long long ll;

int N, K;
int denom[5000];
map<int, int> M;

int f(int amount)
{
	int ans = INF;
	ji(N)
	{
		jjs(j, 1, K+1)
		{
			int a = denom[i] * j;
			int v = amount - a;
			if (!M.count(v)) continue;
			else ans = min(ans, j + M[v]);
		}
	}
	return ans > K ? -1 : ans;
}

int main()
{
	rint(N); rint(K);
	M[0] = 0;
	ji(N)
	{
		rlong(denom[i]);
		jjs(j, 1, K+1)
		{
			int a = (int) (denom[i] * j);
			if (M.count(a))
				M[a] = min(M[a], j);
			else
				M[a] = j;
		}
	}
	nrint(Q);
	jk(Q)
	{
		nrlong(v);
		printf("%d\n", f(v));
	}
}