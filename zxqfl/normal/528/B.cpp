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
#define rfloat(x) scanf("%lf", &(x))
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<double, double> pd;

vector<int> V;

struct stree
{
	int a, b;
	stree *left, *right;
	int lazy, val;

	stree(int l, int r)
	{
		a = V[l];
		b = V[r];
		lazy = val = 0;
		if (a == b)
		{
			left = right = 0;
		}
		else
		{
			int mid = (l+r) / 2;
			left = new stree(l, mid);
			right = new stree(mid+1, r);
		}
	}

	int answer()
	{
		return val + lazy;
	}

	void propagate()
	{
		if (lazy && left)
		{
			left->lazy += lazy;
			right->lazy += lazy;
			lazy = 0;
			val = max(left->answer(), right->answer());
		}
	}

	void update(int p, int v)
	{
		if (p < a || p > b)
			return;
		if (a == b)
			val = max(val, v);
		else
		{
			left->update(p, v);
			right->update(p, v);
			val = max(right->answer(), left->answer());
		}
	}

	int query(int l, int r)
	{
		if (l <= a && r >= b)
			return answer();
		if (l > b || r < a)
			return 0;
		propagate();
		return max(left->query(l, r), right->query(l, r));
	}
};

int N;
pair<ll, ll> arr[200000];

int main()
{
	rint(N);
	ji(N)
	{
		rlong(arr[i].first);
		rlong(arr[i].second);
	}
	sort(arr, arr + N);
	int mval[N];
	int mx = 0;
	int pos = 0;
	set<ll> possval;
	ji(N)
	{
		possval.insert(arr[i].first + arr[i].second);
	}
	foreach(x, possval)
		V.pb((int) x);
	stree tree(0, V.size()-1);
	ji(N)
	{
		mval[i] = tree.query(V[0], arr[i].first - arr[i].second) + 1;
		tree.update(arr[i].first + arr[i].second, mval[i]);
		// printf("%lld %d\n", arr[i].first, mval[i]);
	}
	int ans = 0;
	ji(N) ans = max(ans, mval[i]);
	printf("%d\n", ans);
}