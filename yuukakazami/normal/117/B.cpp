#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
using namespace std;
typedef long long int64;

int main() {
	int64 a, b, m;
	cin >> a >> b >> m;
	int64 MOD = int64(1e9);
	for (int i = 0; i < m && i <= a; ++i) {
		if ((m - i) * MOD % m > b) {
			cout << 1 << " ";
			printf("%09d", i);
			return 0;
		}
	}
	cout << 2 << endl;
	return 0;
}