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

int a[1000];

int solve()
{
	ll n, m;
    cin >> n >> m;
    --m;
    ll d = (1ll << (n - 2));
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i)
    {
        if (m >= d)
        {
            m -= d;
            a[r--] = i;
        }
        else
            a[l++] = i;
        d /= 2;
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] + 1 << ' ';
    cout << '\n';
	return 0;
}