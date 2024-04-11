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

ll C, H1, H2, W1, W2;
ll ans = 0;

void cons(ll x)
{
	if (x < 0 || W1 * x > C) return;
	ans = max(ans, H1 * x + H2 * ((C - W1 * x) / W2));
}

int main()
{
	rlong(C);
	rlong(H1);
	rlong(H2);
	rlong(W1);
	rlong(W2);
	ji(100000)
	{
		cons(i);
		cons(C / W1 - i);
	}
	swap(W1, W2);
	swap(H1, H2);
	ji(100000)
	{
		cons(i);
		cons(C / W1 - i);
	}
	printf("%lld\n", ans);
}