#include <bits/stdc++.h>
	 
const int kMaxN = 2000 + 5;
const double kEps = 1e-8;
 
int n, a, b, h[kMaxN][kMaxN];
double p[kMaxN], u[kMaxN], f[kMaxN][kMaxN];
void Update(double &x, double y, int &xh, int yh) {
	if(x < y) x = y, xh = yh;
}
double Check(double mid) {
	for(int i = 0; i <= a; ++i) f[0][i] = h[0][i] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= i && j <= a; ++j) {
			f[i][j] = f[i - 1][j]; h[i][j] = h[i - 1][j];
			Update(f[i][j], f[i - 1][j] + u[i] - mid, h[i][j], h[i - 1][j] + 1);
			if(j) {
				Update(f[i][j], f[i - 1][j - 1] + p[i], h[i][j], h[i - 1][j - 1]);
				Update(f[i][j], f[i - 1][j - 1] + p[i] + u[i] - p[i] * u[i] - mid, h[i][j], h[i - 1][j - 1] + 1);
			}
		}
	}
	return h[n][a];
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 1; i <= n; ++i) scanf("%lf", p + i);
	for(int i = 1; i <= n; ++i) scanf("%lf", u + i);
	double l = 0, r = 1;
	while(r - l > kEps) {
		double mid = (l + r) / 2;
		int tmp;
		if((tmp = Check(mid)) < b) r = mid;
		else l = mid;
	}
	printf("%.6lf", f[n][a] + l * b);
	return 0;
}