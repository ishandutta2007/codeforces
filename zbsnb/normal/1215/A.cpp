#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int main() {
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	int minn = 1e9, maxn = 0;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (i*c + j * d <= e) {
				maxn = max(maxn, i + j);
			}
		}
	}

	e -= a * (c - 1) + b * (d - 1);
	if (e < 0)e = 0;
	cout << e << " " << maxn << endl;
}