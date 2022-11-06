#include "bits/stdc++.h"
using namespace std;

const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}


vector<Mod>memo(1e7);
vector<bool>flag(1e7, false);
vector<int>primes;
const long long int AA = 5e6;
void dfs(const long long int now,const int amax) {
	assert(!flag[now]);
	flag[now] = true;
	for (int i = 0; i <= amax; ++i) {
		long long int next = now*primes[i];
		if (next > AA)break;
		memo[next] = memo[primes[i]] * now + memo[now];
		dfs(next, i);
	}
}
int main() {
	memo[1] = 0;
	for (int i = 2; i <= 5 * 1e6; ++i) {
		if (!flag[i]) {
			primes.push_back(i);
			if (i % 2)memo[i] = Mod(i)*Mod((i - 1) / 2);
			else memo[i] = Mod(i / 2)*Mod(i - 1);
			dfs(i, primes.size()-1);
		}
	}
	int t, l, r; cin >> t >> l >> r;
	Mod ans = 0;
	Mod k = 1;
	for (int i = l; i <= r; ++i) {
		ans += k*memo[i];
		k *= Mod(t);
	}
	cout << ans << endl;
	return 0;
}