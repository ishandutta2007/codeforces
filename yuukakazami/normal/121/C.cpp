#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int64;
int64 n, k;
vector<int64> ls;
void rec(int64 cur) {
	if (cur > n)
		return;
	if (cur > 0)
		ls.push_back(cur);
	rec(cur * 10 + 4);
	rec(cur * 10 + 7);
}

vector<int64> buildKth(vector<int64> a, int64 k) {
	sort(a.begin(), a.end());
	if (!k)
		return a;
	int64 step = 1;
	for (int i = 1; i < a.size(); ++i) {
		step *= i;
	}
	int64 cnt = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (k < step) {
			swap(a[0], a[i]);
			vector<int64> tmp = buildKth(vector<int64>(a.begin() + 1, a.end()), k);
			tmp.insert(tmp.begin(), a[0]);
			return tmp;
		} else {
			k -= step;
		}
	}
}

bool isL(int x) {
	while (x) {
		int d = x % 10;
		if (d != 4 && d != 7)
			return false;
		x /= 10;
	}
	return true;
}

int bf(int n, int k) {
	vector<int> a;
	for (int i = 1; i <= n; ++i) {
		a.push_back(i);
	}
	while (k > 0) {
		--k;
		next_permutation(a.begin(), a.end());
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (isL(i + 1) && isL(a[i]))
			++ans;
	}
	return ans;
}

int main() {
	cin >> n >> k;
	--k;
	rec(0);
	sort(ls.begin(), ls.end());
	if (k == 0) {
		cout << ls.size() << endl;
		return 0;
	}
	for (int diffAt = n - 1; diffAt >= 1; --diffAt) {
		int64 cnt = 1;
		for (int j = 1; j <= n - diffAt + 1; ++j) {
			cnt *= j;
		}
		if (k < cnt) {
			int64 ans = 0;
			for (int k = 0; k < ls.size(); ++k) {
				if (ls[k] < diffAt)
					++ans;
			}
			vector<int64> rem;
			for (int i = diffAt; i <= n; ++i) {
				rem.push_back(i);
			}
			rem = buildKth(rem, k);
			for (int i = diffAt; i <= n; ++i) {
				if (isL(i) && isL(rem[i - diffAt]))
					++ans;
			}
			cout << ans << endl;
			return 0;
		}
	}

	cout << "-1" << endl;
	return 0;
}