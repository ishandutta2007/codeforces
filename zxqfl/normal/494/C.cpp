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
typedef pair<pi, double> rec;

int N, Q;
int initial[100000];
rec recs[5001];
double fchance[5002];
double cchance[5002];
int parent[5001];
vector<int> children[5001];
int tmax[5001];
int otmax[5001];

bool gr(int a, int b)
{
	return recs[a].first.first <= recs[b].first.first && recs[a].first.second >= recs[b].first.second;
}
bool eq(int a, int b)
{
	return recs[a].first == recs[b].first;
}

void gmax(int p)
{
	int idx = 0;
	vector<int>& C = children[p];

	ji(C.size())
		gmax(C[i]);
	for (int i = recs[p].first.first; i <= recs[p].first.second;)
	{
		if (idx < C.size() && i == recs[C[idx]].first.first)
		{
			tmax[p] = max(tmax[p], tmax[C[idx]]);
			i = recs[C[idx]].first.second+1;
			idx++;
		}
		else
		{
			tmax[p] = max(tmax[p], initial[i]);
			otmax[p] = max(otmax[p], initial[i]);
			i++;
		}
	}
}

vector<double> solve(int p)
{
	vector<double> ans(Q+1);
	ji(Q+1)
		ans[i] = 1;
	vector<int>& C = children[p];
	ji(C.size())
	{
		vector<double> V = solve(C[i]);
		for (int j = ans.size()-1; j >= 0; j--)
		{
			int k = j - tmax[C[i]] + tmax[p];
			// printf("%d   %d %d\n", p, j, k);
			if (k < V.size() && k >= 0)
				ans[j] *= V[k];
		}
	}
	ji(ans.size())
		ans[i] = 1 - ans[i];
	ans[0] = 1;
	for (int i = ans.size()-2; i >= 0; i--)
	{
		double x = ans[i];
		ans[i+1] += (x - ans[i+1]) * recs[p].second;
	}
		// printf("%d   (%d %d %f):\n", p, recs[p].first.first, recs[p].first.second, recs[p].second);
		// jj(ans.size())
		// 	printf("   %d %f\n", j, ans[j]);
	ji(ans.size())
		ans[i] = 1 - ans[i];
	return ans;
}

int main()
{
	ji(5002) fchance[i] = 1;
	cchance[0] = 1;
	rint(N), rint(Q);
	ji(N) rint(initial[i]);
	ji(Q)
	{
		int a, b;
		double d;
		rint(a); rint(b);
		scanf("%lf", &d);
		recs[i] = mp(mp(a-1, b-1), d);
	}
	sort(recs, recs + Q);
	recs[Q] = mp(mp(0, N-1), 0);
	Q++;

	// ji(Q) printf("%d %d\n", recs[i].first.first, recs[i].first.second);
	ji(Q)
	{
		int par = -1;
		jj(Q) if (i != j && gr(j, i))
		{
			if (eq(j, i))
			{
				if (j > i)
				{
					par = j;
					break;
				}
			}
			else if (par == -1 || (gr(par, j) && !eq(par, j)))
				par = j;
		}
		parent[i] = par;
	}
	assert(parent[Q-1] == -1);
	ji(Q-1)
	{
		children[parent[i]].pb(i);
	}
	// ji(Q)
	// 	printf("par[%d] = %d\n", i, parent[i]);

	gmax(Q-1);
	// ji(Q)
	// 	printf("tmax[%d] = %d\n", i, tmax[i]);
	vector<double> V = solve(Q-1);
	ji(V.size())
		V[i] = 1 - V[i];
	double total = 0;
	for (int i = V.size()-2; i >= 0; i--)
	{
		total += i * (V[i] - V[i+1]);
	}
	printf("%.15f\n", total + tmax[Q-1]);
}