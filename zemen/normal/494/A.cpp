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
	freopen("a.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

vector <int> ans;
char s[200001];

int solve()
{
	gets(s);
	int n = strlen(s);
	int bal = 0;
	int last = n - 1;
	while (s[last] != '#')
		--last;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
			++bal;
		else if (s[i] == ')')
			--bal;
		else
		{
			--bal;
			ans.push_back(1);
		}
	}
	ans.back() += bal;
	if (ans.back() < 1)
	{
		cout << -1 << '\n';
		return 0;
	}
	int pos = 0;
	bal = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '(')
			++bal;
		else if (s[i] == ')')
			--bal;
		else
			bal -= ans[pos++];
		if (bal < 0)
		{
			cout << -1 << '\n';
			return 0;
		}
	}
	for (int i = 0; i < sz(ans); ++i)
		cout << ans[i] << '\n';
	return 0;
}