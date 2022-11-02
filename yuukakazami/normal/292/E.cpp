#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <map>
#include <utility>
#define VAL(x,c) __typeof(c) x=c
using namespace std;
using namespace __gnu_cxx;

const int MAX_N = int(1e5) + 10;
int n, m;
int a[MAX_N], b[MAX_N];

struct Segment {
	int l, r;
	int*a;
	Segment(int l, int r, int*a) :
			l(l), r(r), a(a) {
	}
	Segment() {
	}

	int get(int x) {
		return a[x - l];
	}
};

map<int, Segment> mp;

Segment get(int x) {
	return (--mp.upper_bound(x))->second;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
	}

	mp[0] = Segment(0, n, b);
	mp[n] = Segment(0, n, b);

	for (int i = 0; i < m; ++i) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			int x, y, k;
			scanf("%d%d%d", &x, &y, &k);
			--x, --y;
			Segment key = Segment(y, y + k, a + x);

			int l = y, r = y + k;
			Segment old = get(r);
			for (;;) {
				VAL(it, mp.lower_bound(l));
				if (it->first < r) {
					mp.erase(it);
				} else {
					break;
				}
			}
			mp[l] = key;
			mp[r] = old;

		} else {
			int x;
			scanf("%d", &x);
			--x;
			Segment key = get(x);
			printf("%d\n", key.get(x));
		}
	}
}