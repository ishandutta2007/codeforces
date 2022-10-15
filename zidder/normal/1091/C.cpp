#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

typedef long long ll;
using namespace std;

int n;

int main() {
	cin >> n;
	set<ll> h;
	for (size_t i = 1; i * i <= n; i++)
	{
		if (n%i != 0) {
			continue;
		}
		
		ll x = n / i;
		x = (n - n / x + 2) * x / 2 ;
		h.insert(x);

		x = i;
		x = (n - n / x + 2) * x / 2;
		h.insert(x);
	}
	for (auto i : h)
		cout << i << " ";
	return 0;
}