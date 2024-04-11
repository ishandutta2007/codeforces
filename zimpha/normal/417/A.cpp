#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int c, d, n, m, k;
	cin >> c >> d >> n >> m >> k;
	int rest = n * m - k;
	int a = min((int)ceil((double)rest / n) * c, rest / n * c + rest % n * d);
	int b = rest * d;
	if (rest <= 0) cout << 0 << endl;
	else cout << min(a, b) << endl;
}