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
	freopen("g.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

int a[11];
int n, k;
int cnt, res;

void dfs(int q)
{
    if (q == k)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (a[j] > a[i])
                    ++res;
        ++cnt;
        return;
    }
    for (int l = 0; l < n; ++l)
        for (int r = l + 1; r <= n; ++r)
        {
            reverse(a + l, a + r);
            dfs(q + 1);
            reverse(a + l, a + r);
        }
}

int solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    dfs(0);
    cout << ld(res) / ld(cnt) << '\n';
	return 0;
}