#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back

using namespace std;

typedef long long ll;
typedef double lf;

const int maxn = 222222, maxk = 55;

lf dp[maxk][maxn];
int n, k;
ll t[maxn];
lf S[maxn], D[maxn], F[maxn];

lf f(int l, int r) {
	return S[r] - S[l] - D[l] * (F[r] - F[l]);
}

void calc(int i, int l, int r, int L, int R) {
    if (l >= r)
        return;

    int best = -1;
    int m = (l + r) / 2;

    for (int k = L; k < min(R, m); k++) {
        if (dp[i][m] > dp[i - 1][k] + f(k, m)) {
            dp[i][m] = dp[i - 1][k] + f(k, m);
            best = k;
        }
    }

    calc(i, l, m, L, best + 1);
    calc(i, m + 1, r, best, R);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> t[i];
	D[0] = 0, F[0] = 0, S[0] = 0;
	for (int i = 0; i < n; ++i) {
		D[i + 1] = D[i] + t[i];
		S[i + 1] = S[i] + D[i + 1] / t[i];
		F[i + 1] = F[i] + (1.0 / t[i]);
	}

	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = 1e100;
		}
	}
	dp[0][0] = 0;

	for (int i = 1; i <= k; ++i) {
		calc(i, 0, n + 1, 0, n);
		//for (int j = 0; j <= n; ++j) {
			//cerr << dp[i][j] << " ";
		//}
		//cerr << endl;
	}
	cout.precision(10);
	cout << fixed;
	cout << dp[k][n] << endl;
  return 0;
}