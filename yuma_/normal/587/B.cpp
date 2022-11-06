#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

const int My_Inf=2147483647;
const long long int My_LInf=9223372036854775807;



const int mod = 1000000007;
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
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
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

Mod dp[2][1000100];

int main() {
	long long int L;
	int N, K; cin >> N >> L >> K;
	vector<int>nums;
	for (int i = 0; i < N; ++i) {
		int a; scanf("%d", &a);
		nums.emplace_back(a);
	}
	vector<int>aset(nums);
	sort(aset.begin(), aset.end());
	aset.resize(unique(aset.begin(), aset.end()) - aset.begin());
	for (int i = 0; i < nums.size(); ++i) {
		nums[i] = lower_bound(aset.begin(), aset.end(), nums[i]) - aset.begin();
	}
	const int NN = aset.size();
	for (int j = 0; j < N; ++j) {
		dp[0][j] = 1;
	}
	const int amari = L%N;
	const int repeat_num = L / N;
	Mod ans(0);
	for (int i = 1; i <= K; ++i) {
		int tar = i & 1, cur = tar ^ 1;
		if (i == 0)assert(tar == 0&&cur==1);
		for (int j = 0; j < NN + 1; ++j) {
			dp[tar][j] = 0;
		}
		for (int j = 0; j < N; ++j) {
			dp[tar][nums[j]] += dp[cur][nums[j]];
			long long int len = L / N + (j < amari);
			if (len >= i)ans += (len - i + 1)*dp[cur][nums[j]];
		}
		for (int i = 0; i < NN; ++i) {
			dp[tar][i + 1] += dp[tar][i];
		}

	}
	cout << ans << endl;
	return 0;
}