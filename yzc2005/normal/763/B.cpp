#include <bits/stdc++.h>
using namespace std;
int main() {
	cout << "YES" << "\n";
	int n;
	cin >> n;
	while (n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int color = (x1 & 1) * 2 + (y1 & 1);
		cout << color + 1 << "\n";
	}
	return 0;
}