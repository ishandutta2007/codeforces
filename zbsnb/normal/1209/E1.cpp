#include<iostream>
#include<algorithm>
using namespace std;

struct nod {
	int a[4],maxn;
	bool operator<(nod x) {
		return maxn < x.maxn;
	}
}e[200];

int a[5][200];
int b[4][4];
int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		if (m < 4) {
			for (int j = m + 1; j <= 4; j++) {
				for (int i = 1; i <= n; i++) {
					a[i][j] = 0;
				}
			}
			m = 4;
		}

		for (int j = 1; j <= m; j++) {
			for (int i = 0; i < 4; i++)e[j].a[i] = 0;
			e[j].maxn = 0;
			for (int i = 1; i <= n; i++) {
				e[j].a[i - 1] = a[i][j];
				e[j].maxn = max(e[j].maxn, a[i][j]);
			}
		}
		sort(e + 1, e + m + 1);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				b[i+1][j+1] = e[m - i].a[j];
			}
		}
		
		int ans = 0;
		for (int i = 0; i < (1 << 8); i++) {
			int p[5];
			p[1] = ((i&(1 << 7)) + (i & (1 << 6)))>>6;
			p[2] = ((i&(1 << 5)) + (i & (1 << 4)))>>4;
			p[3] = ((i&(1 << 3)) + (i & (1 << 2)))>>2;
			p[4] = ((i&(1 << 1)) + (i & (1 << 0)))>>0;

			//cout << i << " " << q << " " << w << " " << e << " " << r << endl;

			int maxn[5] = {};
			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j < n; j++) {
					maxn[j] = max(maxn[j], b[i][(j + p[i]) % n + 1]);
				}
			}

			//cout << i << " "; for (int i = 0; i < n; i++)cout << maxn[i] << " "; cout << endl;

			int tmp = 0;
			for (int i = 0; i < n; i++)tmp += maxn[i];
			ans = max(ans, tmp);
		}

		cout << ans << endl;
	}
}