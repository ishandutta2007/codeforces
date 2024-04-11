#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int MAX_N = int(1e5) + 10;
typedef long long int64;
pair<int, int> a[MAX_N * 2];
int n, m;

int cnt[MAX_N * 2];

int cntp[MAX_N * 2];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[i] = make_pair(x, i);
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[n + i] = make_pair(x, i);
	}
	cin >> m;
	sort(a, a + n * 2);

	for (int i = 0, j; i < n * 2; i = j) {
		for (j = i; j < n * 2 && a[i].first == a[j].first; j++)
			continue;
		map<int, int> num;
		int tot = j - i;
		for (int k = i; k < j; ++k) {
			num[a[k].second]++;
		}
		for (int k = 1; k <= tot; ++k) {
			cnt[k]++;
		}
		for (map<int, int>::iterator it = num.begin(); it != num.end(); ++it)
			for (int k = 1; k <= it->second; ++k) {
				cnt[k]--;
			}
	}

	int64 ans = 1;
	for (int i = 1; i <= n * 2; ++i) {
		if (cnt[i] == 0)
			continue;
		int x = i;
		for (int j = 2; j * j <= x; ++j) {
			while (x % j == 0)
				cntp[j] += cnt[i], x /= j;
		}
		if (x > 1)
			cntp[x] += cnt[i];
	}
	for (int i = 1; i <= n * 2; ++i) {
		for (int j = 0; j < cntp[i]; ++j) {
			ans = ans * i % m;
		}
	}
	cout << ans << endl;
	return 0;
}