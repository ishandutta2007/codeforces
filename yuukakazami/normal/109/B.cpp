#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long int64;
vector<int> ls;

void rec(int64 cur) {
	if (cur > 1e9)
		return;
	ls.push_back(cur);
	rec(cur * 10 + 4);
	rec(cur * 10 + 7);
}

int64 isII(int64 l, int64 r, int64 L, int64 R) {
	return max(min(r, R) - max(l, L) + 1, 0LL);
}

int main() {
	rec(0);
	ls.push_back(INT_MAX);
	sort(ls.begin(), ls.end());
	int64 l, r, L, R, k;
	cin >> l >> r >> L >> R >> k;
	int64 cnt = 0;
	for (int i = 1; i < ls.size() - 1; ++i) {
		int j = i + k - 1;
		if (j < ls.size() - 1) {
			{
				int64 A = isII(ls[i - 1] + 1, ls[i], l, r);
				int64 B = isII(ls[j], ls[j + 1] - 1, L, R);
				cnt += A * B;
			}
			{
				int64 A = isII(ls[i - 1] + 1, ls[i], L, R);
				int64 B = isII(ls[j], ls[j + 1] - 1, l, r);
				cnt += A * B;
			}
			if (k == 1) {
				if (l <= ls[i] && ls[i] <= r && L <= ls[i] && ls[i] <= R)
					--cnt;
			}
		}
	}
	double ans = 1.0 * cnt / ((r - l + 1) * (R - L + 1));
	printf("%0.10lf\n", ans);
	return 0;
}