#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;

struct Tree {
	Tree*pl, *pr;
	int l, r;
	int cnt[26];

	int same;

	void apply(int s) {
		same = s;
		memset(cnt, 0, sizeof cnt);
		cnt[same] = r - l;
	}

	void relax() {
		if (same != -1 && pl) {
			pl->apply(same);
			pr->apply(same);
			same = -1;
		}
	}

	void update() {
		for (int i = 0; i < 26; ++i) {
			cnt[i] = pl->cnt[i] + pr->cnt[i];
		}
	}

	Tree(int _l, int _r, char buf[]) :
			l(_l), r(_r) {
		same = -1;
		if (l + 1 == r) {
			memset(cnt, 0, sizeof cnt);
			cnt[buf[l] - 'a']++;
			pl = pr = 0;
			return;
		}
		pl = new Tree(l, l + r >> 1, buf);
		pr = new Tree(l + r >> 1, r, buf);
		update();
	}

	void collect(int L, int R, int my[]) {
		if (L >= r || l >= R)
			return;
		if (L <= l && R >= r) {
			for (int i = 0; i < 26; ++i) {
				my[i] += cnt[i];
			}
			return;
		}
		relax();
		pl->collect(L, R, my);
		pr->collect(L, R, my);
	}

	void makeSame(int L, int R, int s) {
		if (L >= r || l >= R)
			return;
		if (L <= l && R >= r) {
			apply(s);
			return;
		}
		relax();
		pl->makeSame(L, R, s);
		pr->makeSame(L, R, s);
		update();
	}
	void restore(char buf[]) {
		if (l + 1 == r) {
			for (int i = 0; i < 26; ++i) {
				if (cnt[i] == 1) {
					buf[l] = 'a' + i;
					break;
				}
			}
			return;
		}
		relax();
		pl->restore(buf);
		pr->restore(buf);
	}
}*root;
int n, m;
char buf[MAX_N];

void doit(int l, int r) {
	static int cnt[26];
	memset(cnt, 0, sizeof cnt);
	root->collect(l, r + 1, cnt);
	int nOdd = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] % 2 == 1)
			++nOdd;
	}
	int len = r - l + 1;
	if (nOdd > 1)
		return;
	if (nOdd != len % 2)
		return;
	int who = -1;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] % 2 == 1) {
			who = i;
			break;
		}
	}
	if (who != -1)
		cnt[who]--;
	int cur = l;
	for (int i = 0; i < 26; ++i) {
		int a = cnt[i] / 2;
		if (a > 0) {
			root->makeSame(cur, cur + a, i);
		}
		cur += a;
	}
	if (who != -1) {
		root->makeSame(cur, cur + 1, who);
		cur += 1;
	}
	for (int i = 26 - 1; i >= 0; --i) {
		int a = cnt[i] / 2;
		if (a > 0) {
			root->makeSame(cur, cur + a, i);
		}
		cur += a;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	scanf(" ");
	scanf("%s", buf);
	root = new Tree(0, n, buf);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		doit(l - 1, r - 1);
	}
	root->restore(buf);
	buf[n] = 0;
	puts(buf);
	return 0;
}