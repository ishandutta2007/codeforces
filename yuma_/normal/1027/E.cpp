#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;






const int mod = 998244353;
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

int main() {
	int N, K; cin >> N >> K;
	vector<vector<vector<long long int>>>dp(2, vector<vector<long long int>>(N + 1, vector<long long int>(N + 1)));
	dp[1][1][1] = 1;
	for (int i = 1; i < N; ++i) {
		int cur=i%2;
		int tar=1-cur;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				dp[tar][max(j, k + 1)][k + 1] += dp[cur][j][k];
				dp[tar][max(j, k + 1)][k + 1] %= mod;
				dp[tar][j][1]                 += dp[cur][j][k];
				dp[tar][j][1] %= mod;
			}
		}
		for (int i = 0; i <= N; ++i) {
			for (int j = 0; j <= N; ++j) {
				dp[cur][i][j]=0;
			}
		}
	}
	vector<Mod>sum(N + 1);
	for (int i = 0; i <= N; ++i) {
		for (int k = 0; k <= i; ++k) {
			sum[i] += dp[N%2][i][k];
		}
	}
	Mod answer = 0;
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x*y < K&&x <= N; ++x) {
			answer += sum[y] * sum[x];
		}
	}
	cout << answer * 2 << endl;
	return 0;

}