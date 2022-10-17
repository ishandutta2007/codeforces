#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int t, n[3], a[3][N];
long long ans;

inline void work(int x, int y, int z) {
	for(int i = 1; i <= n[x]; ++i) {
		long long f1 = a[x][i];
		int pos = lower_bound(a[y] + 1, a[y] + n[y] + 1, f1) - a[y];
		if(pos == n[y] + 1) continue;
		long long f2 = a[y][pos];
		int pos1 = upper_bound(a[z] + 1, a[z] + n[z] + 1, f2) - a[z] - 1;
		if(!pos1) continue;
		long long f3 = a[z][pos1];
		ans = min(ans, (f1 - f2) * (f1 - f2) + (f2 - f3) * (f2 - f3) + (f3 - f1) * (f3 - f1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	for(cin >> t; t; --t) {
		ans = LONG_LONG_MAX;
		for(int i = 0; i < 3; ++i) cin >> n[i];
		for(int i = 0; i < 3; ++i)
			for(int j = 1; j <= n[i]; ++j)
				cin >> a[i][j];
		for(int i = 0; i < 3; ++i) sort(a[i] + 1, a[i] + n[i] + 1);
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j)
				for(int k = 0; k < 3; ++k)
					if(i != j && j != k && k != i) work(i, j, k);
		cout << ans << endl;
	}
}