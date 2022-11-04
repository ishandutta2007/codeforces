#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define left LEFT
#define right RIGHT
#define next NEXT
#define mp make_pair

int FASTBUFFER;

using namespace std;

const int N = 500005;

int n;
pair <int, int> A[N];
int left[N << 2], right[N << 2], ans[N << 2], tag[N << 2];
int succ[N], next[N], a[N], f[N];
pair <int, pair <int, pair <int, int> > > g[N];

void add(int a, pair <int, int> b) {
	for (int i = a; i <= n; i += (i & -i)) {
		A[i] = max(A[i], b);
	}
}

pair <int, int> ask(int a) {
	pair <int, int> ret = A[a];
	for (int i = a; i; i -= (i & -i)) {
		ret = max(ret, A[i]);
	}
	
	return ret;
}

map <int, int> pos;

void make(int l, int r, int i) {
	int mid = (l + r) >> 1;
	left[i] = l, right[i] = r, ans[i] = tag[i] = 0;
	if (l == r) {
		return;
	}
	
	make(l, mid, (i << 1));
	make(mid + 1, r, ((i << 1) | 1));
}

void up(int i) {
	int lc = (i << 1), rc = (lc | 1);
	ans[i] = max(ans[lc], ans[rc]);
}

void down(int i) {
	int lc = (i << 1), rc = (lc | 1), x = tag[i];
	ans[lc] = max(ans[lc], x);
	ans[rc] = max(ans[rc], x);
	tag[lc] = max(tag[lc], x);
	tag[rc] = max(tag[rc], x);
	tag[i] = 0;
}

void work(int l, int r, int i, int type, int &v) {
	if (l > right[i] || r < left[i]) {
		return;
	}
	
	if (l <= left[i] && r >= right[i]) {
		if (type == 1) {
			v = max(v, ans[i]);
		} else {
			ans[i] = max(ans[i], v);
			tag[i] = max(tag[i], v);
		}
		
		return;
	}
	
	down(i);
	work(l, r, (i << 1), type, v);
	work(l, r, ((i << 1) | 1), type, v);
	up(i);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		succ[i] = pos[a[i]];
		next[succ[i]] = i;
		pos[a[i]] = i;
	}
	
	make(1, n, 1);
	int sel = 0;
	for (int i = 1; i <= n; i++) {
		if (succ[i] == 0) {
			continue;
		}
		
		int x = succ[i], y = succ[x], z = succ[y];
		if (z) {
			pair <int, int> ret = ask(z - 1);
			f[i] = ret.first + 1;
			g[i] = mp(ret.second, mp(z, mp(y, x)));
		}
		
		int now = 0;
		work(x, x, 1, 1, now);
		if (now != 0) {
			int z = now, y = next[z];
			pair <int, int> ret = ask(z - 1);
			if (ret.first + 1 > f[i]) {
				f[i] = ret.first + 1;
				g[i] = mp(ret.second, mp(now, mp(x, y)));
			}
		}
		
		work(x + 1, i - 1, 1, 2, x);
		if (f[i] > f[sel]) {
			sel = i;
		}
		
		add(i, make_pair(f[i], i));
	}
	
	printf("%d\n", f[sel] * 4);
	vector <int> ans;
	while (f[sel]) {
		ans.push_back(sel);
		ans.push_back(g[sel].second.second.second);
		ans.push_back(g[sel].second.second.first);
		ans.push_back(g[sel].second.first);
		sel = g[sel].first;
	}
	
	for (int i = (int)ans.size() - 1; i >= 0; i--) {
		printf("%d ", a[ans[i]]);
	}
	
	printf("\n");
	return 0;
}