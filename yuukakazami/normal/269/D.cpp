#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = int(1e5) + 10;

struct Panel;

struct Panel {
	int h, l, r;
	int ans;
	void read() {
		cin >> h >> l >> r;
	}

	vector<Panel*> nxt;
};

bool cmp(Panel*a, Panel*b) {
	return a->h < b->h;
}

int n;
Panel pool[MAX_N];
Panel*ps[MAX_N];

bool ord;
const int INF = int(1e9) + 10;

Panel*up, *bottom;

struct Seg {
	map<int, Panel*> mp;
	void clear(Panel*all) {
		mp.clear();
		mp[-INF] = all;
		mp[INF] = 0;
	}

	Panel*get(int at) {
		return (--mp.upper_bound(at))->second;
	}

	void set(int l, int r, Panel*w) { //[l,r)
		Panel*old = get(r);
		for (;;) {
			map<int, Panel*>::iterator it = mp.lower_bound(l);
			if (it->first < r) {
				mp.erase(it);
			} else {
				break;
			}
		}
		mp[l] = w;
		mp[r] = old;
	}

	bool same(int l, int r, Panel*w) {
		if (get(l) != w)
			return false;
		return mp.upper_bound(l)->first >= r;
	}
};

Seg seg;

void addLink(Panel*a, Panel*b) { //up -> bottom
	if (a->h < b->h)
		swap(a, b);
	a->nxt.push_back(b);
}

void buildGraph(bool ord) {
	::ord = ord;
	seg.clear(ord ? bottom : up);

	for (int i = 0, j; i < n; i = j) {
		for (j = i; j < n && ps[i]->h == ps[j]->h; ++j)
			;
		for (int k = i; k < j; ++k) {
			Panel*me = ps[k];
			for (int ed = 0; ed < 2; ++ed) {
				int x = ed ? me->r : me->l;
				Panel*prev = seg.get(x);

				int il = max(me->l, prev->l), ir = min(me->r, prev->r);
				if (il < ir) {
					//[il,ir)
					if (seg.same(il, ir, prev)) {
						addLink(prev, me);
					}
				}
			}
		}

		for (int k = i; k < j; ++k) {
			Panel*me = ps[k];
			seg.set(me->l, me->r, me);
		}
	}
}

void relax(Panel*cur) {
	for (vector<Panel*>::iterator e = cur->nxt.begin(); e != cur->nxt.end();
			++e) {
		Panel*nxt = *e;
		int cst = min(cur->r, nxt->r) - max(cur->l, nxt->l);
		nxt->ans = max(nxt->ans, min(cur->ans, cst));
	}
}

int main() {
	int t;
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		ps[i] = pool + i;
		ps[i]->read();
	}

	up = new Panel;
	up->l = -INF, up->r = INF, up->h = INF;
	bottom = new Panel;
	bottom->l = -INF, bottom->r = INF, bottom->h = -INF;

	sort(ps, ps + n, cmp);
	buildGraph(true);
	reverse(ps, ps + n);
	buildGraph(false);

	reverse(ps, ps + n);
	up->ans = 2 * INF;
	relax(up);
	for (int i = n - 1; i >= 0; --i) {
		relax(ps[i]);
	}
	cout << bottom->ans << endl;
	return 0;
}