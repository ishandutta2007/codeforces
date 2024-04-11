#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;



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

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

long long int memo[500][500];

int main() {
	memo[1][1] = 1;
	for (int i = 0; i < 500; ++i) {
		memo[i][0] = 1;
	}
	for (int i = 2; i <=400; ++i) {
		for (int j = 1; j < 500; ++j) {
			memo[i][j] = 0;
			
			for (int k = 0; k <= j; ++k) {
				long long int plus = memo[i - 1][k] * memo[i - 1][j - k];
				plus %= mod;
				plus *= (4 * k + 1);
				plus %= mod;
				memo[i][j] += plus;
			}

			for (int k = 0; k < j; ++k) {
				long long int plus = memo[i - 1][k] * memo[i - 1][j - k-1];
				plus %= mod;
				plus *= 1;
				plus %= mod;
				memo[i][j] += plus;
			}
			for (int k = 0; k <=j+1; ++k) {
				long long int plus = memo[i - 1][k] * memo[i - 1][j - k + 1];
				plus %= mod;
				plus *= 2*k*(k-1)+2*k*(j-k+1);
				memo[i][j] += plus;
			}
			//   x
			//   
			//for (int k = 0; k <= j; ++k) {
			//	memo[i][j] += memo[i - 1][k] * memo[i - 1][j - k];
			//}

			////   o
			////  
			//for (int k = 0; k < j; ++k) {
			//	memo[i][j] += memo[i - 1][k] * memo[i - 1][j - k-1];
			//}

			////   o
			////  /
			//for (int k =0; k <= j; ++k) {
			//	memo[i][j] += Mod(2)*Mod(k)*memo[i - 1][k] * memo[i - 1][j - k];
			//}

			////   o
			////    |
			//for (int k = 0; k <= j; ++k) {
			//	memo[i][j] += Mod(2)*Mod(j-k)*memo[i - 1][k] * memo[i - 1][j-k];
			//}

			////   o
			////  / |
			//for (int k = 0; k <= j+1; ++k) {
			//	memo[i][j] += Mod(2)*Mod(k)*Mod(j-k+1)*memo[i - 1][k] * memo[i - 1][j-k+1];
			//}

			////   o
			//// //
			//for (int k = 1; k <= j + 1; ++k) {
			//	memo[i][j] += Mod(k)*Mod(k - 1)*memo[i - 1][k] * memo[i-1][j - k + 1];
			//}
			////   o
			////    ||
			//for (int k = 0; k <= j + 1; ++k) {
			//	memo[i][j] += Mod(j-k+1)*Mod(j-k)*memo[i - 1][k] * memo[i - 1][j - k + 1];
			//}
			memo[i][j] %= mod;
		}
	}
	int N; cin >> N;
	cout << memo[N][1] << endl;
	return 0;
}