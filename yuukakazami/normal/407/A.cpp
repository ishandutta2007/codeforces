#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int isqrt(int x) {
	int a = sqrt(x) - 2;
	if (a < 0)
		a = 0;
	while (a * a < x)
		++a;
	if (a * a == x)
		return a;
	return -1;
}

bool checkedge(int x, int y, int xx, int yy) {
	if (x == xx || y == yy)
		return false;
	return true;
}

bool check(int x, int y, int dx, int dy) {
	int xx = x + dx, yy = y + dy;
	if (x * dx + y * dy != 0)
		return false;
	if (!checkedge(0, 0, x, y))
		return false;
	if (!checkedge(x, y, xx, yy))
		return false;
	if (!checkedge(xx, yy, 0, 0))
		return false;
	cout << "YES" << endl;
	cout << 0 << " " << 0 << endl;
	cout << x << " " << y << endl;
	cout << xx << " " << yy << endl;
	return true;
}

int main() {
	int a, b;
	cin >> a >> b;
	for (int x = 0; x <= a; ++x) {
		int y = isqrt(a * a - x * x);
		if (y == -1)
			continue;
		for (int dx = 0; dx <= b; ++dx) {
			int dy = isqrt(b * b - dx * dx);
			if (dy == -1)
				continue;
			for (int msk = 0; msk < (1 << 4); ++msk) {
				int arr[] = { x, y, dx, dy };
				for (int i = 0; i < 4; ++i) {
					if (msk >> i & 1)
						arr[i] *= -1;
				}
				if (check(arr[0], arr[1], arr[2], arr[3]))
					return 0;
			}
		}
	}
	puts("NO");
}