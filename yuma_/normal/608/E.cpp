#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
#include<limits>
#include <complex>
using namespace std;

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

#define MAX_N 1024000

Mod fact[MAX_N], factinv[MAX_N];
void init() {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < MAX_N - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}
//
//
//int move(string st, int& now, int way) {
//	if (now!=st.size()&&mp[st[now]] == way) {
//		now++;
//		return now;
//	}
//	else if (now != 0&& mp[st[now-1]] == (way + 2) % 4) {
//		now--;
//		return now;
//	}
//	return now;
//}

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

long long int hash_[1000011], pmo_[1000011];
long long int hash2_[1000011], pmo2_[1000011];

long long int rhash_[1000011], rpmo_[1000011];
long long int rhash2_[1000011], rpmo2_[1000011];

struct RollingHash {
	static const long long int mul0 = 10009, mul1 = 10007;
	static const long long int add0 = 1000010007, add1 = 1003333331;
	string s; int l;
	void init(string s) {
		this->s = s; l = s.size();
		hash_[0] = 0; pmo_[0] = 1;
		hash2_[0] = 0; pmo2_[0] = 1;
		for (int i = 0; i < l; ++i) {
			pmo_[i + 1] = pmo_[i] * mul0;
			pmo2_[i + 1] = pmo2_[i] * mul1;
		}
		for (int i = 0; i < l; ++i) {
			hash_[i + 1] = (hash_[i] * mul0 + s[i]);
			hash2_[i + 1] = (hash2_[i] * mul1 + s[i]);
		}
	}
	pair<long long int, long long int >  hash(int l, int r) { // s[l..r]
		return make_pair(hash_[r + 1] - hash_[l] * pmo_[r + 1 - l],
			hash2_[r + 1] - hash2_[l] * pmo2_[r + 1 - l]);

	}
};
struct RollingHash2 {
	static const long long int mul0 = 10009, mul1 = 10007;
	static const long long int add0 = 1000010007, add1 = 1003333331;
	string s; int l;
	void init(string s) {
		this->s = s; l = s.size();
		rhash_[0] = 0; rpmo_[0] = 1;
		rhash2_[0] = 0; rpmo2_[0] = 1;
		for (int i = 0; i < l; ++i) {
			rpmo_[i + 1] = rpmo_[i] * mul0;
			rpmo2_[i + 1] = rpmo2_[i] * mul1;
		}
		for (int i = 0; i < l; ++i) {
			rhash_[i + 1] = (rhash_[i] * mul0 + s[i]);
			rhash2_[i + 1] = (rhash2_[i] * mul1 + s[i]);
		}
	}
	pair<long long int, long long int >  hash(int l, int r) { // s[l..r]
		return make_pair(rhash_[r + 1] - rhash_[l] * rpmo_[r + 1 - l],
			rhash2_[r + 1] - rhash2_[l] * rpmo2_[r + 1 - l]);

	}
};
int main() {

	int N; cin >> N;
	string st[2];
	cin >> st[0] >> st[1];
	for (int i = 0; i < st[0].size(); ++i) {
		if (st[0][i] == 'W') {
			st[0][i] = 'E';
		}
		else if (st[0][i] == 'E') {
			st[0][i] = 'W';
		}
		else if (st[0][i] == 'S') {
			st[0][i] = 'N';
		}
		else {
			st[0][i] = 'S';
		}
	}

	//{
	//	int now = 0;
	//	for (int i = 0; i < N; ++i) {

	//		move(st[1], now, mp[st[0][i]]);
	//	}
	//	if (now == st[0].size()) {
	//		cout << "YES" << endl;
	//		return 0;
	//	}
	//	now = N - 1;
	//	for (int i = 0; i < N; ++i) {

	//		move(st[0], now, mp[st[1][i]]);
	//	}
	//	if (now == st[0].size()) {
	//		cout << "YES" << endl;
	//		return 0;
	//	}
	//}
	//{
	//	int now = 0;
	//	for (int i = 0; i < N; ++i) {

	//		move(st[0], now, mp[st[1][i]]);
	//	}
	//	if (now == st[1].size()) {
	//		cout << "YES" << endl;
	//		return 0;
	//	}
	//	now = N - 1;
	//	for (int i = 0; i < N; ++i) {

	//		move(st[1], now, mp[st[0][i]]);
	//	}
	//	if (now == st[1].size()) {
	//		cout << "YES" << endl;
	//		return 0;
	//	}
	//}
	//cout << "NO" << endl;
	RollingHash rh1;
	rh1.init(st[0]);

	reverse(st[1].begin(), st[1].end());
	RollingHash2 rh2;
	rh2.init(st[1]);
	
	bool ok = true;
	for (int i = 0; i <= N - 2; ++i) {
		if (rh1.hash(N - 2 - i, N - 2) == rh2.hash(0, i)){
		//if (rh1.hash(N - 2 - i, N - 2) == rh2.hash(N - 2 - i, N - 2)) {
			ok = false;
		}
	}
	if (ok)cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}

/*
5
RRRRN
RWSSL

*/