#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

typedef std::vector <int> vector;
typedef long long ll;
const int N = 1054;

int n, T, t, linear;
ll A, B, C, x, y, z, quadratic;
vector a[N];
int sum[N], vsum;
ll sqsum[N];

int main() {
	int i, j;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> T;
	for (i = 0; i < T; ++i) {
		a[i].resize(n);
		for (j = 0; j < n; ++j) {
			cin >> a[i][j], sum[i] += a[i][j];
			sqsum[i] += (ll)a[i][j] * a[i][j];
		}
		std::sort(a[i].begin(), a[i].end());
	}
	vsum = (sum[T - 1] - *sum) / (T - 1);
	for (i = 0; i < T; ++i) if (sum[i] != *sum + vsum * i) {t = i; break;}
	linear = *sum + vsum * i - sum[i];

	if (t > 2) {
		x = sqsum[0], y = sqsum[1], z = sqsum[2];
		A = x, B = (4 * y - 3 * x - z) / 2, C = (x - 2 * y + z) / 2;
	} else {
		x = sqsum[3], y = sqsum[4], z = sqsum[5];
		A = 10 * x - 15 * y + 6 * z, B = (16 * y - 9 * x - 7 * z) / 2, C = (x - 2 * y + z) / 2;
	}
	quadratic = A + t * (B + C * t) - sqsum[i];

	cout << t << ' ' << (quadratic / linear + linear) / 2 << endl;
	return 0;
}