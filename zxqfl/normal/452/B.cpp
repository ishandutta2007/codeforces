#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((ll) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

ll calc(vector<int>& V)
{
	ll ans = 0;
	int x = V[0], y = V[1];

	for (int i = 2; i < V.size(); i += 2)
	{
		ll dx = V[i] - x;
		ll dy = V[i+1] - y;
		ans += dx * dx + dy * dy;
		x = V[i];
		y = V[i+1];
	}
	return ans;
}

int main()
{
	int N, M;
	rint(N), rint(M);

	ll bd = 0;
	vector<int> V;

	vector<pi> pts;

	set<pi> S;
	S.insert(mp(0, 0));
	S.insert(mp(1, 0));
	S.insert(mp(0, 1));
	S.insert(mp(N, 0));
	S.insert(mp(N-1, 0));
	S.insert(mp(N, 1));
	S.insert(mp(N, M));
	S.insert(mp(N-1, M));
	S.insert(mp(N, M-1));
	S.insert(mp(0, M));
	S.insert(mp(0, M-1));
	S.insert(mp(1, M));

	for (const pi& x : S)
	{
		if (x.first >= 0 && x.second >= 0 && x.first <= N && x.second <= M)
			pts.pb(x);
	}

	loop(v1, pts.size())
	{
		loop(v2, pts.size()) if (v1 != v2)
		{
			loop(v3, pts.size()) if (v3 != v2 && v3 != v1)
			{
				loop(v4, pts.size()) if (v4 != v3 && v2 != v4 && v4 != v1)
				{
					vector<int> NV;
					NV.pb(pts[v1].first);
					NV.pb(pts[v1].second);
					NV.pb(pts[v2].first);
					NV.pb(pts[v2].second);
					NV.pb(pts[v3].first);
					NV.pb(pts[v3].second);
					NV.pb(pts[v4].first);
					NV.pb(pts[v4].second);
					ll x = calc(NV);
					if (x > bd)
					{
						V = NV;
						bd = x;
					}
				}
			}
		}
	}

	for (int i = 0; i < V.size(); i += 2)
		printf("%d %d\n", V[i], V[i+1]);
}