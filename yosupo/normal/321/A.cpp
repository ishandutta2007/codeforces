#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	int c = s.size();
	int xb[101], yb[101];
	int x = 0, y = 0;
	xb[0] = yb[0] = 0;
	for (int i = 1; i <= c; i++) {
		switch (s[i-1]) {
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			case 'L':
				x--;
				break;
			case 'R':
				x++;
				break;
		}
		xb[i] = x;
		yb[i] = y;
	}
	int xr = xb[c], yr = yb[c];
	for (int i = 0; i <= c; i++) {
		int xu = a - xb[i];
		int yu = b - yb[i];
		int resx, resy;
		if (xr == 0) {
			if (xu != 0) continue;
			resx = -1;
		} else if (!(xu % xr) && xu / xr >= 0) {
			resx = xu / xr;
		} else {
			continue;
		}
		if (yr == 0) {
			if (yu != 0) continue;
			resy = -1;
		} else if (!(yu % yr) && yu / yr >= 0) {
			resy = yu / yr;
		} else {
			continue;
		}
		if (min(resx, resy) == -1 || resx == resy) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}