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

pair <int, int> qw[1001];
map <int, int> o;
priority_queue <int> q;

void upd(int a, int b)
{
    auto it = o.find(a);
    if (it == o.end())
    {
        o[a] = b;
        q.push(a);
    }
    else
        o[a] = min(it->second, b);
}

int solve()
{
	int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> qw[i].first;
    for (int j = 0; j < n; ++j)
        cin >> qw[j].second;
    for (int i = 0; i < n; ++i)
        upd(qw[i].first, qw[i].second);
    while (!q.empty())
    {
        int u = q.top();
        int cost = o[u];
        q.pop();
        for (auto v: o)
            upd(__gcd(u, v.first), cost + v.second);
    }
    if (!o.count(1))
        cout << -1 << '\n';
    else
        cout << o[1] << '\n';
	return 0;
}