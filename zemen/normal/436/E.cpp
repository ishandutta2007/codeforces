#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "e"

struct myset {
	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > o;
	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > del;
	
	void insert(pair <int, int> val) {
		o.push(val);
	}
	
	void erase(pair <int, int> val) {
		del.push(val);
	}
	
	pair <int, int> begin() {
		while (!del.empty() && del.top() == o.top()) {
			o.pop();
			del.pop();
		}
		return o.top();
	}
	
	bool empty() {
		while (!del.empty() && del.top() == o.top()) {
			o.pop();
			del.pop();
		}
		return o.empty();
	}
};

myset a;
myset b;
myset c;
myset d;
int acost[300001];
int bcost[300001];
int state[300001];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; ++i) {
		int ca, cb;
		scanf("%d%d", &ca, &cb);
		a.insert(mp(ca, i));
		b.insert(mp(cb, i));
		acost[i] = ca;
		bcost[i] = cb;
	}
	ll cost = 0;
	for (int iter = 0; iter < w; ++iter) {
		int upd1 = INF;
		if (!a.empty())
			upd1 = a.begin().fi;
		int upd2 = INF;
		if (!b.empty() && !d.empty())
			upd2 = b.begin().fi + d.begin().fi;
		int upd3 = INF;
		if (!c.empty())
			upd3 = c.begin().fi;
		if (upd1 <= upd2 && upd1 <= upd3) {
			int id = a.begin().se;
			//~ cerr << "upd1 " << id << '\n';

			assert(state[id] == 0);
			cost += acost[id];
			state[id] = 1;
			a.erase(mp(acost[id], id));
			b.erase(mp(bcost[id], id));
			c.insert(mp(bcost[id] - acost[id], id));
			d.insert(mp(-acost[id], id));
		} else if (upd2 <= upd3) {
			int id = b.begin().se;
			int id2 = d.begin().se;
			//~ cerr << "upd2 " << id << ' ' << id2 << '\n';

			assert(state[id] == 0);
			cost += bcost[id];
			cost += d.begin().fi;
			state[id] = 2;
			a.erase(mp(acost[id], id));
			b.erase(mp(bcost[id], id));
			d.insert(mp(acost[id] - bcost[id], id));
			assert(state[id2] != 0);
			if (state[id2] == 1) {
				a.insert(mp(acost[id2], id2));
				b.insert(mp(bcost[id2], id2));
				c.erase(mp(bcost[id2] - acost[id2], id2));
				d.erase(mp(-acost[id2], id2));
				state[id2] = 0;
			} else {
				c.insert(mp(bcost[id2] - acost[id2], id2));
				d.erase(mp(acost[id2] - bcost[id2], id2));
				d.insert(mp(-acost[id2], id2));
				state[id2] = 1;
			}
		} else {
			int id = c.begin().se;
			//~ cerr << "upd3 " << id << '\n';

			assert(state[id] == 1);
			cost += bcost[id] - acost[id];
			state[id] = 2;
			c.erase(mp(bcost[id] - acost[id], id));
			d.erase(mp(-acost[id], id));
			d.insert(mp(acost[id] - bcost[id], id));
		}
	}
	cout << cost << '\n';
	for (int i = 0; i < n; ++i)
		cout << state[i];
	cout << '\n';
}