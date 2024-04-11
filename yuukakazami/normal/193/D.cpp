#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
typedef long long int64;
int n;
const int MAX_N = int(3e5) + 10;
int p[MAX_N];
//[l,r] is valid only if their has less than 4 bad pairs :)

struct Event {
	int minL, maxL;
	int minR, maxR;
	Event() {
	}
	Event(int minL, int maxL, int minR, int maxR) :
			minL(minL), maxL(maxL), minR(minR), maxR(maxR) {
	}
};

int nE;
Event events[MAX_N * 2];
vector<Event*> byMinL[MAX_N], byMaxL[MAX_N];

struct Tree {
	Tree*pl, *pr;
	int l, r;
	int add;
	int cnt[6];

	void update() {
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < 6; ++i) {
			cnt[min(i + pl->add, 5)] += pl->cnt[i];
			cnt[min(i + pr->add, 5)] += pr->cnt[i];
		}
	}

	Tree(int l, int r) :
			l(l), r(r), add(0) {
		if (l + 1 == r) {
			memset(cnt, 0, sizeof cnt);
			cnt[0] = 1;
			return;
		}
		pl = new Tree(l, l + r >> 1);
		pr = new Tree(l + r >> 1, r);
		update();
	}

	void addIt(int L, int R, int a) {
		if (L >= r || l >= R)
			return;
		if (L <= l && R >= r) {
			add += a;
			return;
		}
		pl->addIt(L, R, a);
		pr->addIt(L, R, a);
		update();
	}

	int calc(int L, int R, int a) {
		if (L >= r || l >= R)
			return 0;
		a += add;
		if (L <= l && R >= r) {
			int ans = 0;
			for (int i = 0; i < 5; ++i) {
				if (i + a <= 4)
					ans += cnt[i];
			}
			return ans;
		}
		return pl->calc(L, R, a) + pr->calc(L, R, a);
	}
}*root;

void addEvent(int a, int b, int c, int d) {
	Event&e = events[nE++] = Event(a, b, c, d);
	byMinL[e.minL].push_back(&e);
	byMaxL[e.maxL].push_back(&e);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		--p[i];
	}
	root = new Tree(0, n);
	for (int i = 0; i + 1 < n; ++i) {
		int a = p[i], b = p[i + 1];
		if (a > b)
			swap(a, b);
		addEvent(0, a, a, b - 1);
		addEvent(a + 1, b, b, n - 1);
	}
	int a = p[0];
	addEvent(0, a, a, n - 1);
	a = p[n - 1];
	addEvent(0, a, a, n - 1);

	int64 ans = 0;
	for (int i = 0; i < n; ++i) {
		for (vector<Event*>::iterator it = byMinL[i].begin(); it != byMinL[i].end(); ++it) {
			Event*e = *it;
			root->addIt(e->minR, e->maxR + 1, 1);
		}
//		cout << i << ":" << root->calc(i, n, 0) << endl;
		ans += root->calc(i + 1, n, 0);
		for (vector<Event*>::iterator it = byMaxL[i].begin(); it != byMaxL[i].end(); ++it) {
			Event*e = *it;
			root->addIt(e->minR, e->maxR + 1, -1);
		}
	}
	cout << ans << endl;
	return 0;
}