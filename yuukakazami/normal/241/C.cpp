#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 100 + 1;
const int MAX_LEN = int(1e5) + 10;

//0:floor,1:ceil
int T[MAX_LEN], F[MAX_LEN];
int Tid[MAX_LEN], Fid[MAX_LEN];

int cnt[MAX_N];

int visit(long long a, long long b, int t) {
	//visit a/b on t
	int at = a / b;
	if (t == 0) {
		if (Fid[at] != -1) {
			cnt[Fid[at]]++;
			return F[at];
		}
		if (a % b == 0 && at > 0) {
			if (Fid[at - 1] != -1) {
				cnt[Fid[at - 1]]++;
				return F[at - 1];
			}
		}
	} else {
		if (Tid[at] != -1) {
			cnt[Tid[at]]++;
			return T[at];
		}
		if (a % b == 0 && at > 0) {
			if (Tid[at - 1] != -1) {
				cnt[Tid[at - 1]]++;
				return T[at - 1];
			}
		}
	}
	return -1;
}

int main() {
	int hl, hr, n;
	cin >> hl >> hr >> n;
	memset(Tid, -1, sizeof Tid);
	memset(Fid, -1, sizeof Fid);

	for (int i = 0; i < n; ++i) {
		int v, a, b;
		char ch;
		cin >> v;
		scanf(" ");
		cin >> ch >> a >> b;
//		cout << ch << endl;
		if (ch == 'T') {
			for (int j = a; j < b; ++j) {
				Tid[j] = i;
				T[j] = v;
			}
		} else {
			for (int j = a; j < b; ++j) {
				Fid[j] = i;
				F[j] = v;
			}
		}
	}

	int ans = 0;
	for (int k = 1; k <= n; ++k) {
		long long a = hl + (k % 2 == 1 ? hr : 100 - hr) + (k - 1) * 100;
		int get = 0;
		memset(cnt, 0, sizeof cnt);
		for (int j = 1; j <= k; ++j) {
			int x = hl + (j - 1) * 100;
			//10^5*a/x
			int c = visit(100000 * x, a, (j + 1) % 2);
			if (c < 0) {
				get = -1;
				break;
			}
			get += c;
		}
		for (int i = 0; i < n; ++i) {
			if (cnt[i] > 1)
				get = -1;
		}
		ans = max(ans, get);
	}

	hl = 100 - hl;
	hr = 100 - hr;

	for (int k = 1; k <= n; ++k) {
		long long a = hl + (k % 2 == 1 ? hr : 100 - hr) + (k - 1) * 100;
		int get = 0;
		memset(cnt, 0, sizeof cnt);
		for (int j = 1; j <= k; ++j) {
			int x = hl + (j - 1) * 100;
			//10^5*x/a
			int c = visit(100000 * x, a, j % 2);
			if (c < 0) {
				get = -1;
				break;
			}
			get += c;
		}
		for (int i = 0; i < n; ++i) {
			if (cnt[i] > 1)
				get = -1;
		}
		ans = max(ans, get);
	}

	cout << ans << endl;
	return 0;
}