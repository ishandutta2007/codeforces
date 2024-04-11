#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define foreach(x, C) for (auto& x : (C))
#define ever ;;
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define rfloat(x) scanf("%lf", &(x))
#define MOD 1000000009

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;

int x[100000], y[100000];
bool removed[100000];
bool putInQ[100000];
map<pi, int> M;
int N;
set<int> S;

int getCubeAt(pi p)
{
	if (M.count(p))
		return M[p];
	else
		return -1;
}

int isCubeAt(pi p)
{
	return M.count(p) ? 1 : 0;
}

bool needsSupport(pi p)
{
	if (!isCubeAt(p))
		return false;
	int q = 0;
	q += isCubeAt({p.first-1, p.second-1});
	q += isCubeAt({p.first  , p.second-1});
	q += isCubeAt({p.first+1, p.second-1});
	assert(q >= 1);
	return q == 1;
}

void checkRemovable(int v)
{
	S.erase(v);
	if (needsSupport({x[v]-1, y[v]+1})) return;
	if (needsSupport({x[v]  , y[v]+1})) return;
	if (needsSupport({x[v]+1, y[v]+1})) return;
	S.insert(v);
}

void checkRemovablePt(pi p)
{
	if (!isCubeAt(p)) return;
	checkRemovable(M[p]);
}

void remove(int v)
{
	removed[v] = true;
	M.erase({x[v], y[v]});
	S.erase(v);
	for (int dx = -2; dx <= 2; dx++)
	for (int dy = -1; dy <= 1; dy++) if (max(abs(dx), abs(dy)) != 0)
	{
		checkRemovablePt({x[v]+dx, y[v]+dy});
	}
}

int main()
{
	rint(N);
	ji(N)
	{
		rint(x[i]);
		rint(y[i]);
		M[{x[i], y[i]}] = i;
	}
	ji(N) checkRemovable(i);
	int ans[N];
	ji(N)
	{
		// foreach(x, S) printf("%d ", x);
		// printf("\n");
		int v;
		if (i % 2)
			v = *S.begin();
		else
			v = *S.rbegin();
		ans[i] = v;
		remove(v);
	}
	ll total = 0;
	ji(N)
	{
		total *= N;
		total += ans[i];
		total %= MOD;
	}
	printf("%lld\n", total);
}