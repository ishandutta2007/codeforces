#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n, k;
int s[MAX_N];

typedef long long int64;

struct Tree {
	int cnt[2];
	Tree*pl, *pr;
	int l, r;

	bool rev;

	void update() {
		for (int k = 0; k < 2; ++k) {
			cnt[k] = pl->cnt[k] + pr->cnt[k];
		}
	}

	Tree(int l, int r) :
			l(l), r(r) {
		rev = 0;
		if (l + 1 == r) {
			cnt[0] = 1;
			cnt[1] = 0;
			pl = pr = 0;
			return;
		}
		pl = new Tree(l, (l + r) >> 1);
		pr = new Tree((l + r) >> 1, r);
		update();
	}

	void apply() {
		rev ^= 1;
		swap(cnt[0], cnt[1]);
	}

	void relax() {
		if (rev) {
			pl->apply();
			pr->apply();
			rev = 0;
		}
	}

	void change(int L, int R) {
		if (L >= r || l >= R)
			return;
		if (L <= l && R >= r) {
			apply();
			return;
		}
		relax();
		pl->change(L, R);
		pr->change(L, R);
		update();
	}

	void calc(int L, int R, int c[2]) {
		if (L <= l && R >= r) {
			for (int k = 0; k < 2; ++k) {
				c[k] += cnt[k];
			}
			return;
		}
		if (L >= r || l >= R)
			return;
		relax();
		pl->calc(L, R, c);
		pr->calc(L, R, c);
	}
}*root;

vector<pair<int, int> > by[MAX_N];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	sort(s, s + n);
	for (int i = 0; i < k; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		int l = lower_bound(s, s + n, a) - s;
		int r = upper_bound(s, s + n, b) - s - 1;
		if (l > r) {
			continue;
		}
		by[l].push_back(make_pair(l, r));
		by[r + 1].push_back(make_pair(l, r));
	}

	root = new Tree(0, n);

	int64 ans = 1LL * n * (n - 1) * (n - 2) / 6;

	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < (int) by[i].size(); ++k) {
			pair<int, int> t = by[i][k];
			root->change(t.first, t.second + 1);
		}
		//calc
		int c[2];
		memset(c, 0, sizeof c);
		int tot = 0;
		if (i > 0) {
			root->calc(0, i, c);
			tot += c[0];
		}
		memset(c, 0, sizeof c);
		if (i + 1 < n) {
			root->calc(i + 1, n, c);
			tot += c[1];
		}
		ans -= 1LL * tot * (tot - 1) / 2;
	}

	cout << ans << endl;
	return 0;
}