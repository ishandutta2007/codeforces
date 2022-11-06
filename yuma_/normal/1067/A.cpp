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
Mod dp[100001][202][2];

int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];

	for(int j=0;j<=201;++j)dp[0][j][1]=1;
	for (int i = 0; i < N; ++i) {
		dp[i+1][0][0]=0;
		for (int j = 1; j <= 200; ++j) {
			for (int k = 0; k < 2; ++k) {
				dp[i+1][j][k]=dp[i+1][j-1][k];

				if (k == 0) {

					dp[i + 1][j][0] +=dp[i][j-1][0];
					dp[i+1][j][0]+=dp[i][j-1][1];
				}
				else {
					dp[i+1][j][1]+=dp[i][201][1]-dp[i][j-1][1];
					dp[i+1][j][1]+=dp[i][j][0]-dp[i][j-1][0];
				}
			}
		}
		dp[i+1][201][1]=dp[i+1][200][1];
		dp[i+1][201][0]=dp[i+1][200][0];
		if (v[i] != -1) {
			for (int j = v[i]-1; j >=0; --j) {
				for (int k = 0; k < 2; ++k) {
					if(j==v[i]-1)dp[i + 1][v[i]][k] -= dp[i + 1][j][k];
					dp[i+1][j][k]=0;
				}
			}
			for (int j = v[i]; j <= 201; ++j) {
				for (int k = 0; k < 2; ++k) {
					dp[i+1][j][k]=dp[i+1][v[i]][k];
				}
			}
		}
	}
	cout<<dp[N][201][1]<<endl;
	return 0;
}