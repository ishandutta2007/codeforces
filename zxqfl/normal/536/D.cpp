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

const int MX = 2015;
vector<pair<int, int> > edges[MX];
ll dist[MX];
ll dist1[MX];
ll dist2[MX];
bool seen[MX];
int N, M, S, T;
int vals[MX];
ll gain1[MX][MX];
ll gain2[MX][MX];

void dij(int src)
{
	ji(N)
	{
		dist[i] = LINF;
		seen[i] = false;
	}
	dist[src] = 0;
	while (true)
	{
		int idx = -1;
		ji(N) if (!seen[i] && (idx < 0 || dist[i] < dist[idx]))
			idx = i;
		if (idx < 0) break;
		seen[idx] = true;
		foreach(e, edges[idx])
		{
			dist[e.first] = min(dist[e.first], dist[idx] + e.second);
		}
	}
}

void solveTransitions(ll myDist[MX], ll theirDist[MX], vector<ll>& myPoss, vector<ll>& theirPoss, ll gain[MX][MX])
{
	// foreach(v, myPoss) printf("%lld\n", v);
	jjl(them, theirPoss.size())
	{
		vector<pair<ll, ll> > cities;
		ji(N)
		{
			if (theirDist[i] > theirPoss[them])
			{
				cities.pb({myDist[i], vals[i]});
			}
		}
		sort(cities.begin(), cities.end());
		int pos = 0;
		ji(myPoss.size())
		{
			if (i == myPoss.size() - 1)
			{
				gain[them][i] = LINF;
				break;
			}
			int newPos = pos;
			ll valueChange = 0;
			while (newPos < cities.size() && cities[newPos].first <= myPoss[i+1])
			{
				valueChange += cities[newPos++].second;	
			}
			if (newPos == pos)
				gain[them][i] = LINF;
			else
				gain[them][i] = valueChange;
			// printf("gain[%d][%d] = %lld\n", them, i, gain[them][i]);
			pos = newPos;
		}
	}
}

ll dp[MX][MX][2];

ll f(int a, int b, int turn)
{
	if (a >= N || b >= N)
		return 0;
	ll& ans = dp[a][b][turn];
	if (ans != -LINF)
		return ans;
	if (turn == 0)
	{
		if (gain1[b][a] == LINF)
		{
			return ans = f(a + 1, b, turn);
		}
		else
		{
			return ans = max(f(a + 1, b, turn), f(a + 1, b, turn ^ 1)) + gain1[b][a];
		}
	}
	else
	{
		if (gain2[a][b] == LINF)
		{
			return ans = f(a, b + 1, turn);
		}
		else
		{
			return ans = min(f(a, b + 1, turn), f(a, b + 1, turn ^ 1));
		}
	}
}

int main()
{
	rint(N); rint(M);
	rint(S); rint(T);
	S--; T--;
	ji(N) rint(vals[i]);
	jk(M)
	{
		nrint(a); nrint(b); nrint(w);
		a--; b--;
		edges[a].pb({b, w});
		edges[b].pb({a, w});
	}
	dij(S);
	ji(N) dist1[i] = dist[i];
	dij(T);
	ji(N) dist2[i] = dist[i];
	// ji(N) printf("%d %lld %lld\n", i, dist1[i], dist2[i]);
	vector<ll> poss1, poss2;
	set<ll> S1, S2;
	S1.insert(-1);
	S2.insert(-1);
	ji(N)
	{
		S1.insert(dist1[i]);
		S2.insert(dist2[i]);
	}
	foreach(v, S1) poss1.pb(v);
	foreach(v, S2) poss2.pb(v);
	solveTransitions(dist1, dist2, poss1, poss2, gain1);
	solveTransitions(dist2, dist1, poss2, poss1, gain2);
	jij(N, N) jk(2) dp[i][j][k] = -LINF;
	// jij(N, N) jk(2) printf("f(%d %d %d) = %lld\n", i, j, k, f(i, j, k));
	ll ans = f(0, 0, 0);
	ll tot = 0;
	ji(N) tot += vals[i];
	// printf("ans=%lld tot=%lld\n", ans, tot);
	if (ans * 2 == tot)
	{
		printf("Flowers");
	}
	else if (ans * 2 < tot)
	{
		printf("Cry");
	}
	else
		printf("Break a heart");
}