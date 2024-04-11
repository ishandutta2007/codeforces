# include <bits/stdc++.h>
using namespace std;
vector <long long> sols;
long long root(long long x) {
	long long low = 0, high = 3e9 + 44;
	while (low <= high) {
		long long med = (low + high) / 2;
		if (med * med == x) {
			return med;
		}
		if (med * med < x)
			low = med + 1;
		else
			high = med - 1;
	}
	return -1;
}
int S(long long x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}
int main() {
	long long n;
	scanf("%lld", &n);
	for (int s = 1; s <= 100; ++s) {
		if (s == 6) {
			cerr << s * s + 4 * n << endl;
		}
		long long r = root(s * s + 4 * n);
		if (r != -1) {
			long long e = (r - s) / 2;
			if (S(e) == s)
				sols.push_back(e);
		}
	}
	sort(sols.begin(), sols.end());
	if (sols.size())
		printf("%lld\n", sols[0]);
	else
		printf("-1\n");
}