#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	long long ret = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		ret += a[i];
	}
	if (n > 1) {
		long long cur = a.back() + a[n - 2];
		ret += cur;
		for (int i = n - 3; i >= 0; --i) {
			cur += a[i];
			ret += cur;
		}
	}
	cout << ret << endl;
}