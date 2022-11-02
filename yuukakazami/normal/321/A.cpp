#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

bool can[400][400];

int main() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	int dx = 0, dy = 0;

	can[200 + dx][200 + dy] = true;
	for (int i = 0; i < (int) s.size(); ++i) {
		if (s[i] == 'U')
			++dy;
		else if (s[i] == 'D')
			--dy;
		else if (s[i] == 'L')
			--dx;
		else if (s[i] == 'R')
			++dx;
		can[200 + dx][200 + dy] = true;
	}

//a*dx,a*dy

	for (int ia = a - 180; ia <= a + 180; ++ia) {
		for (int ib = b - 180; ib <= b + 180; ++ib) {
			int c[2], n = 0;
			if (dx == 0) {
				if (ia != 0)
					continue;
			} else {
				if (ia % dx != 0)
					continue;
				c[n++] = ia / dx;
			}

			if (dy == 0) {
				if (ib != 0)
					continue;
			} else {
				if (ib % dy != 0)
					continue;
				c[n++] = ib / dy;
			}

			if (n == 2 && c[0] != c[1])
				continue;
			if (n > 0 && c[0] < 0)
				continue;

			int da = a - ia, db = b - ib;
			if (can[200 + da][200 + db]) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	return 0;
}