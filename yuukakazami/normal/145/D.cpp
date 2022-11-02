#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;
const int MAX_N = int(1e5) + 10;
int a[MAX_N], n;

bool isLucky(int x) {
	while (x > 0) {
		int d = x % 10;
		if (d != 4 && d != 7)
			return false;
		x /= 10;
	}
	return true;
}

vector<int> pos;
typedef long long int64;
int nxt[MAX_N]; //next lucky number same with it

int main() {
	cin >> n;
	pos.push_back(-1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (isLucky(a[i]))
			pos.push_back(i);
	}
	int64 ans = 1ULL * (n + 2) * (n + 1) / 2 * n / 3 * (n - 1) / 4;
	for (int i = 1; i < pos.size(); ++i) {
		nxt[i] = pos.size();
		for (int j = i + 1; j < pos.size(); ++j) {
			if (a[pos[i]] == a[pos[j]]) {
				nxt[i] = j;
				break;
			}
		}
	}
	//let us calculate segment pairs which violate the conditions
	for (int i = 1; i + 1 < pos.size(); ++i) {
		set<int> s;
		s.insert(pos[i]), s.insert(n);
		int64 cur = 0, rC = pos[i + 1] - pos[i];
		for (int j = i; j > 0; --j) {
			if (nxt[j] > i) {
				for (int k = nxt[j]; k < pos.size(); k = nxt[k]) {
					set<int>::iterator pre, nxt;
					pre = nxt = s.insert(pos[k]).first;
					--pre, ++nxt;
					if (pre == s.begin()) {
						cur += 1LL * (*nxt - pos[k]) * (1LL * rC * (rC + 1) / 2 + 1LL * (pos[k] - pos[i + 1]) * rC);
					} else {
						cur += 1LL * (*nxt - pos[k]) * (pos[k] - *pre) * rC;
					}
				}
			}
			ans -= cur * (pos[j] - pos[j - 1]);
		}
	}
	cout << ans << endl;
	return 0;
}