#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;



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

//mod extend euclid 
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

#define MAX_MOD_N 1054000

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

Mod ar(const pair<int, int>a,
	const pair<int, int>b,
	const pair<int, int>c) {
	int x1=b.first-a.first;
	int x2=c.first-a.first;
	int y1=b.second-a.second;
	int y2=c.second-a.second;

	return 
		(x1*y2-x2*y1);
}

int main() {
	int N;cin>>N;
	vector<vector<int>>dp(N,vector<int>(5,-1));
	int pre_p;
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		a--;
		if (i == 0) {
			for (int j = 0; j < 5; ++j) {
				dp[i][j]=0;
			}
		}
		else {
			for (int pre = 0; pre < 5; ++pre) {
				if (dp[i - 1][pre] != -1) {
					for (int nex = 0; nex < 5; ++nex) {
						if (pre_p < a) {
							if (pre < nex) {
								dp[i][nex]=pre;
							}
						}
						else if (pre_p == a) {
							if (pre != nex) {
								dp[i][nex]=pre;
							}
						}
						else {
							if (pre > nex) {
								dp[i][nex]=pre;
							}
						}
					}
				}
			}
		}
		pre_p=a;
	}
	vector<int>anss;
	for (int i = 0; i < 5; ++i) {
		if (dp[N - 1][i] != -1) {
			int finger=i;
			for (int j = N - 1; j >= 0; --j) {
				anss.push_back(finger);
				if (j) {
					finger=dp[j][finger];
				}
			}
			reverse(anss.begin(),anss.end());

			break;
		}
	}
	if(anss.empty())cout<<-1<<endl;
	else {
		for (int i = 0; i < anss.size(); ++i) {
			cout<<anss[i]+1;
			if(i==anss.size()-1)cout<<endl;
			else cout<<" ";
		}
	}
	return 0;
}