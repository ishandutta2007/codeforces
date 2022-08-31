#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <deque>

using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll result = 0;
	while (n) {
		ll nb = n;
		ll b = 0;
		while (nb) {
			b = max(nb%10, b);
			nb /= 10;
		}
		n -= b;
		result++;
	}
	cout << result << endl;
	return 0;
}