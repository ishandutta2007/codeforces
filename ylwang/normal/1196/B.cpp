#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		int cntodd = 0;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			cntodd += a[j] % 2;
		}
		if (cntodd < k || cntodd % 2 != k % 2) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int j = 0; j < n; ++j) {
			if (k == 1) break;
			if (a[j] % 2 == 1) {
				cout << j + 1 << " ";
				--k;
			}
		}
		cout << n << endl;
	}
	return 0;
}