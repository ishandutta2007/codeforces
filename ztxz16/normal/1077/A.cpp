#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int test;

int main() {
	scanf("%d", &test);
	while (test--) {
		long long a, b, k;
		cin >> a >> b >> k;
		if (k % 2 == 1) {
			cout << (a - b) * (k / 2) + a << endl;
		} else {
			cout << (a - b) * (k / 2) << endl;
		}
	}
	
	return 0;
}