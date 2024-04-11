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

int N, M;
int dist[500000];
int stops[500000];
int cnt[500000];
vector<ll> poss;

void solve()
{
	if (M == 1)
	{
		poss.pb(0);
		return;
	}
	ll arr[N];
	arr[0] = 0;
	jjs(i, 1, N) arr[i] = arr[i-1] + dist[i] - dist[i-1];
	ll ans = 0;
	cnt[0] *= 2;
	cnt[N-1] *= 2;
	int mn = INF;
	ji(N) mn = min(mn, cnt[i]);
	ans += arr[N-1] * mn;
	ji(N) cnt[i] -= mn;
	bool all0 = true;
	ji(N) all0 &= cnt[i] == 0;
	if (all0)
	{
		jjs(i, 1, N)
			poss.pb(ans - (dist[i] - dist[i-1]));
	}
	else
	{
		jjs(i, 1, N)
			ans += min(cnt[i], cnt[i-1]) * (dist[i] - dist[i-1]);
		poss.pb(ans);
	}
}

int main()
{
	rint(N);
	ji(N) rint(dist[i]);
	rint(M);
	ji(M) rint(stops[i]);
	ji(M) stops[i]--;
	ji(M) cnt[stops[i]]++;
	solve();
	sort(poss.begin(), poss.end());
	if (poss[0] != poss.back())
		printf("-1\n");
	else
		printf("%lld\n", poss[0]);
}