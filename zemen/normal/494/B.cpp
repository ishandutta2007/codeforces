#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
	srand(2317);
	cout.precision(10);
	cout.setf(ios::fixed);
	#ifdef LOCAL
	freopen("b.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

int pi[200005];
bool ok[200005];
int lb[200005];

int d[200005][2];

const int mod = 1000000007;

void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		 a -= mod;
}

int solve()
{
	string s, t;
	cin >> s >> t;
	string S = t + '*' + s;
	int n = sz(s);
	int m = sz(t);
	int k = 0;
	for (int i = 1; i < sz(S); ++i)
	{
		while (k > 0 && S[i] != S[k])
			k = pi[k - 1];
		if (S[i] == S[k])
			++k;
		pi[i] = k;
		if (i >= 2 * m && k == m)
			ok[i - 2 * m] = true;
	}
	//~ for (int i = 0; i < n; ++i)
		//~ cerr << ok[i] << ' ';
	int bd = n + 1;
	for (int i = n - 1; i >= 0; --i)
	{
		if (ok[i])
			bd = i + m;
		lb[i] = bd;
	}
	//~ for (int i = 0; i < n; ++i)
		//~ cerr << lb[i] << ' ';
	//~ cerr << '\n';
	d[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		add(d[i][0], d[i][1]);
		add(d[i + 1][0], d[i][0]);
		add(d[i + 1][1], d[i][1]);
		add(d[lb[i]][1], d[i][0]);
	}
	add(d[n][0], d[n][1]);
	add(d[n][0], mod - 1);
	cout << d[n][0] << '\n';
	return 0;
}