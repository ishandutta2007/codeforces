#include <iostream>
#include <string>
#include <vector>
#define mp make_pair
#define SS ;
typedef long long ll;

using namespace std;
ll n;
ll lgg() {
	ll q = n * 2;
	int s = -1;
	while (q) {
		q /= 10;
		s++;
	}
	q = 0;
	while (s--) {
		q *= 10;
		q += 9;
	}
	return q;
}
int main() {
	cin >> n;
	if (n < 5) {
		cout << n*(n - 1) / 2;
		SS;
		return 0;
	}
	ll q = lgg();
	ll inc = q + 1;
	ll sum = 0;
	while (q < 2 * n) {
		sum += n >= q ? (q - 1) / 2 : (2 * n - q + 1) / 2;
		q += inc;
	}
	cout << sum;
	SS;
	return 0;
}