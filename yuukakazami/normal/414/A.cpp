#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
	//x,2x
	int n, k;
	cin >> n >> k;
	if (n / 2 > k) {
		puts("-1");
		return 0;
	}
	if (k == 0) {
		if (n == 1) {
			cout << 1 << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
	}
	if (n == 1) {
		if (k == 0)
			cout << 1 << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	int here = int(1e9);
	while (n - 2 >= 2) {
		cout << here-- << " ";
		cout << here-- << " ";
		n -= 2;
		--k;
	}
	//n-2<2
	cout << k << " " << 2 * k << " ";
	n -= 2;
	if (n)
		cout << here-- << endl;
	else
		cout << endl;
}