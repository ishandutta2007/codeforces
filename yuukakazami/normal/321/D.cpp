#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int n, k;
const int MAX_N = 33;

int a[MAX_N][MAX_N], b[MAX_N][MAX_N];

int main() {
	cin >> n;
	k = n / 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> b[i][j];
		}
	}

	int ans = 0;

	for (int msk = 0; msk < (1 << (k + 1)); ++msk) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = b[i][j];
			}
		}

		for (int i = 0; i <= k; ++i) {
			if (msk >> i & 1) {
				for (int x = k; x <= k + k; ++x) {
					for (int j = i; j <= i + k; ++j) {
						a[x][j] *= -1;
					}
				}
			}
		}

		//i,i+k+1

		int cur = 0;
		for (int i = 0; i < n; ++i) {
			cur += a[k][i];
		}

		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] += a[i + k + 1][j];
			}
		}

		for (int i = 0; i < k; ++i) {
			//i,i+k+1
			int t1 = a[i][k], t2 = -t1;
			for (int j = 0; j < k; ++j) {
				//a[i][j],a[i][j+k+1]
				int x = a[i][j], y = a[i][j + k + 1];
				t1 += max(x + y, -x - y);
				t2 += max(-x + y, x - y);
			}
			cur += max(t1, t2);
		}

		ans = max(ans, cur);
	}

	cout << ans << endl;
	return 0;
}