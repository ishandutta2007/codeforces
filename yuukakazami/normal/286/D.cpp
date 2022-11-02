#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

struct Wall {
	int l, r, t;
	bool operator<(const Wall&o) const {
		return t < o.t;
	}
	void read() {
		scanf("%d%d%d", &l, &r, &t);
	}
};

struct Event {
	int x, w;
	bool type;
	Event(int x, int w, bool tp) :
			x(x), w(w), type(tp) {
	}
	bool operator<(const Event&o) const {
		return x < o.x;
	}
};

vector<Wall> walls;

vector<Event> events;

struct E {
	int x, tp, sum, id;
	E(int x, int tp, int id = -1) :
			x(x), tp(tp), id(id) {
	}
	bool operator<(const E&o) const {
		return x < o.x;
	}
};

int nQ, nW;

vector<E> es;
const int MAX_N = int(1e5) + 10;
int ans[MAX_N];

int main() {
	cin >> nQ >> nW;
	for (int i = 0; i < nW; ++i) {
		int l, r, t;
		scanf("%d%d%d", &l, &r, &t);
		events.push_back(Event(l, t, true));
		events.push_back(Event(r, t, false));
	}
	sort(events.begin(), events.end());

	multiset<int> st;
	for (int i = 0; i < (int) events.size(); ++i) {
		Event e = events[i];
		if (i > 0) {
			int l = events[i - 1].x, r = events[i].x;
			if (!st.empty() && l < r) {
				int t = *st.begin();
				//[t-l,t-r)
//				cerr << t - r << " " << t - l << endl;
				es.push_back(E(t - r, 1));
				es.push_back(E(t - l, -1));
			}
		}
		if (e.type) {
			st.insert(e.w);
		} else {
			st.erase(st.find(e.w));
		}
	}

	for (int i = 0; i < nQ; ++i) {
		int q;
		scanf("%d", &q);
		es.push_back(E(q, 0, i));
	}

	sort(es.begin(), es.end());

	int cnt = 0;
	int sum = 0;

	for (int i = 0; i < (int) es.size(); ++i) {
		E e = es[i];
		if (e.tp == 1) {
			cnt++;
			sum -= e.x;
		} else if (e.tp == -1) {
			sum += e.x;
			cnt--;
		} else {
			ans[e.id] = sum + e.x * cnt;
		}
	}

	for (int i = 0; i < nQ; ++i) {
		printf("%d\n", ans[i]);
	}
	return 0;
}