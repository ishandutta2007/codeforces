#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MOD = int(1e9) + 9;
const int MAX_N = int(1e5) + 10;
int n, k;
pair<int, int> ps[MAX_N];

void update(vector<int>&am, const vector<int>&ch) {
	if (!ch.empty()) {
		am[1] = max(am[0] + ch[0] + 1, am[1] + max(ch[0], ch[1]));
		am[0] += max(ch[0], ch[1]);
	}
}

struct Tree {
	int x, y;
	Tree*l, *r;
	int lx, rx;
	Tree(int x, int y) :
			x(x), y(y), l(0), r(0) {
	}
	vector<int> am;
	void dfs() {
		am = vector<int>(2);
		for (int i = 0; i < 2; ++i) {
			Tree*t = i ? l : r;
			if (t) {
				t->dfs();
				update(am, t->am);
			}
		}
		lx = rx = x;
		if (l)
			lx = l->lx;
		if (r)
			rx = r->rx;
	}
	vector<int> solve(int L, int R) {
		if (L <= lx && R >= rx)
			return am;
		if (L > rx || lx > R)
			return vector<int>();
		if (L <= x && R >= x) {
			vector<int> am(2, 0);
			for (int i = 0; i < 2; ++i) {
				Tree*t = i ? l : r;
				if (t) {
					update(am, t->solve(L, R));
				}
			}
			return am;
		}
		if (L > x)
			return r->solve(L, R);
		else
			return l->solve(L, R);
	}
};

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		cin >> ps[i].first >> ps[i].second;
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = k; i < n; ++i) {
		ps[i].first = (1LL * ps[i - 1].first * a + b) % MOD;
		ps[i].second = (1LL * ps[i - 1].second * c + d) % MOD;
	}
	sort(ps, ps + n);

	vector<Tree*> stack;
	for (int i = 0; i < n; ++i) {
		Tree*t = new Tree(ps[i].first, ps[i].second);
		while (!stack.empty() && stack.back()->y < t->y)
			t->l = stack.back(), stack.pop_back();
		if (!stack.empty()) {
			stack.back()->r = t;
		}
		stack.push_back(t);
	}
	Tree*root = stack[0];
	root->dfs();
	int nQ;
	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		vector<int> am = root->solve(l, r);
		printf("%d\n", am.empty() ? 0 : max(am[0], am[1]));
	}
	return 0;
}