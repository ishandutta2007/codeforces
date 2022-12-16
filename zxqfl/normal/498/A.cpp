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

ll ax, ay, bx, by;
ll a[300], b[300], c[300];
int N;

bool s1[300];
bool s2[300];

void solve(ll basex, ll basey, bool* arr)
{
	ji(N)
	{
		if (b[i] == 0)
			arr[i] = basex > (double) c[i] / -a[i];
		else
		{
			double ypos = (double) c[i] / -b[i];
			double y = basey - ypos;
			ll x = basex;
			ll vx = -b[i];
			ll vy = a[i];
			arr[i] = (vx * y - vy * x) > 0;
		}
	}
}

int main()
{
	rlong(ax);
	rlong(ay);
	rlong(bx);
	rlong(by);
	rint(N);
	ji(N)
	{
		rlong(a[i]);
		rlong(b[i]);
		rlong(c[i]);
	}

	solve(ax, ay, s1);
	solve(bx, by, s2);

	int total = 0;
	ji(N) if (s1[i] != s2[i])
		total++;
	printf("%d\n", total);
}