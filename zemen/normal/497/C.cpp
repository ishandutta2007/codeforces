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

pair <int, int> q[200001];
int k[200001];
int rb[200001];
int ans[200001];

struct Event
{
	int id, x;
	bool query;
	
	Event(int id): id(id), x(q[id].first), query(true) {}
	
	Event(int id, int x): id(id), x(x), query(false) {}
	
	bool operator<(const Event &e) const
	{
		return x < e.x || (x == e.x && query < e.query);
	}
	
};

vector <Event> event;

set <pair <int, int>> s;

int solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		q[i] = make_pair(l, r);
		event.push_back(Event(i));
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		--l;
		rb[i] = r, ::k[i] = k;
		event.push_back(Event(i, l));
	}
	sort(event.begin(), event.end());
	for (const auto &ev: event)
	{
		if (ev.query)
		{
			int id = ev.id;
			auto it = s.lower_bound(make_pair(q[id].second, -1));
			if (it == s.end())
			{
				cout << "NO\n";
				return 0;
			}
			ans[id] = it->second;
			--k[it->second];
			if (k[it->second] == 0)
				s.erase(it);
		}
		else
			s.insert(make_pair(rb[ev.id], ev.id));
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << ans[i] + 1 << ' ';
	cout << '\n';
	return 0;
}