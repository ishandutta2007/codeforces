#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
typedef long long int64;
int n;

int main() {
	int ans = 1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int k, a;
		cin >> k >> a;
		int pw = 1;
		while ((1LL << (pw * 2)) < a)
			++pw;
		ans = max(ans, k + pw);
	}
	cout << ans << endl;
	return 0;
}