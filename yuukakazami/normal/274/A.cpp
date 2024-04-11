#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int n, k;
const int MAX_N = int(1e5) + 10, MAX_VALUE = int(1e9);
int a[MAX_N];

map<int, int> id;
bool used[MAX_N];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];

	}
	if (k == 1) {
		cout << n << endl;
		return 0;
	}

	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		id[a[i]] = i;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			int x = a[i];
			int cnt = 0;
			while (id.count(x)) {
				used[id[x]] = true;
				++cnt;
				if (1LL * x * k > MAX_VALUE)
					break;
				x *= k;
			}
			ans += (cnt + 1) / 2;
		}
	}
	cout << ans << endl;
	return 0;
}