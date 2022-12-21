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

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N;
vector<pi> V;

int main()
{
	rint(N);
	V.resize(N);
	set<int> sizes;
	int mn = 0;
	ji(N)
	{
		rint(V[i].first);
		rint(V[i].second);
		sizes.insert(V[i].first);
		sizes.insert(V[i].second);
		mn = max(mn, min(V[i].first, V[i].second));
	}
	ll ans = LINF;
	foreach(sz, sizes) if (sz >= mn)
	{
		vector<int> Q;
		int tot = 0;
		int trem = N / 2;
		ji(V.size())
		{
			auto p = V[i];
			if (p.second > sz)
			{
				trem--;
				tot += p.second;
			}
			else if (p.first > sz)
			{
				tot += p.first;
			}
			else if (p.first > p.second)
			{
				tot += p.first;
				Q.pb(p.first - p.second);
			}
			else
				tot += p.first;
		}
		if (trem < 0) continue;
		sort(Q.begin(), Q.end());
		reverse(Q.begin(), Q.end());
		ji(min((int) Q.size(), trem))
		{
			tot -= Q[i];
		}
		ans = min(ans, (ll) sz * tot);
	}
	printf("%lld\n", ans);
}