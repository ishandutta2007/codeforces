#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;

set<int> st;
vector<priority_queue<ll_i, vector<ll_i>, greater<ll_i> > > taxis;

void add_taxi(int i, int j, ll t) {
	if (taxis[i].empty()) st.insert(i);
	taxis[i].push(ll_i(t, j));
}

int main() {
	int N, M, Q;
	cin >> N >> M >> Q;
	priority_queue<ll, vector<ll>, greater<ll> > events;
	map<ll, vector<i_i> > mp;
	taxis.resize(N);
	rep(j, M) {
		int i; scanf("%d", &i), i--;
		add_taxi(i, j, 0);
	}
	vector<ll> t(Q);
	vector<int> a(Q), b(Q);
	rep(q, Q) {
		scanf("%lld%d%d", &t[q], &a[q], &b[q]), a[q]--, b[q]--;
		events.push(t[q]);
	}
	int q = 0;
	while (!events.empty()) {
		ll t0 = events.top(); events.pop();
		// cout << t0 << endl;
		for (i_i z: mp[t0]) add_taxi(z.first, z.second, t0);
		mp[t0].clear();
		for (; q < Q && t[q] <= t0 && !st.empty(); q++) {
			int i0 = a[q];
			vector<vector<ll> > v;
			{
				auto it = st.upper_bound(i0);
				if (it != st.begin()) {
					it--;
					int i = *it;
					ll_i z = taxis[i].top();
					v.pb({i0 - i, z.first, z.second, i});
				}
			}
			{
				auto it = st.lower_bound(i0);
				if (it != st.end()) {
					int i = *it;
					ll_i z = taxis[i].top();
					v.pb({i - i0, z.first, z.second, i});
				}
			}
			sort(v.begin(), v.end());
			int i = v[0][3], j = v[0][2];
			taxis[i].pop();
			if (taxis[i].empty()) st.erase(i);
			ll t1 = t0 + abs(i - a[q]) + abs(a[q] - b[q]);
			events.push(t1);
			mp[t1].pb(i_i(b[q], j));
			printf("%d %lld\n", j + 1, t0 + abs(i - a[q]) - t[q]);
		}
	}
	// cout << "a" << endl;
}