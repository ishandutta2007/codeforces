#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline ull my_rand() {
	return rnd() + rnd();
}
int prime[100005], tot;
bool not_prime[1000005];
ull w[1000005], sum[1000005];
bool banned[1000005];
void sieve(int n) {
	not_prime[1] = true;
	for (int i = 2; i <= n; ++i) {
		if (!not_prime[i]) {
			prime[++tot] = i;
		}
		for (int j = 1; j <= tot && i * prime[j] <= n; ++j) {
			not_prime[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
	for (int i = 1; i <= tot; ++i) {
		int x = prime[i];
		ull cur = my_rand();
		for (int j = x; j <= n; j += x) {
			bool f = true;
			for (int y = j / x; y % x == 0; y /= x) {
				f ^= 1;
			}
			if (f) {
				w[j] ^= cur;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] ^ w[i];
	}
}
void output() {
}
int main() {
	sieve(1000000);
	int n;
	cin >> n;
	map<ull, int> rev;
	ull all = 0;
	auto output = [&]() {
		vector<int> p;
		for (int i = 1; i <= n; ++i) {
			if (!banned[i]) {
				p.emplace_back(i);
			}
		}
		cout << p.size() << "\n";
		for (auto x : p) {
			cout << x << " ";
		}
		exit(0);
	};
	for (int i = 1; i <= n; ++i) {
		rev[sum[i]] = i;
		all ^= sum[i];
	}
	if (!all) {
		output();
	}
	if (rev.count(all)) {
		banned[rev[all]] = true;
		output();
	}
	for (int i = 1; i <= n; ++i) {
		ull x = sum[i];
		if (rev.count(all ^ x)) {
			int j = rev[all ^ x];
			banned[i] = banned[j] = true;
			output();
		}
	}
	assert(n & 1);
	banned[n] = banned[(n - 1) / 2] = banned[2] = true;	
	output();
	return 0;
}