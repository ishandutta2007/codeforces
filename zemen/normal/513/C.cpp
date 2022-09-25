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
	freopen("c.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

int l[11];
int r[11];
ld len[11];

int solve()
{
	int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];
    for (int i = 0; i < n; ++i)
        len[i] = r[i] - l[i] + 1;
    ld ans = 0;
    for (int i = 0; i < n; ++i)
        for (int cost = 0; cost <= 10000; ++cost)
        {
            if (cost < r[i])
            {
                ld pr = (r[i] - max(l[i], cost + 1) + 1.0) / len[i];
                bool fail = false;
                ld pr2 = 1;
                for (int j = 0; j < n; ++j)
                {
                    if (j == i)
                        continue;
                    if (l[j] > cost)
                        fail = true;
                    pr2 *= (min(r[j], cost) - l[j] + 1.0) / len[j];
                }
                ld pr3 = 1;
                for (int j = 0; j < n; ++j)
                {
                    if (j == i)
                        continue;
                    pr3 *= (min(r[j], cost - 1) - l[j] + 1.0) / len[j];
                }
                pr2 -= pr3;
                pr *= pr2;
                if (!fail)
                {
                    ans += pr * cost;
                }
            }
            if (l[i] <= cost && cost <= r[i])
            {
                ld pr = 1 / len[i];
                bool fail = false;
                ld pr2 = 1;
                for (int j = 0; j < n; ++j)
                {
                    if (j == i)
                        continue;
                    int rb = j < i ? cost - 1 : cost;
                    if (l[j] > rb)
                        fail = true;
                    pr2 *= (min(r[j], rb) - l[j] + 1.0) / len[j];
                }
                ld pr3 = 1;
                for (int j = 0; j < n; ++j)
                {
                    if (j == i)
                        continue;
                    pr3 *= (min(r[j], cost - 1) - l[j] + 1.0) / len[j];
                }
                pr2 -= pr3;
                pr *= pr2;
                if (!fail)
                {
                    ans += pr * cost;
                }
            }
        }
    cout << ans << '\n';
    return 0;
}