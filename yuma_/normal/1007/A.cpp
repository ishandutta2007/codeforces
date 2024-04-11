#include "bits/stdc++.h"

#pragma warning(disable:4996)
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

template<typename T>
vector<vector<T>> keisann(const vector<vector<T>>l, const vector<vector<T>>r) {
	vector<vector<T>>ans(l.size(), vector<T>(r[0].size()));
	assert(l[0].size() == r.size());
	for (unsigned int h = 0; h < l.size(); ++h) {
		for (unsigned int i = 0; i < r.size(); ++i) {
			for (unsigned int w = 0; w < r[0].size(); ++w) {

				ans[h][w] += l[h][i] * r[i][w];
			}
		}
	}
	return ans;
}

template<typename T>
vector<vector<T>>powgyou(vector<vector<T>>a, const long long int n) {
	assert(a.size() == a[0].size());
	if (!n) {
		vector<vector<T>>e(a.size(), vector<T>(a[0].size()));
		for (unsigned int i = 0; i < a.size(); ++i) {
			e[i][i] = 1;
		}
		return e;
	}
	if (n == 1)return a;
	else {
		vector<vector<T>>ans(a.size(), vector<T>(a[0].size(), 0));
		ans = powgyou(a, n / 2);
		ans = keisann(ans, ans);
		if (n % 2) {
			ans = keisann(ans, a);
		}
		return ans;
	}
}

int main() {
	int N;cin>>N;
	map<int,int>mp;
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		mp[a]++;
	}
	vector<int>v;
	for (auto m : mp) {
		v.push_back(m.second);
	}
	reverse(v.begin(),v.end());
	int ans=0;
	if (v.size() == 1) {
		ans=0;
	}
	else {
		int num=0;
		num+=v[0];
		for (int i = 1; i < v.size(); ++i) {
			int use=min(num,v[i]);
			ans+=use;
			num-=use;
			num+=v[i];
		}

	}
	cout<<ans<<endl;
	return 0;
}