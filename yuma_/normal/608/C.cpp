//#include<stdio.h>
//#include <iostream>
//#include <math.h>
//#include <numeric>
//#include <vector>
//#include <map>
//#include <functional>
//#include <stdio.h>
//#include <array>
//#include <algorithm>
//#include <string>
//#include <string.h>
//#include <assert.h>
//#include <stdio.h>
//#include <queue>
//#include<iomanip>
//#include<bitset>
//#include<stack>
//#include<set>
//#include<limits>
//#include <complex>
//using namespace std;
//
//const int mod = 1000000007;
//struct Mod {
//public:
//	int num;
//	Mod() : num(0) { ; }
//	Mod(long long int n) : num((n % mod + mod) % mod) { ; }
//	Mod(int n) : num((n % mod + mod) % mod) { ; }
//	operator int() { return num; }
//};
//
//Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
//Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
//Mod operator++(Mod &a) { return a + Mod(1); }
//Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
//Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
//Mod operator--(Mod &a) { return a - Mod(1); }
//Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
//Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
//Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
//Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
//Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
//Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
//Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
//Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
//Mod operator^(const Mod a, const int n) {
//	if (n == 0) return Mod(1);
//	Mod res = (a * a) ^ (n / 2);
//	if (n % 2) res = res * a;
//	return res;
//}
//Mod inv(const Mod a) { return a ^ (mod - 2); }
//Mod operator/(const Mod a, const Mod b) {
//	assert(b.num != 0);
//	return a * inv(b);
//}
//Mod operator/(const long long int a, const Mod b) {
//	assert(b.num != 0);
//	return Mod(a) * inv(b);
//}
//Mod operator/=(Mod &a, const Mod b) {
//	assert(b.num != 0);
//	return a = a * inv(b);
//}
//
//#define MAX_N 1024000
//
//Mod fact[MAX_N], factinv[MAX_N];
//void init() {
//	fact[0] = Mod(1); factinv[0] = 1;
//	for (int i = 0; i < MAX_N - 1; ++i) {
//		fact[i + 1] = fact[i] * Mod(i + 1);
//		factinv[i + 1] = factinv[i] / Mod(i + 1);
//	}
//}
//Mod comb(const int a, const int b) {
//	return fact[a] * factinv[b] * factinv[a - b];
//}
//
//
//Mod getans(int m, int p) {
//	if (m == 0)return 1;
//	Mod bb(comb(p + m, m) - comb(p + m, m - 1));
//	return comb(p + m, m) - comb(p + m, m - 1);
//}
//
//
//int main() {
//	string a, b;
//	cin >> a >> b;
//	int ans = 0;
//	
//	int onum = 0;
//	int lnum = 0;
//	for (int i = 0; i < b.size(); ++i) {
//		if (b[i] == '1') {
//			lnum++;
//		}
//		else
//			onum++;
//	}
//	cout << ans << endl;
//	return 0;
//}

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


Mod getans(int m, int p) {
	if (m == 0)return 1;
	Mod bb(comb(p + m, m) - comb(p + m, m - 1));
	return comb(p + m, m) - comb(p + m, m - 1);
}
int dp[100010];

int main() {
	memset(dp, 0, sizeof(dp));
	int n; cin >> n;
	vector<int >places;
	vector<int>powers;
	vector<pair<int, int>>aa;
	for (int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		aa.push_back(make_pair(a, b));
	}
	sort(aa.begin(), aa.end(), [](const pair<int, int>l, const pair<int, int>r) {return l.first < r.first; });
	for (int i = 0; i < aa.size(); ++i) {
		places.push_back(aa[i].first);
		powers.push_back(aa[i].second);
	}
	dp[0] = 0;
	for (int i = 1; i <= n - 1; ++i) {

		auto it(lower_bound(places.begin(), places.begin() + i, places[i] - powers[i]));
		if (it == places.begin()) {

			dp[i] = i - (it - places.begin());


		}
		else {
			dp[i] = dp[it - places.begin() - 1] + i - (it - places.begin());

		}
	}

	int ans = n;
	for (int i = 0; i < n; ++i) {//
		ans = min(ans, i + dp[n - i - 1]);
	}
	cout << ans << endl;
	return 0;
}