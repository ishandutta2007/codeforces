#include "bits/stdc++.h"
#include<unordered_map> 
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;



int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : num(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) { ; }
	Mod(int n) : num((n % mod + mod) % mod) { ; }
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

Mod dp[501][501][2];

int main() {
	for (int i = 0; i < 600; ++i){
		for (int j = 0; j < 600; ++j){
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
		}
	}
	int N, M, B, aMod; cin >> N >> M >> B >> aMod;
	mod = aMod;
	vector<int>bugs;
	for (int i = 0; i < N; ++i){
		int b; cin >> b;
		bugs.push_back(b);
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < M; ++i){
		int tar = i & 1, cur = tar ^ 1;
		for (int k = 0; k < 501; ++k){
			for (int j = 0; j < 501; ++j){
				dp[k][j][cur] = 0;
			}
		}

		for (int j = 0; j < N; ++j){
			for (int k = 0; k <= B; ++k){
				dp[j + 1][k][tar] += dp[j][k][tar];
				if (k + bugs[j] <= B){ 
					dp[j][k + bugs[j]][cur] += dp[j][k][tar];
				}

			}
		}
	}
	Mod ans(0);
	for (int j = 0; j < N; ++j){
		for (int k = 0; k <= B; ++k){
			ans += dp[j][k][M & 1];

		}
	}
	cout << ans << endl;
	return 0;
}