#include <bits/stdc++.h>
#define N 100034
#define Y 1000000
using namespace std;

const double eps = 3e-9;

int n, i, j;
int x[N], v[N];

double L, R, M;

inline void up(double &x, const double y) {x < y ? x = y : 0.0;}
inline void down(double &x, const double y) {x > y ? x = y : 0.0;}

inline bool test(double t){
	bool rev = false;
	double v0, x0, l, r;
	double li = Y, ls = 0.0, ri = Y, rs = 0.0;
	for(i = 1; i <= n; ++i){
		v0 = (double)((rev = v[i] > 0) ? v[i] : -v[i]);
		x0 = (double)(rev ? Y - x[i] : x[i]);
		if(x0 <= v0 * t) {l = 0.0; r = Y;}
		else{
			l = x0; down(r = Y, x0 / v0 * (double)*v);
			down(r, (x0 * v0 + ((double)*v * *v - v0 * v0) * t) / (double)*v);
			// x <= [x_0 v_0 + (v^2 - v_0^2) t] / v
		}
		if(l > r + eps) continue;
		rev ? down(ri, Y - r) : down(li, l);
		rev ? up(rs, Y - l) : up(ls, r);
	}
	return ceil(max(li, ri)) <= floor(min(ls, rs)) + eps;
}

int main(){
	scanf("%d%d", &n, v);
	for(i = 1; i <= n; ++i){
		scanf("%d%d%d", x + i, v + i, &j);
		j == 1 ? v[i] = -v[i] : 0;
	}
	for(L = 0.0, R = Y; R - L > eps; )
		test(M = (L + R) * 0.5) ? R = M : (L = M);
	printf("%.9lg\n", (L + R) * 0.5);
	return 0;
}