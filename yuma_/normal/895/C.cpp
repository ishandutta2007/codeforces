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

#define MAX_MOD_N 102400

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
vector<int>primes;
void hurui(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>(amax + 1, true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2 * i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}
map<long long int, int>soinnsuu(long long int a) {
	hurui(1e4);
	map<long long int, int>ans;
	for (auto km : primes) {
		int i = km;
		if (i> a)break;
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}
int main() {  
	init();
	vector<int>v{ 2,3,5,7,11,13,17,19,23,29,31 };
	//v = { 2,3,5,7,11 };
	int N;cin>>N;
	map<int,int>mp,somp;
	for (int i = 0; i < N; ++i) {
		int a;cin>>a;
		vector<int>av{37,41,43,47,53,59,61,67 };
		if (find(av.begin(), av.end(), a) != av.end()) {
			somp[a]++;
		}
		else {
			mp[a]++;
		}
		
	}
	vector<vector<Mod>>dp(mp.size()+1,vector<Mod>(1<<(v.size())));
	dp[0][0]=1;
	int id=0;
	for (auto m : mp) {
		for (int now = 0; now < (1 << v.size()); ++now) {
			bitset<18>nowbs(now);
			auto so(soinnsuu(m.first));
			bitset<18>xorbs;
			for (auto s : so) {
				if (s.second % 2) {
					xorbs[find(v.begin(), v.end(), s.first) - v.begin()].flip();
				}
			}
			dp[id+1][nowbs.to_ulong()]+=dp[id][nowbs.to_ulong()]*mod_pow(2,m.second-1);
			dp[id + 1][(nowbs^xorbs).to_ulong()] += dp[id][nowbs.to_ulong()] * mod_pow(2, m.second - 1);
		}
		id++;
	}
	Mod ans=dp[mp.size()][0];
	for (auto sm : somp) {
		ans*=mod_pow(2,sm.second-1);
	}
	cout<<ans-Mod(1)<<endl;
	return 0;
}