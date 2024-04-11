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
	N++;
	bool prime[N];
	ji(N) prime[i] = true;
	for (int i = 2; i < N; i++) if (prime[i])
	{
		for (int j = i*2; j < N; j += i)
			prime[j] = false;
	}
	bool assigned[N];
	ji(N) assigned[i] = false;
	vector<pi> ans;
	for (int i = N-1; i > 1; i--) if (prime[i])
	{
		vector<int> V;
		for (int j = i; j < N; j += i) if (!assigned[j])
			V.pb(j);
		if (V.size() > 1)
		{
			swap(V[0], V[1]);
			for (int j = V.size() - 1; j > 0; j -= 2)
			{
				ans.pb({V[j], V[j-1]});
				assigned[V[j]] = assigned[V[j-1]] = true;
			}
		}
	}
	printf("%d\n", (int) ans.size());
	foreach(x, ans) printf("%d %d\n", x.first, x.second);
}