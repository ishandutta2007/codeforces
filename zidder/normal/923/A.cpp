#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>


#define SS ;
typedef long long ll;
using namespace std;
int maxdiv(int n) {
	int m = n;
	int i = 2;
	int ret = n;
	while (i*i <= n) {
		if (n%i == 0) {
			ret = i;
			while (n%i == 0)
				n /= i;
		}
		i++;
	}
	if (n > 1) {
		if (n == m)
			return -1;
		return n;
	}
	return ret;
}
int main() {
	int x2;
	cin >> x2;
	int dx = maxdiv(x2);
	int ans = x2 - dx + 1;
	for (int i = 1; i < dx; i++) {
		int q = maxdiv(x2 - i);
		if (q > 0) {
			ans = min(ans, x2 - i - q + 1);
		}
	}
	cout << ans;
	SS;
	return 0;
}