#include <bits/stdc++.h>
using namespace std;
#define INF int(1e9+1)
#define INFL ll(2e18+INF)
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;
typedef complex <ld> point;
void solve();

#define NAME "c"
#define LOCAL_INPUT NAME ".in"
//~ #define LOCAL_OUTPUT NAME ".out"
//~ #define INPUT NAME ".in"
//~ #define OUTPUT NAME ".out"

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
		clock_t start = clock();
		#ifdef LOCAL_INPUT
			assert(freopen(LOCAL_INPUT, "r", stdin));
		#endif
		#ifdef LOCAL_OUTPUT
			assert(freopen(LOCAL_OUTPUT, "w", stdout));
		#endif
	#else
		#ifdef INPUT
			assert(freopen(INPUT, "r", stdin));
		#endif
		#ifdef OUTPUT
			assert(freopen(OUTPUT, "w", stdout));
		#endif
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef _GEANY
		fprintf(stderr, "Time: %.3fs\n", double(clock() - start) / CLOCKS_PER_SEC);
	#endif
}

vector <int> a[100001];
vector <int> a2[100001];
int bad[100001];
set <pair <int, int> > s;
set <pair <int, int> > b;
typedef set <pair <int, int> >::iterator iter;
int cnt;
int sum;

bool get(bool mode2 = false) {
	if (s.empty())
		return false;
	iter it = s.end();
	--it;
	int id = it->second;
	s.erase(it);
	//~ cerr << id << ' ' << a[id].back() << '\n';
	if (bad[id] + 1 >= cnt - 1 + mode2)
		return get();
	b.erase(make_pair(bad[id], id));
	++bad[id];
	b.insert(make_pair(bad[id], id));
	--cnt;
	sum -= a[id].back();
	a2[id].push_back(a[id].back());
	a[id].pop_back();
	if (!a[id].empty())
		s.insert(make_pair(a[id].back(), id));
	return true;
}

bool put(int id) {
	if (a2[id].empty())
		return false;
	b.erase(make_pair(bad[id], id));
	--bad[id];
	b.insert(make_pair(bad[id], id));
	++cnt;
	sum += a2[id].back();
	a2[id].pop_back();
	return true;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t, cost;
		cin >> t >> cost;
		sum += cost;
		a[t].push_back(cost);
	}
	if (sum == 0) {
		cout << 0 << '\n';
		return;
	}
	for (int i = 1; i < 100001; ++i) {
		sort(a[i].begin(), a[i].end());
		if (!a[i].empty()) {
			s.insert(make_pair(a[i].back(), i));
			b.insert(make_pair(bad[i], i));
		}
	}
	int res = sum;
	
	cnt = n;
	while (get()) {
		while (true) {
			iter it = b.end();
			--it;
			if (it->first < cnt)
				break;
			int id = it->second;
			if (!get(true) || !put(id)) {
				cout << res << '\n';
				return;
			}
		}
		res = min(res, sum);
	}
	cout << res << '\n';
}