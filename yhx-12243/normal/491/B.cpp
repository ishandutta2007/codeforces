#include <bits/stdc++.h>
#define N 100034
using namespace std;

typedef long long ll;

int n, m, i, x, y, anh;
ll XY, Xy, xY, xy;
ll d, ans;

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

int main(){
	XY = Xy = xY = xy = INT_MIN; ans = INT_MAX;
	scanf("%*d%*d%d", &n);
	for(i = 1; i <= n; ++i){
		scanf("%d%d", &x, &y);
		up(XY, x + y); up(Xy, x - y); up(xY, - x + y); up(xy, - x - y);
	}
	scanf("%d", &m);
	for(i = 1; i <= m; ++i){
		scanf("%d%d", &x, &y);
		up(d = XY - (x + y), Xy - (x - y));
		up(d, xY - (- x + y));
		up(d, xy - (- x - y));
		if(d < ans) {ans = d; anh = i;}
	}
	printf("%I64d\n%d\n", ans, anh);
	return 0;
}