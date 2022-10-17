#include <bits/stdc++.h>
#define LL long long

const long double PI = 3.1415926535897932384626;
const int N = 1e5 + 5;

int n, ansx, ansy;
long double ans = 1e9;

int quad(int x, int y) {
	if(x > 0 && y > 0) return 1;
	else if(x == 0 && y > 0) return 2;
	else if(x < 0 && y > 0) return 3;
	else if(x < 0 && y == 0) return 4;
	else if(x < 0 && y < 0) return 5;
	else if(x == 0 && y < 0) return 6;
	else if(x > 0 && y < 0) return 7;
	else if(x > 0 && y == 0) return 8;
} // 

struct POINT {
	int id, x, y;
	long double deg;
	bool operator<(const POINT &rhs) const {
		int quad1 = quad(x, y), quad2 = quad(rhs.x, rhs.y);
		if(quad1 != quad2)
			return quad1 < quad2;
		else
			return y * rhs.x < x * rhs.y; // 
	}
} p[N];

int32_t main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d", &p[i].x, &p[i].y);
		p[i].id = i;
		p[i].deg = std::atan2(1.0 * p[i].y, 1.0 * p[i].x);
		if(p[i].deg < 0)
			p[i].deg += 2 * PI;
	}
	std::sort(p + 1, p + n + 1);
	p[0] = p[n];
	for(int i = 1; i <= n; ++i) {
		long double cur_ans = p[i].deg - p[i - 1].deg;
		if(cur_ans < 0)
			cur_ans += 2 * PI;
		if(cur_ans < ans) {
			ans = cur_ans;
			ansx = p[i].id, ansy = p[i - 1].id;
		}
	}
	printf("%d %d", ansx, ansy);
    return 0;
}