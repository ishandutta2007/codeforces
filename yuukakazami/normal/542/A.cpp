#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;

const int MAX_N = int(2e5) + 10;

struct Video {
	int l, r;
	void read() {
		scanf("%d%d", &l, &r);
	}

	void reflect() {
		swap(l, r);
		l *= -1, r *= -1;
	}
};
int nVideos, nTVs;
Video videos[MAX_N];

struct TV {
	int l, r, c, ans, with;
	void read() {
		scanf("%d%d%d", &l, &r, &c);
		ans = 0;
	}

	void reflect() {
		swap(l, r);
		l *= -1, r *= -1;
	}

	void update(int id) {
		int a = videos[id].l, b = videos[id].r;
		a = max(a, l);
		b = min(b, r);
		int upd = b - a;
		if (upd > ans) {
			ans = upd;
			with = id;
		}
	}
};
TV tvs[MAX_N];

template<class T>
struct Index: public vector<T> {
	void doit() {
		sort(this->begin(), this->end());
		this->erase(unique(this->begin(), this->end()), this->end());
	}
	int get(T x) {
		return lower_bound(this->begin(), this->end(), x) - this->begin();
	}
};

Index<int> idx;

struct TA {
	pair<int, int> a[MAX_N * 4];
	int n;

	void init(int _n) {
		n = _n;
		for (int i = 0; i <= n; ++i) {
			a[i] = make_pair(-1, -1);
		}
	}

	void update(int p, pair<int, int> key) {
		for (++p; p <= n; p += p & -p)
			a[p] = max(a[p], key);
	}

	pair<int, int> get(int p) {
		pair<int, int> r = make_pair(-1, -1);
		for (++p; p; p -= p & -p)
			r = max(r, a[p]);
		return r;
	}
} ta;

const int ADD = 0, QRY = 1, DEL = 2;

struct Event {
	int type, x, y, id;

	Event(int type, int x, int y, int id = -1) :
			type(type), x(x), y(y), id(id) {
	}

	bool operator<(const Event&o) const {
		if (x != o.x)
			return x < o.x;
		return type < o.type;
	}
};

void processR() {
	vector<Event> events;

	multiset<pair<int, int> > on;

	for (int i = 0; i < nVideos; ++i) {
		events.push_back(Event(ADD, videos[i].l, videos[i].l, i));
		events.push_back(Event(DEL, videos[i].r, videos[i].l, i));
	}

	for (int i = 0; i < nTVs; ++i) {
		events.push_back(Event(QRY, tvs[i].r, tvs[i].l, i));
	}

	sort(events.begin(), events.end());

	for (int i = 0; i < events.size(); ++i) {
		Event&e = events[i];
		if (e.type == ADD) {
			on.insert(make_pair(e.y, e.id));
		} else if (e.type == DEL) {
			on.erase(on.find(make_pair(e.y, e.id)));
		} else {
			if (!on.empty()) {
				pair<int, int> min_l = *on.begin();
				tvs[e.id].update(min_l.second);
			}
		}
	}
}

struct Event2 {
	int type, x, y, z, id;

	Event2(int type, int x, int y, int z, int id = -1) :
			type(type), x(x), y(y), z(z), id(id) {
	}

	bool operator<(const Event2&o) const {
		if (x != o.x)
			return x < o.x;
		return type < o.type;
	}
};

void processIn() {
	vector<Event2> events;

	ta.init(idx.size());
	int n = idx.size();

	for (int i = 0; i < nVideos; ++i) {
		events.push_back(
				Event2(ADD, videos[i].r, videos[i].l, videos[i].r - videos[i].l,
						i));
	}

	for (int i = 0; i < nTVs; ++i) {
		events.push_back(Event2(QRY, tvs[i].r, tvs[i].l, i));
	}

	sort(events.begin(), events.end());

	for (int i = 0; i < events.size(); ++i) {
		Event2&e = events[i];
		if (e.type == ADD) {
			ta.update(n - 1 - idx.get(e.y), make_pair(e.z, e.id));
		} else {
			pair<int, int> w = ta.get(n - 1 - idx.get(e.y));
			tvs[e.z].update(w.second);
//			tvs[e.z].ans = max(tvs[e.z].ans, w);
		}
	}
}

int main() {
	cin >> nVideos >> nTVs;
	for (int i = 0; i < nVideos; ++i) {
		videos[i].read();
		idx.push_back(videos[i].l);
		idx.push_back(videos[i].r);
	}
	for (int i = 0; i < nTVs; ++i) {
		tvs[i].read();
		idx.push_back(tvs[i].l);
		idx.push_back(tvs[i].r);
	}
	idx.doit();

	processR();
	for (int i = 0; i < nVideos; ++i) {
		videos[i].reflect();
	}
	for (int i = 0; i < nTVs; ++i) {
		tvs[i].reflect();
	}
	processR();
	for (int i = 0; i < nVideos; ++i) {
		videos[i].reflect();
	}
	for (int i = 0; i < nTVs; ++i) {
		tvs[i].reflect();
	}

	processIn();

	int a = -1, b = -1;
	long long ans = 0;
	for (int i = 0; i < nTVs; ++i) {
		long long upd = 1LL * tvs[i].ans * tvs[i].c;
		if (upd > ans) {
			ans = upd;
			a = tvs[i].with, b = i;
		}
	}

	cout << ans << endl;
	if (ans > 0)
		cout << a + 1 << " " << b + 1 << endl;
}