
#include "bits/stdc++.h"
using namespace std;

bool isso(long long int a) {
	if (a == 1 || a == 0)return false;
	for (long long int i = 2; i*i <= a; ++i) {
		if ((a%i)) {
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	int n; cin >> n;
	if (isso(n)) {
		cout << 1 << endl;
		cout << n << endl;
	}
	else if (isso(n - 2)) {
		cout << 2 << endl;
		cout << n - 2 << " " << 2 << endl;
	}
	else if (isso(n - 4)) {
		cout << 3 << endl;
		cout << n - 4 << " " << 2<<" " << 2 << endl;
	}
	else {
		for (int minus = 6; true; minus += 2) {
			if (isso(n - minus)) {
				for (int num = 3; num <= minus / 2; num += 2) {
					if (isso(num) && isso(minus - num)) {
						cout << 3 << endl;
						cout << n - minus << " " << num << " " << minus - num << endl;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}