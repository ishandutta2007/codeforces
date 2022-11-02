#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

int extgcd(int a, int b, int&x, int&y) {
	if (b == 0) {
		return x = 1, y = 0, a;
	}
	int d = extgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}
const int INF = ~0U >> 1;

int doit(int x, int d, int v) {
	//first x+ad>=v
	if (x > v) {
		x -= (x - v) / d * d;
	} else {
		x += (v - x) / d * d;
		if (x < v)
			x += d;
	}
	return x;
}
int c3, c4, c5, sum;

int get(int y) {
	return (sum - c5 * y) / c3;
}

int xs[100], cnt = 0;
int x, stepx, y, stepy;
void addx(int a) {
	int x = doit(::x, stepx, a);
	xs[cnt++] = x;
	xs[cnt++] = x - stepx;
}

void addy(int a) {
	int y = doit(::y, stepy, a);
	xs[cnt++] = get(y);
	xs[cnt++] = get(y - stepy);
}

int main() {
	int n, m;
	cin >> n >> m;
	{
		int cnt[6] = { };
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		c3 = cnt[3], c4 = cnt[4], c5 = cnt[5];
	}
//	cout << c3 << " " << c4 << " " << c5 << endl;
	int ans[4] = { INF, 0, 0, 0 };
	for (int w4 = 0; w4 * c4 <= m; ++w4) {
		int A = w4 * c4;
		//w3c3+w4c4+w5c5 //w3<=w4<=w5
		//|w3c3-w4c4|+|w4c4-w5c5|
		//fix w4
		//|w3c3-A|+|w5c5-A|
		//w3c3>=A && w5c5>=A
		sum = m - A;
		int d = extgcd(c3, c5, x, y);
		if (sum % d != 0) {
			continue;
		}
		x *= sum / d, y *= sum / d;
		//c3x+c5y=sum
		stepx = c5 / d, stepy = c3 / d;
//		cout << c3 << " " << x << " " << c5 << " " << y << " " << sum << endl;
//		cout << x << " " << stepx << endl;
		cnt = 0;
		addx(w4), addx(A / c3), addx(0), addx(sum / c3);
		addy(w4), addy(A / c5), addy(0), addy(sum / c5);
		for (int i = 0; i < cnt; ++i) {
			int w3 = xs[i];
			int w5 = (sum - w3 * c3) / c5;
//			cout << w3 << endl;
			assert((sum-w3*c3)%c5==0);
			if (w3 <= w4 && w4 <= w5 && w3 >= 0) {
				int by = abs(w3 * c3 - A) + abs(A - w5 * c5);
				if (by < ans[0]) {
					int tmp[4] = { by, w3, w4, w5 };
					memcpy(ans, tmp, sizeof ans);
				}
			}
		}
	}
	if (ans[0] == INF) {
		puts("-1");
	} else {
		for (int i = 1; i <= 3; ++i) {
			printf("%d ", ans[i]);
		}
		puts("");
	}
	return 0;
}