#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
using namespace std;

const int MAX_N = 100000 + 10;
const int MAX_V = 10000 + 10;
const int MAX_SIZE = 400;

int n, m;
int a[MAX_N];

bool isLucky(int x) {
	while (x) {
		int d = x % 10;
		if (d != 4 && d != 7)
			return false;
		x /= 10;
	}
	return true;
}

bool is[MAX_V];
int num[MAX_SIZE];
int id[MAX_N];
int size;

void add(int i, int d) {
	int o = is[a[i]];
	int c = is[a[i] += d];
	num[id[i]] += c - o;
}

int main() {
	cin >> n >> m;
	size = 1;
	while (size * size < n)
		++size;
	for (int i = 0; i < MAX_V; ++i) {
		is[i] = isLucky(i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		id[i] = i / size;
		num[id[i]] += is[a[i]];
	}
	for (int i = 0; i < m; ++i) {
		char buf[10];
		scanf(" ");
		scanf("%s", buf);
		if (buf[0] == 'c') { //count
			int l, r;
			scanf("%d%d", &l, &r), --l, --r;
			int sl = l / size, sr = r / size;
			int ret = 0;
			if (sl == sr) {
				for (int j = l; j <= r; ++j) {
					ret += is[a[j]];
				}
			} else {
				for (int j = l; j < (sl + 1) * size; j++)
					ret += is[a[j]];
				for (int j = sl + 1; j < sr; ++j) {
					ret += num[j];
				}
				for (int j = sr * size; j <= r; ++j) {
					ret += is[a[j]];
				}
			}
			printf("%d\n", ret);
		} else {
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d), --l, --r;
			for (int a = l; a <= r; ++a) {
				add(a, d);
			}
		}
	}
	return 0;
}