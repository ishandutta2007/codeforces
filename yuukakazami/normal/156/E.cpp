#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 10000 + 10;
const int MAX_M = 30000 + 10;

typedef long long ll;
ll a[MAX_N];
int n, m;

int d[MAX_M], ans[MAX_M];
ll c[MAX_M];
string pat[MAX_M];

int dp[10000000];

int mod;

vector<int> ps;

int myPow(int a, int b) {
	int r = 1;
	for (int i = 0; i < b; ++i) {
		r *= a;
	}
	return r;
}

int get(char ch) {
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	return ch - 'A' + 10;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> d[i] >> pat[i] >> c[i];
	}

	for (int i = 2; i <= 100; ++i) {
		bool chk = true;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0)
				chk = false;
		}
		if (chk)
			ps.push_back(i);
	}

	memset(ans, -1, sizeof ans);

	for (int d = 2; d <= 16; ++d) {
		int len = 0;
		int x = n;
		while (x > 0) {
			++len;
			x /= d;
		}

		int total = myPow(d + 1, len);

		for (int pi = 0, pj; pi < ps.size(); pi = pj) {
			pj = pi;
			mod = 1;
			while (pj < ps.size() && mod * ps[pj] <= 10000)
				mod *= ps[pj++];

			for (int i = 0; i < total; ++i) {
				static int ds[100];
				int x = i;

				int at = -1;

				for (int j = len - 1; j >= 0; --j) {
					ds[j] = x % (d + 1);
					x /= d + 1;
					if (ds[j] == d) {
						at = j;
						break;
					}
				}

				if (at != -1) {
					int pw = myPow(d + 1, len - 1 - at);
					dp[i] = 1;
					for (int j = 1; j <= d; ++j) {
						dp[i] = dp[i] * dp[i - j * pw] % mod;
					}
				} else {
					int orig = 0;
					for (int j = 0; j < len; ++j) {
						orig = orig * d + ds[j];
					}
					if (orig < n)
						dp[i] = a[orig] % mod;
					else
						dp[i] = 1;
				}
			}

			for (int i = 0; i < m; ++i) {
				if (::d[i] == d && ans[i] == -1) {
					string p = pat[i];
					bool chk = true;
					if (p.length() > len) {
						for (int i = 0; i < p.length() - len; ++i) {
							if (p[i] == '?')
								p[i] = '0';
							if (p[i] != '0')
								chk = false;
						}
						p = p.substr(p.length() - len);
					}
					if (!chk)
						continue;
					while (p.length() < len)
						p = "0" + p;

					int mask = 0;
					for (int i = 0; i < p.length(); ++i) {
						mask = mask * (d + 1) + (p[i] == '?' ? d : get(p[i]));
					}

					for (int k = pi; k < pj; ++k) {
						if ((dp[mask] + c[i]) % ps[k] == 0) {
							ans[i] = ps[k];
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}