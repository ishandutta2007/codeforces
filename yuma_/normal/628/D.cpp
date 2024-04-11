#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


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
Mod mod_pow(const Mod a, const int n) {
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
	assert(b.num != 0);
	return Mod(a) * inv(b);
}
Mod operator/=(Mod &a, const Mod b) {
	assert(b.num != 0);
	return a = a * inv(b);
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init() {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < MAX_MOD_N - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}


Mod dp[2][2000][2][2];

int main() {
	int M, D; cin >> M >> D;
	string amin, amax; cin >> amin >> amax;
	int asize = amin.size();
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2000; ++j) {
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l < 2; ++l) {
					dp[i][j][k][l] = 0;
				}
			}
		}
	}
	dp[asize%2][0][1][0] = 1;
	for (int i = asize-1; i>=0; --i) {
		int tar = i & 1, cur = tar ^ 1;
		for (int i = tar; i < tar+1; ++i) {
			for (int j = 0; j < 2000; ++j) {
				for (int k = 0; k < 2; ++k) {
					for (int l = 0; l < 2; ++l) {
						dp[i][j][k][l] = 0;
					}
				}
			}
		}
		if (i == 0)assert(tar == 0);
		for (int j = 0; j < 2000; ++j) {
			for (int mul = 0; mul < 10; ++mul) {
				const int num = mul*M + j;
				const int keta = num % 10;
				const int kuri = num / 10;
				bool ok = true;
				if (tar) {
					if (keta!=D) {
						ok = false;
					}
				}
				else {
					if (keta == D) {
						ok = false;
					}
				}
				if (ok) {
					for (int t = 0; t < 2; ++t) {
						int aa;
						if (keta > amin[i] - '0') {
							aa = 1;
						}
						else if (keta < amin[i] - '0') {
							aa = 0;
						}
						else if (keta == amin[i] - '0') {
							aa = t;
						}
						for (int l = 0; l < 2; ++l) {
							int bb;
							if (keta > amax[i] - '0') {
								bb = 1;
							}
							else if (keta < amax[i] - '0') {
								bb = 0;
							}
							else if (keta == amax[i] - '0') {
								bb = l;
							}
							dp[tar][kuri][aa][bb] += dp[cur][j][t][l];
						}
					}
				}
			}
		}
	}
	cout << dp[0][0][1][0] << endl;
	return 0;
}