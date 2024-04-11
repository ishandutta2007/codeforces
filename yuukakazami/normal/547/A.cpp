#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int m;

typedef long long int64;

struct Data {
	int h, a, x, y;
	void read() {
		cin >> h >> a >> x >> y;
	}

	pair<int, int> solve() {
		vector<int> pre(m, -1);
		pre[h] = 0;
		int cur = 1;
		int cycLen;

		for (;;) {
			h = (1LL * x * h + y) % m;
			if (pre[h] != -1) {
				cycLen = cur - pre[h];
				break;
			}
			pre[h] = cur++;
		}

		if (pre[a] == -1)
			return make_pair(-1, -1);

		vector<bool> incyc(m, false);
		while (!incyc[h]) {
			incyc[h] = true;
			h = (1LL * x * h + y) % m;
		}

		if (incyc[a])
			return make_pair(pre[a], cycLen);

		if (!incyc[a])
			return make_pair(pre[a], -1);
	}

	vector<int64> generate(int M) {
		pair<int, int> ret = solve();
		vector<int64> seq;
		if (ret.first == -1)
			return seq;
		if (ret.second == -1)
			seq.push_back(ret.first);
		for (int i = 0; i < M; ++i) {
			seq.push_back(ret.first + 1LL * i * ret.second);
		}
		return seq;
	}
};

int main() {
	cin >> m;
	Data A, B;
	A.read();
	B.read();

	int M = 5 * m;

	vector<int64> LA = A.generate(M), LB = B.generate(M);

	int ia = 0, ib = 0;
	int64 ans = -1;
	while (ia < LA.size() && ib < LB.size()) {
		if (LA[ia] == LB[ib]) {
			ans = LA[ia];
			break;
		} else {
			if (LA[ia] < LB[ib])
				++ia;
			else
				++ib;
		}
	}

	cout << ans << endl;
	return 0;
}