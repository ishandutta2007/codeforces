#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <deque>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll f(P p, ll x) {
	return p.first * x + p.second;
}

bool check(P a, P b, P c) {
	return (c.first - b.first) * (a.second - b.second) >= (b.first - a.first) * (b.second - c.second);
}
int m, p;
ll v[100100];

ll calc() {
	sort(v, v+m, greater<int>());
	ll fir = v[0];
	ll f_sm = 0, f_ma = 0;
	for (int i = 0; i < m; i++) {
		v[i] -= fir;
		v[i] *= -1;
		f_sm += v[i];
	}

	static ll dp[100100][103];
	static deque<P> cv[103];

	memset(dp, -1, sizeof(dp));
	dp[0][1] = 0;
	cv[1].push_back(P(0, 0));
	for (int i = 1; i < m; i++) {
		for (int j = p; j >= 2; j--) {
			if (cv[j-1].size() == 0) continue;


/*			for (P p: cv[j-1]) {
				dp[i][j] = max(dp[i][j], f(p, i));
			}*/

			while (cv[j-1].size() >= 2) {
				if (f(cv[j-1][0], i) > f(cv[j-1][1], i)) break;
				cv[j-1].pop_front();
			}

			dp[i][j] = f(cv[j-1][0], i);

			// bool f = false;
			// for (int k = 0; k < i; k++) {
			// 	if (dp[k][j-1] == -1) continue;
			// 	f = true;
			// 	break;
			// }
			// if (!f) continue;


			// for (int k = 0; k < i; k++) {
			// 	if (dp[k][j-1] == -1) continue;
			//  	dp[i][j] = max(dp[i][j],
			//  		dp[k][j-1] - v[k] * m + v[k] * i);
			// }

			dp[i][j] += v[i] * (m-i);
			f_ma = max(f_ma, dp[i][j]);

			P p = P(v[i], dp[i][j] - v[i] * m);

			while (cv[j].size() >= 2) {
				int cs = (int)cv[j].size();
				if (!check(cv[j][cs-2], cv[j][cs-1], p)) break;
				cv[j].pop_back();
			}

			cv[j].push_back(p);

		}
	}


	return f_sm - f_ma;
}

int main() {
	int n;
	scanf("%d %d %d", &n, &m, &p);
	static int dsm[100100];
	for (int i = 1; i < n; i++) {
		int d;
		scanf("%d", &d);
		dsm[i] = dsm[i-1] + d;
	}

	for (int i = 0; i < m; i++) {
		int h, t;
		scanf("%d %d", &h, &t);
		t -= dsm[h-1];
		v[i] = t;
	}

	cout << calc() << endl;
	return 0;
}