#include<bits/stdc++.h>
using namespace std;

bool test(long long n) {
	long long sum = 0, x = n;
	while(x) {
		sum += x % 10;
		x /= 10;
	}
	return gcd(sum, n) > 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		long long n;
		cin >> n;
		while(!test(n))	n++;
		cout << n << '\n';
	}
}