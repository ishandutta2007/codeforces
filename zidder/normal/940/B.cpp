#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define SS ;
typedef long long ll;
using namespace std;
ll n, k, A, B;

int main() {
	cin >> n >> k >> A >> B;
	ll ans = 0;
	if (k == 1)
		k = n + 1;
	while (n > 1) {
		if (n >= k) {
			if (n%k > 0) {
				ans += A * (n % k);
				n -= n % k;
			}
			else {
				if (A * (n - n / k) < B)
					ans += A*(n - n / k);
				else
					ans += B;
				n /= k;
			}
		}
		else {
			ans += (n - 1) * A;
			break;
		}
	}
	cout << ans;
	SS;
	return 0;
}