#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

int main() {
	long long int a, b; cin >> a >> b;
	if (a + 12> b) {
		long long int num = 1;
		long long int k = a % 10;
		for (int i = 0; i < b - a; ++i) {
			k++;
			k %= 10;
			num *= k;
		}
		cout << num % 10 << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}