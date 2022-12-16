#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define INF ((int) 1e9+10)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main()
{
	int A, B, C, X, Y, Z;
	int cA, cB, cC;
	rint(A); rint(B); rint(C); rint(X); rint(Y); rint(Z); rint(cA); rint(cB); rint(cC);
	B -= Z;
	C -= Y;

	ll best = INF;
	for (int ATK = max(1, min(X, B)); ATK <= X; ATK++)
	{
		ll cost = 0;
		if (ATK - B > 0)
			cost += (ATK - B) * cB;
		ll bcost = INF;
		int tKill = (X + ATK - 1) / ATK;
		for (int DMGTK = min(C, 0); DMGTK <= 0; DMGTK++)
		{
			ll ccost = (DMGTK - C) * cC;
			ccost = max(ccost, 0ll);
			int taken = -DMGTK * tKill;
			if (taken >= A)
			{
				ccost += (taken + 1 - A) * cA;
			}
			bcost = min(bcost, ccost);
			//printf("%d %lld %d\n", DMGTK, ccost, taken);
		}
		//printf("%d %lld %lld %d\n", ATK, cost, bcost, tKill);
		best = min(best, cost + bcost);
	}
	printf("%lld\n", best);
}