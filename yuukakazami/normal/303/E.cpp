#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
using namespace std;

const int MAX_N = 80 + 10;

int l[MAX_N], r[MAX_N], n;

double pl[MAX_N], pr[MAX_N], pm[MAX_N];
int who[MAX_N], cnt, shift;

double ret[MAX_N][MAX_N][MAX_N];

//small,in

void add(double dp[MAX_N][MAX_N], double nxt[MAX_N][MAX_N], int me) {
	double l = pl[me], r = pr[me], m = pm[me];
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; i + j < cnt; ++j) {
			nxt[i][j] = 0;
		}
	}
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; i + j < cnt; ++j) {
			double c = dp[i][j];
			nxt[i + 1][j] += c * l;
			nxt[i][j + 1] += c * m;
			nxt[i][j] += c * r;
		}
	}
}

void copy(double src[MAX_N][MAX_N], double dst[MAX_N][MAX_N]) {
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; i + j < cnt; ++j) {
			dst[i][j] = src[i][j];
		}
	}
}

void add(double dp[MAX_N][MAX_N], double nxt[MAX_N][MAX_N], int l, int r) {
	double tmp[MAX_N][MAX_N];
	copy(dp, tmp);

	for (int i = l; i < r; ++i) {
		add(tmp, nxt, i);
		copy(nxt, tmp);
	}
}

void rec(int l, int r, double dp[MAX_N][MAX_N]) {
	if (l + 1 == r) {
		for (int i = 0; i < cnt; ++i) {
			for (int j = 0; i + j < cnt; ++j) {
				ret[who[l]][i + shift][j] += pm[l] * dp[i][j];
			}
		}
		return;
	}

	double nxt[MAX_N][MAX_N];
	int m = l + r >> 1;
	add(dp, nxt, l, m);
	rec(m, r, nxt);
	add(dp, nxt, m, r);
	rec(l, m, nxt);
}

void doit(int x) {
	double dp[MAX_N][MAX_N][MAX_N] = { };
	int cur = 0;
	dp[0][0][0] = 1;
	for (int i = 0; i < cnt; ++i) {
		if (i != x) {
			add(dp[cur], dp[cur + 1], i);
			++cur;
		}
	}
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; i + j < cnt; ++j) {
			ret[who[x]][i + shift][j] += pm[x] * dp[cur][i][j];
		}
	}
}

void calc(int L, int R) {
	shift = 0;
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (l[i] <= L && r[i] >= R) {
			who[cnt] = i;
			double tot = r[i] - l[i];
			pm[cnt] = (R - L) / tot;
			pl[cnt] = (L - l[i]) / tot;
			pr[cnt] = (r[i] - R) / tot;
			++cnt;
		} else if (r[i] <= L)
			++shift;
	}
	if (cnt == 0)
		return;

	double dp[MAX_N][MAX_N] = { };
	dp[0][0] = 1;
	rec(0, cnt, dp);
}

double ans[MAX_N][MAX_N];

int main() {
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		v.push_back(l[i]);
		v.push_back(r[i]);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i + 1 < v.size(); ++i) {
		if (v[i] < v[i + 1]) {
			calc(v[i], v[i + 1]);
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = 0.0;
	for (int i = 0; i < n; i++)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n - x; y++)
				for (int z = 0; z <= y; z++)
					ans[i][x + z] += ret[i][x][y] / (y + 1);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%0.10lf ", ans[i][j]);
		}
		puts("");
	}
}