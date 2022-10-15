#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>


#define SS ;
typedef long long ll;
using namespace std;
ll ff(ll x,ll n) {
	if (x % 2 == 0)
		return x / 2;
	if (n % 2 == 0)
		return ff((x - 1) / 2, n / 2) + n / 2;
	return ff(x + 2, n + 1) - 1;
}
int main() {
	ll n;
	ll q;
	cin >> n >> q;
	for (size_t i = 0; i < q; i++)
	{
		ll x;
		cin >> x;
		cout << ff(x - 1, n) + 1 << " ";
	}
	SS;
	return 0;
}