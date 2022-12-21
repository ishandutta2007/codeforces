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

const int MX = 200009;
vector<int> children[MX];
ll value[MX];
ll subsidiaryValue[MX];

void solve(int x)
{
	ll ans = 0;
	vector<ll> vals;
	foreach(o, children[x])
	{
		solve(o);
		ans += subsidiaryValue[o];
		vals.pb(value[o]);
	}
	sort(vals.begin(), vals.end());
	reverse(vals.begin(), vals.end());
	for (int i = 0; i + 1 < vals.size(); i += 2)
	{
		subsidiaryValue[x] += vals[i];
		subsidiaryValue[x] += vals[i+1];
	}
	if (vals.size() % 2)
		value[x] = max(value[x], vals.back());
	subsidiaryValue[x] += ans;
}

int main()
{
	nrint(N);
	ji(N)
	{
		nrint(sup);
		rlong(value[i]);
		if (sup > 0)
		{
			sup--;
			children[sup].pb(i);
		}
	}
	solve(0);
	printf("%lld\n", subsidiaryValue[0] + value[0]);
}