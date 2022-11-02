#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long int64;

int main() {
	int n;
	cin >> n;
	int b4 = INT_MAX, b7 = 0;
	for (int n4 = 0; n4 <= n; ++n4) {
		int r = n - n4 * 4;
		if (r >= 0 && r % 7 == 0) {
			int n7 = r / 7;
			if (n4 + n7 < b4 + b7)
				b4 = n4, b7 = n7;
		}
	}
	if (b4 == INT_MAX) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < b4; ++i) {
		cout << 4;
	}
	for (int i = 0; i < b7; ++i) {
		cout << 7;
	}
	cout << endl;
	return 0;
}