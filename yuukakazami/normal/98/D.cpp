#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n, r[20];
vector<int> sa, sb;
void doit(int a, int b, int n) {
	for (int i = 0; i < n; ++i) {
		sa.push_back(a), sb.push_back(b);
	}
}

void rec(int i, int a, int b, int c, bool ord) {
	//a->c , b for temp ord means what order we want for the same radius
	//just yy , can't prove :(
	if (i == n)
		return;
	int j;
	for (j = i; j < n && r[j] == r[i]; ++j)
		;
	int cnt = j - i;
	if (j == n && ord) {
		doit(a, b, cnt - 1);
		doit(a, c, 1);
		doit(b, c, cnt - 1);
		return;
	}
	if (j == i + 1 || !ord) {
		rec(j, a, c, b, false);
		doit(a, c, cnt);
		rec(j, b, a, c, false);
	} else {
		rec(j, a, b, c, false);
		doit(a, b, cnt);
		rec(j, c, b, a, false);
		doit(b, c, cnt);
		rec(j, a, b, c, true);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	rec(0, 1, 2, 3, true);
	printf("%d\n", sa.size());
	for (int i = 0; i < sa.size(); ++i) {
		printf("%d %d\n", sa[i], sb[i]);
	}
	return 0;
}