#include <bits/stdc++.h>
#define N 2034
using namespace std;

const double eps = 1e-8;

int n, A, B;
double a[N], b[N], ab[N];
double L, M, R;
double f[N][N];
int g[N][N];

inline void up(double &x, const double y, int &X, const int Y) {x < y ? (x = y, X = Y) : 0;}

bool test(double k){
	int i, j;
	memset(f, 0, sizeof f); memset(g, 0, sizeof g);
	for(i = 1; i <= n; ++i)
		for(j = 0; j <= A; ++j){
			up(f[i][j], f[i - 1][j], g[i][j], g[i - 1][j]); // use nothing
			up(f[i][j], f[i - 1][j] + b[i] - k, g[i][j], g[i - 1][j] + 1); // use ball B
			if(!j) continue;
			up(f[i][j], f[i - 1][j - 1] + a[i], g[i][j], g[i - 1][j - 1]); // use ball A
			up(f[i][j], f[i - 1][j - 1] + ab[i] - k, g[i][j], g[i - 1][j - 1] + 1); // use ball A & B
		}
	return g[n][A] < B;
}

int main(){
	int i;
	scanf("%d%d%d", &n, &A, &B);
	for(i = 1; i <= n; ++i) scanf("%lf", a + i);
	for(i = 1; i <= n; ++i) scanf("%lf", b + i);
	for(i = 1; i <= n; ++i) ab[i] = 1.0 - (1.0 - a[i]) * (1.0 - b[i]);
	for(L = 0.0, R = 1.0; R - L > eps; )
		test(M = (L + R) * 0.5) ? R = M : (L = M);
	printf("%.8lg\n", f[n][A] + R * (double)B);
	return 0;
}